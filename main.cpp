#include <QCoreApplication>
#include <serverapp.h>
#include <servergui.h>
#include <serverservice.h>
#include <senddata.h>
#include <signalgenerator.h>
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ServerApp ServerApplication;
    return app.exec();
}



