#include "servergui.h"
#include <iostream>
ServerGui::ServerGui()
{

}

void ServerGui::printIPMessage()
{
     std::cout<<"Adres Ip serwera: "+ ipAddressMessage+"\n";
}

void ServerGui::printPortMessage()
{
    std::cout<<"Port serwera: "+ portNumberMessage+"\n";
}

void ServerGui::printStatusLabelMessage()
{
    std::cout<<statusLabelMessage+"\n";
}

void ServerGui::printHelpStringMessage()
{
    std::cout<<helpStringMessage+"\n";
}

void ServerGui::printMessage(std::string Message)
{
    std::cout<<Message+"\n";
}




void ServerGui::setIPMessage(std::string ipAddress)
{
    ipAddressMessage=ipAddress;
}

void ServerGui::setPortNumberMessage(std::string portNumber)
{
    portNumberMessage=portNumber;
}

void ServerGui::setStatusLabelMessage(std::string statusLabel)
{
    statusLabelMessage=statusLabel;
}

void ServerGui::setHelpStringMessage(std::string helpString)
{
    helpStringMessage=helpString;
}

void ServerGui::startInformation(ServerService serviceS)
{
    setIPMessage (serviceS.getIpAddress());
    setPortNumberMessage (serviceS.getPortNumber());
    setStatusLabelMessage(serviceS.getStatusLabel());
    printMessage ("start\n");
    printStatusLabelMessage();
    printIPMessage ();
    printPortMessage ();
    printMessage ("koniec\n");
}




