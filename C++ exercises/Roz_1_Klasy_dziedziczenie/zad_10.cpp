#include <iostream>

class trojkat
{
public:
    int wysokosc, podstawa;

    void wczytaj_dane();
    void wypisz_dane();
    void pole_trojkata();
};

void trojkat::wczytaj_dane()
{
    std::cout<<"Podaj wysokosc trojkata: ";
    std::cin>>wysokosc;
    std::cout<<"Podaj podstawe trojkata: ";
    std::cin>>podstawa;
}


int main(int argc, char* argv[])
{
    trojkat t;
    t.wczytaj_dane();

    return 0;
}
