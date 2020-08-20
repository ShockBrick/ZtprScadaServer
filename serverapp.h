#ifndef SERVERAPP_H
#define SERVERAPP_H
#include <vector>
#include <senddata.h>
#include <servergui.h>
#include <serverservice.h>

class ServerApp
{

    ServerGui guiS;
    //parameteres of network
    std::string ipAddress;
    std::string portNumber;
    // variables for gui
    std::string statusLabel;


    ServerService serviceS;
    std::vector <SendData<double>> vSend;//    std::vector <SendData<int>> vSend;
public:
    ServerApp();
};

#endif // SERVERAPP_H


