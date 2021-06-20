#ifndef GRAN_HH
#define GRAN_HH

#include "BrylaGeometryczna.hh"
/*!
*\file
*\brief Definicja klasy Gran.
*/

/*!
*\brief Klasa Gran.
*Klasa definiuje pojecie Grani.
*Klasa dziedziczy po klasie rodzica BrylaGeometryczna.
*/
class Gran : public BrylaGeometryczna
{

public:
    /*!
*\brief Konstruktor parametryczny klasy Gran.
*/
    Gran(Vector3D SrodekBryly = Vector3D(), double x = 50, double y = 50, double z = 50, std::string NazwaPliku = "../dat/Gran.dat");
    /*!
*\brief Tworzy kopie elementu klasy Gran.
*/
    Gran(Gran &pr);
        /*!
*\brief Operator przypisania dal klasy Gran.
*/
    Gran &operator=(const Gran &other)
    {
        wymiaryBryly = other.wymiaryBryly;
        WierzBryly = other.WierzBryly;
        SrodekBryly = other.SrodekBryly;
        NazwaPliku = other.NazwaPliku;
        return *this;
    }
};

#endif