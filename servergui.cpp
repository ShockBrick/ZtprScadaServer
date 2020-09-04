#include "servergui.h"
#include <QGridLayout>
#include <QGroupBox>
#include <QGuiApplication>
#include <QGuiApplication>
#include <QPushButton>
#include <iostream>
#include <QStyleHints>
ServerGui::ServerGui(QWidget *parent) : QDialog(parent)
  ,startInformationLabel(new QLabel)
{

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
   startInformationLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);


    //! [2]
    auto quitButton = new QPushButton(tr("Quit"));
    quitButton->setAutoDefault(false);
    connect(quitButton, &QAbstractButton::clicked, this, &QWidget::close);
    //! [3]


    auto buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);
    buttonLayout->addStretch(1);

    QVBoxLayout *mainLayout = nullptr;
    if (QGuiApplication::styleHints()->showIsFullScreen() || QGuiApplication::styleHints()->showIsMaximized()) {
        auto outerVerticalLayout = new QVBoxLayout(this);
        outerVerticalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding));
        auto outerHorizontalLayout = new QHBoxLayout;
        outerHorizontalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Ignored));
        auto groupBox = new QGroupBox(QGuiApplication::applicationDisplayName());
        mainLayout = new QVBoxLayout(groupBox);
        outerHorizontalLayout->addWidget(groupBox);
        outerHorizontalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Ignored));
        outerVerticalLayout->addLayout(outerHorizontalLayout);
        outerVerticalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding));
    } else {
        mainLayout = new QVBoxLayout(this);
    }

    mainLayout->addWidget(startInformationLabel);
    mainLayout->addLayout(buttonLayout);

    setWindowTitle(QGuiApplication::applicationDisplayName());
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



    startInformationLabel->setText(tr("%1\nAdres Ip serwera:\n %2\nPort serwera:  %3\n\n")
                          .arg(QString::fromStdString(statusLabelMessage)).arg(QString::fromStdString(ipAddressMessage)).arg(QString::fromStdString(portNumberMessage)));




}






