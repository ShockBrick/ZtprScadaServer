#include <QCoreApplication>
#include <serverapp.h>
#include <servergui.h>
#include <serverservice.h>
#include <senddata.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ServerApp ServerApplication;

    return a.exec();
}



