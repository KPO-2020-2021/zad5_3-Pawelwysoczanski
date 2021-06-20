#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

#include "BrylaGeometryczna.hh"
/*!
*\file
*\brief Definicja klasy Graniastoslup.
*/

/*!
*\brief Klasa Graniastoslup.
*Klasa definiuje pojecie Graniastoslupa.
*Klasa dziedziczy po klasie rodzica BrylaGeometryczna.
*/
class Graniastoslup : public BrylaGeometryczna
{
public:
    /*!
*\brief Konstruktor parametryczny klasy Graniastoslup
*/
    Graniastoslup(Vector3D srodek=Vector3D(),double z=10,double promien=25,std::string nazwa = "../datasets/garniastoslup6.dat" );
   
};

#endif
