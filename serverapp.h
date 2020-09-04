#ifndef SERVERAPP_H
#define SERVERAPP_H
#include <vector>
#include <senddata.h>
#include <servergui.h>
#include <serverservice.h>



/** Klasa tworzy główną aplikacją, steruje pozostałymi klasami serwera.**/
class ServerApp
{
    ServerGui guiS;/**< \brief Obiekt typu ServerGui, służy do wyświetlania informacji o serwerze.*/
    //    parameteres of network
    std::string ipAddress;/**< \brief Zmienna przechowująca adress Ip serwer.*/
    std::string portNumber;/**< \brief Zmienna przechowująca numer portu serwera.*/
    // variables for gui
   // std::string statusLabel;/**< \brief Zmienna przechowująca numer portu serwer.*/

    ServerService serviceS;/**< \brief Obiekt typu ServerService, zarządza całą strukturą sieciową serwera.*/
    std::vector <SendData<double>> vSend;/**< \brief Wektor danych, w którym zapisuje się dane wysyłane z serwera.*/
public:
    /** \brief Konstruktor uruchamia interfejs graficzny i wyświetla dane z obiektu serviceS.
     *
     *
     *
     */
    ServerApp();
};

#endif // SERVERAPP_H


