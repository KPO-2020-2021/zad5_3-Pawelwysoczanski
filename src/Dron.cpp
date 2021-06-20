
#include "Dron.hh"

/*!
*\brief 
* Konstruktor tworzy model drona ktorego elementy skladowe zapisuje osobno do pliku zlozone z prostopadloscianu oraz graniastoslupow.
*/
Dron::Dron(int id, PzG::LaczeDoGNUPlota &Lacze, Vector3D pozycja) : Lacze(Lacze)
{
    kat = 0;
    this->id = id;
    orginalny.SetNazwaPliku("../dat/korpus" + std::to_string(id) + ".dat");

    for (int i = 0; i < 4; i++)
        wir_o[i].SetNazwaPliku("../dat/wirnik" + std::to_string(i) + std::to_string(id) + ".dat");

    Lacze.DodajNazwePliku(orginalny.GetNazwaPliku().c_str());
    for (int i = 0; i < 4; i++)
        Lacze.DodajNazwePliku(wir_o[i].GetNazwaPliku().c_str());
    kopia = orginalny;

    kopia.Przesun(pozycja);
    for (int i = 0; i < 4; i++)
        wir_k[i] = wir_o[i];

    for (int i = 0; i < 4; i++)
        wir_k[i].Przesun(orginalny[i * 2] + pozycja);

    this->droga = this->droga + pozycja;
}
/*!
  *\brief Metoda ktora wykonuje operacje wznoszenia drona na wysokosc przelotu.
  */
void Dron::Wznoszenie(double droga)
{
    Vector3D droga_o;
    droga_o[2] = droga;

    this->droga = this->droga + droga_o;
    kopia.Translacja(obrot);
    kopia.Przesun(this->droga);
}
/*!
  *\brief Metoda ktora wykonuje operacje Przesuniecia drona.
  */
void Dron::Przesun(double droga)
{
    Vector3D droga_o;
    droga_o[0] = droga * cos(kat * M_PI / 180);
    droga_o[1] = droga * sin(kat * M_PI / 180);
    this->droga = this->droga + droga_o;
    kopia.Translacja(obrot);
    kopia.Przesun(this->droga);
}
/*!
  *\brief Metoda ktora wykonuje operacje Obrotu drona.
  */
void Dron::Obrot(double kat)
{
    this->kat += kat;
    Macierz3x3 nowa;
    obrot = nowa * mac_obr_z(this->kat);
    kopia.Translacja(obrot);
    kopia.Przesun(this->droga);
}
/*!
  *\brief Metoda ktora wykonuje operacje Obrotow rotorow drona.
  */
void Dron::ObrotRotrow()
{
    static int kat = 0;
    kat += 3;
    if (kat == 360)
        kat = 0;

    Macierz3x3 nowa, nowa2;

    for (int i = 0; i < 4; i++)
    {
        if ((i + 1) % 2 == 0)
        {
            nowa = nowa * mac_obr_z(kat);
            wir_k[i].Translacja(nowa);
        }
        else
        {
            nowa2 = nowa2 * mac_obr_z(-kat);
            wir_k[i].Translacja(nowa2);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        wir_k[i].Przesun(kopia[i * 2]);
    }
}
/*!
  *\brief Metoda ktora wykonuje operacje zapisu drona do pliku.
  */
void Dron::Zapisz()
{
    kopia.Zapisz();
    for (int i = 0; i < 4; i++)
        wir_k[i].Zapisz();
}
/*!
  *\brief Metoda ktora wykonuje operacje sterowania dronem.
  */
void Dron::Sterowanie(std::list<std::shared_ptr<ObiektySceny>> &ListaElementow)
{

    double droga;
    double kat;

    Zapisz();
    cout << "Podaj kierunek lotu (kat w stopniach)>";
    cin >> kat;
    cout << "Podaj ddlugosc lotu> ";
    cin >> droga;
    Lacze.DodajNazwePliku("../dat/trasa.dat");
    RysujDroge(droga, kat);
    cout << "Wznosznie..." << endl;
    for (int i = 0; i < 100; i++)
    {
        kopia = orginalny;
        for (int j = 0; j < 4; j++)
            wir_k[j] = wir_o[j];
        Wznoszenie(1);
        ObrotRotrow();
        Zapisz();
        Lacze.Rysuj();
        usleep(CZAS);
    }

    bool kolizja = false;
    if (kat > 0)
    {
        for (int i = 0; i < kat; i++)
        {
            kopia = orginalny;
            for (int i = 0; i < 4; i++)
                wir_k[i] = wir_o[i];
            Obrot(1);
            ObrotRotrow();
            Zapisz();
            Lacze.Rysuj();
            usleep(CZAS);
        }
    }
    else
    {
        for (int i = 0; i > kat; i--)
        {
            kopia = orginalny;
            Obrot(-1);
            ObrotRotrow();
            Zapisz();
            Lacze.Rysuj();
            usleep(CZAS);
        }
    }

    cout << "Przelot..." << endl;
    for (int i = 0; i < droga; i++)
    {
        kopia = orginalny;
        for (int j = 0; j < 4; j++)
            wir_k[j] = wir_o[j];
        Przesun(1);
        ObrotRotrow();
        Zapisz();
        Lacze.Rysuj();
        usleep(CZAS);
    }
    for (std::list<std::shared_ptr<ObiektySceny>>::const_iterator a = ListaElementow.begin(); a != ListaElementow.end(); a++)
    {
        kopia = orginalny;
        Wznoszenie(-100);
        if (czy_kolizja(*a))
        {
            cout << (*a)->getNazwa() << endl;
            kolizja = true;
        }
        kopia = orginalny;
        Wznoszenie(100);
    }
    cout << "Opadanie..." << endl;
    for (int i = 0; i < 100; i++)
    {
        kopia = orginalny;
        for (int j = 0; j < 4; j++)
            wir_k[j] = wir_o[j];
        Wznoszenie(-1);
        ObrotRotrow();
        Zapisz();
        Lacze.Rysuj();
        usleep(CZAS);
    }
    Lacze.UsunNazwePliku("../dat/trasa.dat");
}
/*!
  *\brief Metoda ktora wykonuje operacje rysowania trasy przelotu drona.   
  */
void Dron::RysujDroge(double droga, double kat)
{
    std::cout << "Rysuje sciezke przelotu" << endl;
    Vector3D nastepny = kopia.GetSrodekBryly();
    nastepny[2] = 0;
    trasa.push_back(nastepny);
    nastepny[2] = 100;
    trasa.push_back(nastepny);
    nastepny[0] += droga * cos((this->kat + kat) * M_PI / 180);
    nastepny[1] += droga * sin((this->kat + kat) * M_PI / 180);
    trasa.push_back(nastepny);
    nastepny[2] = 0;
    trasa.push_back(nastepny);

    std::fstream plik;

    plik.open("../dat/trasa.dat", std::ios::out);
    for (int i = 0; i < (int)trasa.size(); i++)
    {

        plik << trasa[i] << std::endl;
    }
    plik.close();
}
void Dron::usun()
{
    Lacze.UsunNazwePliku(orginalny.GetNazwaPliku().c_str());
    for (int i = 0; i < 4; i++)
        Lacze.UsunNazwePliku(wir_o[i].GetNazwaPliku().c_str());
}

bool Dron::czy_kolizja(shared_ptr<ObiektySceny> Obiekt)
{
    std::shared_ptr<Dron> self = shared_from_this();

    if (Obiekt != self)
    {

        Vector3D SrodekDrona = kopia.GetSrodekBryly();
        Vector3D SrodekObiektu = Obiekt->getSrodekBtyly();
        double l = sqrt(pow(SrodekDrona[0] - SrodekObiektu[0], 2) + pow(SrodekDrona[1] - SrodekObiektu[1], 2) + pow(SrodekDrona[2] - SrodekObiektu[2], 2));
        if (Promien + Obiekt->promien() >= l)
        {
            return true;
        }
    }
    return false;
}