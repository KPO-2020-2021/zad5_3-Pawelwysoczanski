#ifndef BRYLAGEOMETRYCZNA_HH
#define BRYLAGEOMETRYCZNA_HH

#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include <fstream>
#include <vector>
#include <memory>
#include "ObiektySceny.hh"
/*!
*\file
*\brief Definicja klasy BrylaGeometryczna.
*/

/*!
*\brief Klasa BrylaGeometryczna
*Klasa definiuje pojecie bryly geometryacznej.
*Klasa jest rodzicem dla klas dziedzicznych Prostopadloscian i Graniastoslup.
*/
class BrylaGeometryczna : public ObiektySceny, public std::enable_shared_from_this<BrylaGeometryczna>
{
protected:
  /*!
 *\brief Wymiary Bryly.
 *Wskaznik na wektor przechowujacy wymiary bryly.
 */
  std::shared_ptr<Vector3D> wymiaryBryly;
  /*!
 *\brief Wierzcholki bryly.
 *Pojemnik typu Vector3D przechowujacy wiercholki bryly.
 */
  std::vector<Vector3D> WierzBryly;
  /*!
 *\brief Srodek bryly.
 *Przechowuje wektor polozenia srodka bryly.
 */
  Vector3D SrodekBryly;
  /*!
 *\brief Nazwa pliku.
 *Przechowuje nazwe pliku zapisu bryly.
 */
  std::string NazwaPliku;

public:
  /*!
 *\brief Operator zabezpieczajacy wyjscia poza zadana skale
 */
  Vector3D &operator[](int index)
  {
    return WierzBryly[index];
  }
  /*!
 *\brief 
 */
  Vector3D operator[](int index) const
  {
    return WierzBryly[index];
  }
  /*!
 *\brief Metoda ktora ustawia srodek bryly.
 */
  void SetSrodekBryly(Vector3D SrodekBryly)
  {
    this->SrodekBryly = SrodekBryly;
  }
  /*!
 *\brief Metoda ktora ustawia nazwe pliku zapisu bryly.
 */
  void SetNazwaPliku(std::string NazwaPliku)
  {
    this->NazwaPliku = NazwaPliku;
  }
  /*!
 *\brief Metoda ktora zwraca srodek bryly.
 */
  Vector3D GetSrodekBryly() const
  {
    return SrodekBryly;
  }
  /*!
 *\brief Metoda ktora zwraca nazwe pliku zapisu bryly.
 */
  std::string GetNazwaPliku() const
  {
    return NazwaPliku;
  }

  /*!
 *\brief Metoda ktora wykonuje operacje przesuniecia bryly.
 */
  void Przesun(Vector3D przes);
  /*!
 *\brief Metoda ktora wykonuje operacje translacji bryly.
 */
  void Translacja(Macierz3x3 obr);
  /*!
 *\brief Metoda ktora wykonuje operacje zapisu bryly do pliku
 */
  void Zapisz();

 bool czy_kolizja(shared_ptr <ObiektySceny> ob);

  double promien()
  {return sqrt(pow(SrodekBryly[0]-WierzBryly[0][0],2) + pow(SrodekBryly[1]-WierzBryly[0][1],2)+pow(SrodekBryly[2]-WierzBryly[0][2],2));} //do przerobienia wrzuc do cpp.
};

#endif
