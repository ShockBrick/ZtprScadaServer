#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H
#include <iostream>
#include <senddata.h>
#include <math.h>

class signalGenerator
{
    std::vector <SendData<double>> vSend;/**< \brief Wektor danych, w którym zapisuje się dane wysyłane z serwera. Wektor ten jest w tej klasie definiowany.*/
    int sizeOfVector=5;/**< \brief Żądana wielkość wektor vSend.*/
public:
    /** \brief Konstruktor tworzy pierwszy wysyłany wektor danych.
     */
    signalGenerator();
    /** \brief Funkcja tworzy następne wektory danych.
     */
    void updateTheSignal();
    /** \brief Funkcja wyświetla w konsoli wektor danych.
     */
    void printSignal();
    /** \brief Funkcja zwraca wektor vSend.
     */
    std::vector <SendData<double>> getVector();
};

#endif // SIGNALGENERATOR_H
