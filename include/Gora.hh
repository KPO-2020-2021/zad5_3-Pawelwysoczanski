#ifndef GORA_HH
#define GORA_HH

#include "BrylaGeometryczna.hh"

/*!
*\file
*\brief Definicja klasy Gora.
*/

/*!
*\brief Klasa Gora.
*Klasa definiuje pojecie Gory.
*Klasa dziedziczy po klasie rodzica BrylaGeometryczna.
*/
class Gora : public BrylaGeometryczna
{

public:
    /*!
*\brief Konstruktor parametryczny klasy Gora.
*/
    Gora(Vector3D SrodekBryly = Vector3D(), double x = 50, double y = 50, double z = 50, std::string NazwaPliku = "../dat/Gora.dat");
    /*!
*\brief Tworzy kopie elementu klasy Gora.
*/
    Gora(Gora &pr);

    /*!
*\brief Operator przypisania dal klasy Gora.
*/
    Gora &operator=(const Gora &other)
    {
        wymiaryBryly = other.wymiaryBryly;
        WierzBryly = other.WierzBryly;
        SrodekBryly = other.SrodekBryly;
        NazwaPliku = other.NazwaPliku;
        return *this;
    }

    double promien() { return (*wymiaryBryly)[2]; }
};

#endif