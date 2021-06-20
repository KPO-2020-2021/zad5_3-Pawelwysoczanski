#include "BrylaGeometryczna.hh"

/*!
 *\brief 
 * Metoda pokolei przeuswa kazdy wierzcholek bryly geometrycznej
 * o zadany wektro, na koncu przesuwa tez srodek samej bryly. 
 */
void BrylaGeometryczna::Przesun(Vector3D przes)
{
    for (int i = 0; i < (int)WierzBryly.size(); i++)
    {
        WierzBryly[i] = WierzBryly[i] + przes;
    }
    SrodekBryly = SrodekBryly + przes;
}
/*!
 *\brief 
 * Metoda pokolei mnozy kazdy wierzcholek bryly geometrycznej 
 * razy macierz, na koniec operacje wykonuje rowniez na srodku
 * bryly.
 */
void BrylaGeometryczna::Translacja(Macierz3x3 obr)
{
    for (int i = 0; i < (int)WierzBryly.size(); i++)
    {
        WierzBryly[i] = (obr * WierzBryly[i]);
    }
    SrodekBryly = obr * SrodekBryly;
}
/*!
 *\brief
 * Metoda otwiera plik do ktorego przekazuje pokolei wspolrzedne wierzcholkow
 * bryly , na koniec w celu poprwanego rysowania bryly zapisu dwie pierwsze wspolrzedne.
 */
void BrylaGeometryczna::Zapisz()
{
    std::fstream plik;
    double tab[] = {0, 0, (*wymiaryBryly)[2] / 2};
    Vector3D przesun_sr(tab);

    plik.open(NazwaPliku, std::ios::out);

    for (int i = 0; i < (int)WierzBryly.size(); i += 2)
    {
        plik << SrodekBryly + przesun_sr << std::endl;
        for (int j = 0; j < 2; j++)
        {
            plik << WierzBryly[j + i] << std::endl;
        }
        plik << SrodekBryly - przesun_sr << std::endl
             << std::endl;
    }

    plik << SrodekBryly + przesun_sr << std::endl;
    for (int j = 0; j < 2; j++)
    {
        plik << WierzBryly[j] << std::endl;
    }
    plik << SrodekBryly - przesun_sr << std::endl
         << std::endl;
    plik.close();
}
bool BrylaGeometryczna::czy_kolizja(shared_ptr<ObiektySceny> ob)
{
    std::shared_ptr<BrylaGeometryczna> self = shared_from_this();

    if (ob != self)
    {

        Vector3D srodek_Bryla = GetSrodekBryly();
        Vector3D srodek_Obiektu = ob->getSrodekBtyly();

        double l = sqrt(pow(srodek_Bryla[0] - srodek_Obiektu[0], 2) + pow(srodek_Bryla[1] - srodek_Obiektu[1], 2) + pow(srodek_Bryla[2] - srodek_Obiektu[2], 2));

        if (promien() + ob->promien() >= l)
        {
            return true;
        }
    }
    return false;
}