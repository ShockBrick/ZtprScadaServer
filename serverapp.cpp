#include "serverapp.h"

ServerApp::ServerApp()
{
    SendData<double> a = SendData<double>(1,1);
    SendData<double> b = SendData<double>(1,1);
    SendData<double> c = SendData<double>(2,3);
    //SendData<int> a = SendData<int>(1,1);
    //SendData<int> b = SendData<int>(1,1);
vSend.push_back(a);
vSend.push_back(b);
vSend.push_back(c);
serviceS.changeVector(vSend);
guiS.startInformation(serviceS);

}
