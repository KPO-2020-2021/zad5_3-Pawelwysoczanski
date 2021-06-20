#ifndef OBIEKTYSCENY_HH
#define OBIEKTYSCENY_HH
#include <string>
#include <memory>
#include "Wektor3D.hh"

class ObiektySceny
{

public:
    virtual bool czy_kolizja(shared_ptr<ObiektySceny> Obiekt) = 0;
    virtual std::string getNazwa() const = 0;
    virtual void zapisz() = 0;
    virtual Vector3D getSrodekBtyly() const = 0;
    virtual double promien() = 0;
};

#endif
