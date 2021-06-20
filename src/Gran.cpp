#include "Gran.hh"
/*!
*\brief Konstruktor parametryczny klasy Gran.
*/
Gran::Gran(Vector3D SrodekBryly, double x, double y, double z, std::string NazwaPliku)
{
  double tab[] = {x, y, z};
  wymiaryBryly = std::make_shared<Vector3D>(tab);
  this->NazwaPliku = NazwaPliku;
  this->SrodekBryly = SrodekBryly;

  Vector3D punkt;

  punkt[0] = SrodekBryly[0] - (x / 2);
  punkt[1] = SrodekBryly[1] + (y / 2);
  punkt[2] = SrodekBryly[2] - (z / 2);
  WierzBryly.push_back(punkt);

  punkt[0] = SrodekBryly[0] - (x / 2);
  punkt[1] = SrodekBryly[1] + (y / 2);
  punkt[2] = SrodekBryly[2] - (z / 2);
  WierzBryly.push_back(punkt);

  punkt[0] = SrodekBryly[0] + (x / 2);
  punkt[1] = SrodekBryly[1] + (y / 2);
  punkt[2] = SrodekBryly[2] - (z / 2);
  WierzBryly.push_back(punkt);

  punkt[0] = SrodekBryly[0] + (x / 2);
  punkt[1] = SrodekBryly[1] + (y / 2);
  punkt[2] = SrodekBryly[2] - (z / 2);
  WierzBryly.push_back(punkt);

  punkt[0] = SrodekBryly[0] + (x / 2);
  punkt[1] = SrodekBryly[1] - (y / 2);
  punkt[2] = SrodekBryly[2] + (z / 2);
  WierzBryly.push_back(punkt);

  punkt[0] = SrodekBryly[0] + (x / 2);
  punkt[1] = SrodekBryly[1] - (y / 2);
  punkt[2] = SrodekBryly[2] - (z / 2);
  WierzBryly.push_back(punkt);

  punkt[0] = SrodekBryly[0] - (x / 2);
  punkt[1] = SrodekBryly[1] - (y / 2);
  punkt[2] = SrodekBryly[2] + (z / 2);
  WierzBryly.push_back(punkt);

  punkt[0] = SrodekBryly[0] - (x / 2);
  punkt[1] = SrodekBryly[1] - (y / 2);
  punkt[2] = SrodekBryly[2] - (z / 2);
  WierzBryly.push_back(punkt);

  this->SrodekBryly[0] = SrodekBryly[0];
  this->SrodekBryly[1] = SrodekBryly[1];
  this->SrodekBryly[2] = SrodekBryly[2] - (z / 2);
}
/*!
*\brief Tworzy kopie elementu klasy Gran.
*/
Gran::Gran(Gran &pr)
{
  wymiaryBryly = pr.wymiaryBryly;
  WierzBryly = pr.WierzBryly;
  SrodekBryly = pr.SrodekBryly;
  NazwaPliku = pr.NazwaPliku;
}
