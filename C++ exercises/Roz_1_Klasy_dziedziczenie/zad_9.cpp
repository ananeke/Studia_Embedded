#include <iostream>
#include <string>

class ksiazka
{
public:
    std::string tytul, autor, wydawca;
    void wypisz();
    void wczytaj();
};

void ksiazka::wypisz()
{
    std::cout << "tytul ksiazki: "<<tytul << '\n';
    std::cout << "autor ksiazki: "<<autor << '\n';
    std::cout << "wydawca ksiazki: "<<wydawca << '\n';
}

void ksiazka::wczytaj()
{
    std::cout<<"Podaj tytul: \n";
    std::cin>>tytul;
    std::cout<<"Podaj autora:  \n";
    std::cin>>autor;
    std::cout<<"Podaj wydawce: \n";
    std::cin>>wydawca;
}

int main(int argc, char* argv[])
{
    ksiazka t;
    t.wczytaj();
    t.wypisz();

    return 0;
}
