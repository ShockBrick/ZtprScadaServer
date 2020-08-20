#ifndef SERVERGUI_H
#define SERVERGUI_H

#include <iostream>
#include<serverservice.h>
class ServerGui
{
    std::string ipAddressMessage={};
    std::string portNumberMessage={};
    std::string statusLabelMessage={};
    std::string helpStringMessage={};
public:

    ServerGui();
    void printMessage (std::string Message);
    void printIPMessage ();
    void printPortMessage ();
    void printStatusLabelMessage ();
    void printHelpStringMessage ();

    void setIPMessage (std::string ipAddress);
    void setPortNumberMessage (std::string portNumber);
    void setStatusLabelMessage (std::string statusLabel);
    void setHelpStringMessage (std::string helpString);

    void startInformation(ServerService serviceS);

};

#endif // SERVERGUI_H
