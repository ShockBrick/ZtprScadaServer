#include "signalgenerator.h"

signalGenerator::signalGenerator()
{
    double pi{3.14};
    for(int i=0;i<sizeOfVector;i++)
    {
        double angle=i*pi/180;
        SendData<double> a = SendData<double>(sin(angle),i);
        vSend.push_back(a);
    }
}

void signalGenerator::updateTheSignal()
{
    double pi{3.14};
    double lastTime = vSend[sizeOfVector-1].getTimeStamp();
    vSend.clear();

    for(int i=1;i<=sizeOfVector;i++)
    {
        double angle=(i+lastTime)*pi/180;
        SendData<double> a = SendData<double>(sin(angle),i+lastTime);
        vSend.push_back(a);
    }

}

void signalGenerator::printSignal()
{
    for(auto signal:vSend)
    {
        std::cout<<"Wartosc: "<<signal.getValue()<<"        "<<"Czas: "<<signal.getTimeStamp()<<std::endl;
    }
}

std::vector<SendData<double> > signalGenerator::getVector()
{
    return vSend;
}


