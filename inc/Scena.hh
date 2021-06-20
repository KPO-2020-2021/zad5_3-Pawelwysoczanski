#ifndef SCENA_HH
#define SCENA_HH
#include <iostream>
#include <iomanip>
#include <memory>
#include <fstream>
#include <list>
#include "Plaskowyz.hh"
#include "Gran.hh"
#include "Gora.hh"
#include "Graniastoslup.hh"
#include "lacze_do_gnuplota.hh"
#include "Dron.hh"
#include "Plaszczyzna.hh"
#include "ObiektySceny.hh"

#define N 2

/*!
*\file
*\brief Definicja klasy Scena.
*/

/*!
*\brief Klasa Scena
*Klasa definiuje pojecie Sceny.
*W klasie sceny definiujemy ilosc dronow znajdujacych sie na scenie oraz wyglad plaszczyzny.
*Sluzy rowniez do wykonywania operacji przelotu drona jak i wyboru odpowiedzniego.
*/

class Scena
{
    /*!
    *\brief Lacze umozliwajace rysowanie w programie GNUPlot.
    */
    PzG::LaczeDoGNUPlota Lacze;
    /*!
    *\brief Wskaznik na tablice dronow ktorymi pozna poruszac.
    */
    std::list<std::shared_ptr<Dron>> TabDronow;
    /*!
    *\brief Wskaznik na PLaszczyzne umozliwiajacy jej wykorzystanie w scenie.
    */
    Plaszczyzna *dno;
    /*!
    *\brief Zmienna pozwalajaca na przechowanie numeru obecnie uzywanego drona.
    */
    int nrDrona;
    /*!
*\brief  Lista dronow znajdujaca sie na scenie.
*/
    std::list<std::shared_ptr<Dron>>::const_iterator Drona;
    /*!
*\brief Lista elementow znajdujaca sie na scenie 
*/
    std::list<std::shared_ptr<ObiektySceny>> ListaElemt;

    /*!
*\brief  Ilosc elementow znajdujaca sie na scenie.
*/
    int nrElem;

public:
    /*!
    *\brief Konstruktor bezparametryczny klasy Scena.
    */
    Scena();
    /*!
    *\brief Metoda ktora rysuje scene.
    */
    void Rysuj();
    /*!
    *\brief Metoda ktora sluzy do wybierania opcji programu.
    */
    bool Interfejs(char opcja);
    /*!
    *\brief Destruktor klasy Scena.
    */
    ~Scena();
};

#endif
