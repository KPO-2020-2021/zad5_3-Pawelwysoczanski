#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include <fstream>
#include <vector>

class Plaszczyzna
{
protected:
    std::vector<Vector3D> wierz;
    std::string nazwa;
   int licz_prostych;
public:
    Plaszczyzna(Vector3D wymiary=Vector3D(),int gestosc_siatki=10, std::string nazwa="../datasets/plaszczyzna");

    Vector3D &operator[](int index);
    Vector3D operator[](int index) const;

    void set_nazwa(std::string nazwa);
    std::string get_nazwa() const;

    void zapisz();
};

#endif