#ifndef DRON_HH
#define DRON_HH

#include "ObiektySceny.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"
#include "lacze_do_gnuplota.hh"
#include <unistd.h> // biblioteka dla usleep
#define CZAS 30000

/*!
*\file
*\brief Definicja klasy Dron.
*/

/*!
*\ 
*Klasa definiuje pojecie Drona sklasdajacego sie z korpusu w postaci prostopadloscianu
*oraz 4 rotorow zbudowanych z graniastoslupow.
*/
class Dron : public ObiektySceny, public std::enable_shared_from_this<Dron>
{
  /*!
  *\brief Trasa przelotu drona.
  *Przechowuje wektory polozenia przelotu drona.
  */
  std::vector<Vector3D> trasa;
  /*!
  *\brief Lacze umozliwajace rysowanie w programie GNUPlot.
  */
  PzG::LaczeDoGNUPlota &Lacze;
  /*!
  *\brief Oryginalny prostopadloscian.
  *Przechowuje oryginalny prostopadloscina.
  */
  Prostopadloscian orginalny;
  /*!
  *\brief Kopia prostopadloscianu
  *Przechowuje kopie prostopadloscianu.
  */
  Prostopadloscian kopia;
  /*!
  *\brief Oryginalne rotory drona.
  *Przechowuje oryginalna tablice Graniastoslupow.
  */
  Graniastoslup wir_o[4];
  /*!
  *\brief Kopia oryginalnych rotorow drona.
  *Przechowuje kopie oryginalnej tabliczy Graniastoslupow.
  */
  Graniastoslup wir_k[4];
  /*!
  *\brief Macierz obrotu drona.
  *Przechowuje macierz obrotu drona.
  */
  Macierz3x3 obrot;
  /*!
  *\brief Wektor punktu docelowego drona.
  *Przechowuje wpolrzedne drogi drona.
  */
  Vector3D droga;
  /*!
  *\brief Kat obrotu drona.
  *Przechowuje kat o jaki ma sie obrocic dron.
  */
  double kat = 0;
  /*!
  *\brief Id drona.
  *Przechowuje nr id drona.
  */
  int id;

  double Promien;

public:
  /*!
  *\brief Konstruktor bezparametryczny klasy dron. 
  */
  Dron();
  /*!
  *\brief Konstruktor parametryczny klasy dron.
  */
  Dron(int id, PzG::LaczeDoGNUPlota &Lacze, Vector3D pozycja);
  /*!
  *\brief Metoda ktora wykonuje operacje wznoszenia drona na wysokosc przelotu.
  */
  void Wznoszenie(double droga);
  /*!
  *\brief Metoda ktora wykonuje operacje przesuniecia drona.
  */
  void Przesun(double droga);
  /*!
  *\brief Metoda ktora wykonuje operacje obrotu drona.
  */
  void Obrot(double kat);
  /*!
  *\brief Metoda ktora wykonuje operacje obrotow rotorow drona.
  */
  void ObrotRotrow();
  /*!
  *\brief Metoda ktora wykonuje operacje zapisu drona do pliku.
  */
  void Zapisz();
  /*!
  *\brief Metoda ktora wykonuje operacje sterowania dronem.
  */
  void Sterowanie(std::list<std::shared_ptr<ObiektySceny>> &ListaElementow);
  /*!
  *\brief Metoda ktora wykonuje operacje rysowania trasy przelotu drona.   
  */
  void RysujDroge(double droga, double kat);
  /*!
*\brief  Metoda zwraca Id drona.
*/
  int getId() { return id; }

  // void Usun();
  double promien() { return kopia.promien(); }

  Vector3D getSrodekDrona() const
  {
    return kopia.GetSrodekBryly();
  }

  bool czy_kolizja(shared_ptr<ObiektySceny> ob);

  void usun();

  std::string getNazwa() const
  {
    return "dron";
  }
};

#endif
