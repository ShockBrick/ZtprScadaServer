#ifndef SERVERGUI_H
#define SERVERGUI_H

#include <QLabel>
#include <QMainWindow>
#include <QObject>
#include <QDialog>

#include <iostream>
#include<serverservice.h>


QT_BEGIN_NAMESPACE
class QLabel;
class QTcpServer;
class QNetworkSession;
QT_END_NAMESPACE


/** Klasa tworzy interfejs graficzny służący do wyswietlenia informacji o serwerze.**/
class ServerGui: public QDialog
{
    Q_OBJECT

    std::string ipAddressMessage={};/**< \brief Zmienna zawierająca Ip Serwera.*/
    std::string portNumberMessage={};/**< \brief Zmienna zawierająca numer portu serwera.*/
    std::string statusLabelMessage={};/**< \brief Zmienna zawierająca informacje o stanie serwera.*/
    std::string helpStringMessage={};/**< \brief Zmienna pomocnicza.*/

    QLabel *startInformationLabel = nullptr;/**< \brief Obiekt typu QLabel, zawiera informacje wyświetlane o serwerze.*/
public:

    /** \brief Konstruktor tworzączy całą grafikę interfejsu.
     *
     *
     */
    explicit  ServerGui(QWidget *parent = nullptr);
    /** \brief Funkcja podstawia pod zmienną ipAddressMessage argument funkcji.
     *
     *
     */
    void setIPMessage (std::string ipAddress);
    /** \brief Funkcja podstawia pod zmienną portNumberMessage argument funkcji.
     *
     *
     */
    void setPortNumberMessage (std::string portNumber);
    /** \brief Funkcja podstawia pod zmienną statusLabelMessage argument funkcji.
     *
     *
     */
    void setStatusLabelMessage (std::string statusLabel);
    /** \brief Funkcja podstawia pod zmienną helpStringMessage argument funkcji.
     *
     *
     */
    void setHelpStringMessage (std::string helpString);
    /** \brief Funkcja służy do wyświetlenia informacji o serwerze podanym jako argument funkcji.
     *
     * @param serviceS Jest to obiekt klasy ServerService z którego pobierane są informacje i są wyświetlane na ekranie.
     *
     */
    void startInformation(ServerService serviceS);

};

#endif // SERVERGUI_H
