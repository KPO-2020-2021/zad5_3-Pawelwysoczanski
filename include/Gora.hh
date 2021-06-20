#ifndef GORA_HH
#define GORA_HH

#include "BrylaGeometryczna.hh"

class Gora : public BrylaGeometryczna
{

public:
  double promien() { return (*wymiary)[2]; }

  Gora(Vector3D srodek = Vector3D(), double x = 50, double y = 50, double z = 50, std::string nazwa = "../datasets/Gora.dat");

  Gora(Gora &pr);

  Gora &operator=(const Gora &other)
  {
    wymiary = other.wymiary;
    wierz = other.wierz;
    srodek = other.srodek;
    nazwa = other.nazwa;
    return *this;
  }
};

#endif