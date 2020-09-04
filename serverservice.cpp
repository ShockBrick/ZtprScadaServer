#include "serverservice.h"


#include <QtNetwork>
#include <QtCore>

#include <iostream>

ServerService::ServerService()
{
   // std::cout<<"ServerService stratuje \n";
  QNetworkConfigurationManager manager;
  if(manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)//sprawdza czy już jest utworzone połączenie sieciowe (16 & 64)
  {
      //Get saved network configuration - Uzyskaj zapisaną konfigurację sieci
      QSettings settings(QSettings::UserScope,QLatin1String("QtProject"));  // ustawienia(zapisywane dla mnie, a nie dla całego kompa, nazwa obiektu QObject który przechowuje  ustawienia)
      settings.beginGroup(QLatin1String("QtNetwork"));//otwieranie grupy
      const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString(); //Returns the value for setting key. If the setting doesn't exist, returns defaultValue.
      settings.endGroup();

      //If the saved network configuration is not curently discovered use the system defaulty

      QNetworkConfiguration config = manager.configurationFromIdentifier(id); //Returns the QNetworkConfiguration for identifier; otherwise returns an invalid QNetworkConfiguration.

        if ((config.state() & QNetworkConfiguration::Discovered) !=QNetworkConfiguration::Discovered){
            config=manager.defaultConfiguration();
            //The Discovered state implies that the configuration is Defined and the outside conditions are such that the configuration can be used immediately to open a new network session.
            //Stan Discovered oznacza, że konfiguracja jest zdefiniowana, a warunki zewnętrzne są takie, że konfiguracja może być natychmiast wykorzystana do otwarcia nowej sesji sieciowej.
        }
        networkSession = new QNetworkSession(config,this);
        connect(networkSession, &QNetworkSession::opened, this, &ServerService::sessionOpened);

        statusLabel = "Opening network session.";
        networkSession->open();
  }
  else
  {
      sessionOpened();
  }
  //    !!!!!!!!!!!!!!!!!!!!!!!!!
 //    !!!!!!!!!!!!!!!!!!!!!!!!!
  connect(tcpServer, &QTcpServer::newConnection, this, &ServerService::sendDataVector);
  //    !!!!!!!!!!!!!!!!!!!!!!!!!
}


void ServerService::sessionOpened()
{
    //std::cout<<"Jestem w sessionOpened\n";
    // Save the used configuration
    if (networkSession) {
        QNetworkConfiguration config = networkSession->configuration();
        QString id;
        if (config.type() == QNetworkConfiguration::UserChoice)
            id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
        else
            id = config.identifier();

        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
        settings.endGroup();
    }

    tcpServer = new QTcpServer(this);
    if(!tcpServer->listen()){
        std::string utf8_text = tcpServer->errorString().toUtf8().constData();
        statusLabel= "Unable to start the server: " + utf8_text;
        return;
    }

    QString ipAddressQ;
    QList<QHostAddress> ipAddressesListQ = QNetworkInterface::allAddresses();


    // use the first non-localhost IPv6 address
    for (int i = 0; i < ipAddressesListQ.size(); ++i) {
        if (ipAddressesListQ.at(i) != QHostAddress::LocalHost &&
            ipAddressesListQ.at(i).toIPv4Address()) {
            ipAddressQ = ipAddressesListQ.at(i).toString();
            ipAddress=ipAddressQ.toUtf8().constData();//zmienna globalna string
            break;
        }
    }
    // if we did not find one, use IPv6 localhost
    if (ipAddressQ.isEmpty())
        ipAddressQ = QHostAddress(QHostAddress::LocalHost).toString();

    QString portNumberQT = QString::number(tcpServer->serverPort());//zamiana quint16 do qstring
    portNumber=portNumberQT.toUtf8().constData();//zamiana qstring do stringa
    statusLabel= "The server started up correctly";
  //  statusLabel="The server is running on\n "+ ipAddress + "\n  "+ portNumber;
}

void ServerService::sendDataVector()
{

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_5_10);
    //std::cout<<"Jestem przed <<vSend \n";
  vSend = sG.getVector();
//    std::cout<<"vSend size:  "<<vSend.size()<<std::endl;
    sG.updateTheSignal();
//    std::cout<<"vSend size:  "<<vSend.size()<<std::endl;
    for (auto pojemnik:vSend)
    {
        std::cout<<"Wartosc: "<<pojemnik.getValue()<<"     "<<"Czas: "<<pojemnik.getTimeStamp()<<std::endl;
    }
    out << vSend;

//std::cout<<"Jestem po \n";
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, &QAbstractSocket::disconnected,
            clientConnection, &QObject::deleteLater);

    clientConnection->write(block);
    clientConnection->disconnectFromHost();
}

void ServerService::changeVector(std::vector<SendData<double> > changeSendVector)//void ServerService::changeVector(std::vector<SendData<int> > changeSendVector)
{
    for(auto& singleVal : changeSendVector)
    {
        vSend.push_back(singleVal);
    }
}

//konstruktor kopiujący
ServerService::ServerService(ServerService &SSS)
{
    ipAddress=SSS.ipAddress;
    portNumber=SSS.portNumber;
    statusLabel=SSS.statusLabel;
   tcpServer =SSS.tcpServer;
    networkSession =SSS.networkSession;
    vSend=SSS.vSend;
}


std::string ServerService::getStatusLabel()
{
    return statusLabel;
}

std::string ServerService::getIpAddress()
{
    return ipAddress;
}

std::string ServerService::getPortNumber()
{
    return portNumber;
}
