#ifndef SERVERSERVICE_H
#define SERVERSERVICE_H

#include <QDataStream>
#include <QObject>
#include <QtNetwork>
#include <string>
#include <senddata.h>
#include <vector>
QT_BEGIN_NAMESPACE
class QTcpServer;
class QNetworkSession;
QT_END_NAMESPACE


class ServerService: public QObject
{
    Q_OBJECT

public:

    ServerService();

    // konstruktor kopiujący - - Qobject is not taken into account
    ServerService(ServerService & SSS);

    void changeVector (std::vector <SendData<double>> changeSendVector);/* void changeVector (std::vector <SendData<int>> changeSendVector);*///function saves vector changeSendVector to vector vSend

    std::string getStatusLabel();
    std::string getIpAddress();
    std::string getPortNumber();

private slots:
    void sessionOpened();
    void sendDataVector();

private:
    QTcpServer *tcpServer = nullptr;
    QNetworkSession *networkSession = nullptr;
    //parameteres of network
    std::string ipAddress;
    std::string portNumber;
    // variables for gui
    std::string statusLabel;
    //data to send
std::vector <SendData<double>> vSend;//    std::vector <SendData<int>> vSend;
};

#endif // SERVERSERVICE_H
