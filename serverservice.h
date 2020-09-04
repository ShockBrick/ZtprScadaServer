#ifndef SERVERSERVICE_H
#define SERVERSERVICE_H

#include <QDataStream>
#include <QObject>
#include <QtNetwork>
#include <string>
#include <senddata.h>
#include <vector>
#include <signalgenerator.h>
QT_BEGIN_NAMESPACE
class QTcpServer;
class QNetworkSession;
QT_END_NAMESPACE

/** Klasa tworzy serwer sieciowy.**/
class ServerService: public QObject
{
    Q_OBJECT

public:
    /** \brief Konstruktor tworzy konfiguracje sieci.
     *
     *
     */
    ServerService();
    // konstruktor kopiujący - - Qobject is not taken into account
    /** \brief Konstruktor kopiujący.
     *
     *
     */
    ServerService(ServerService & SSS);
    /** \brief Funkcja przepisująca wektor znajdujący się w argumencie funkcji do wektora vSend.
     */
    void changeVector (std::vector <SendData<double>> changeSendVector);//function saves vector changeSendVector to vector vSend
    /** \brief Funkcja zwraca wartość zmiennej statusLabel.
     */
    std::string getStatusLabel();
    /** \brief Funkcja zwraca wartość zmiennej ipAddress.
     */
    std::string getIpAddress();
    /** \brief Funkcja zwraca wartość zmiennej portNumber.
     */
    std::string getPortNumber();

private slots:
    /** \brief Funkcja otwiera połączenie sieciowe.
     */
    void sessionOpened();
    /** \brief Funkcja wysyła do klienta wektor danych.
     */
    void sendDataVector();

private:
    QTcpServer *tcpServer = nullptr;/**< \brief Obiekt typu QTcpSocket, tworzy gniazdo TCP.*/
    QNetworkSession *networkSession = nullptr;/**< \brief Obiekt typu  QNetworkSession.*/
    //parameteres of network
    std::string ipAddress;/**< \brief Zmienna zawierająca IP serwer.*/
    std::string portNumber;/**< \brief Zmienna zawierająca numer portu serwera.*/
    // variables for gui
    std::string statusLabel;/**< \brief Zmienna zawierająca status serwera.*/
    //data to send
    std::vector <SendData<double>> vSend;  /**< \brief Wektor danych, w którym zapisuje się dane wysyłane z serwera.*/
    signalGenerator sG;/**< \brief Obiekt typu signalGenerator, tworzy generator sygnału.*/
};

#endif // SERVERSERVICE_H
