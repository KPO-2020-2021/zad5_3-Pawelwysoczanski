#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "BrylaGeometryczna.hh"

class Prostopadloscian : public BrylaGeometryczna
{

public:
    Prostopadloscian(Vector3D srodek = Vector3D(), double x = 50, double y = 50, double z = 50, std::string nazwa = "../datasets/prostopadloscian.dat");

    Prostopadloscian(Prostopadloscian &pr);

    Prostopadloscian &operator=(const Prostopadloscian &other)
    {
        wymiary = other.wymiary;
        wierz = other.wierz;
        srodek = other.srodek;
        nazwa = other.nazwa;
        return *this;
    }
};

#endif