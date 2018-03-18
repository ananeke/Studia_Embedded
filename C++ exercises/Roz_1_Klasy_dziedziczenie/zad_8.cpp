#include <iostream>
#include <string>

class ksiazka
{
public:
    std::string tytul, autor, wydawca;
};

void wypisz(ksiazka k)
{
    std::cout << "tytul ksiazki: "<<k.tytul << '\n';
    std::cout << "autor ksiazki: "<<k.autor << '\n';
    std::cout << "wydawca ksiazki: "<<k.wydawca << '\n';
}

void wczytaj(ksiazka& p)
{
    std::cout<<"Podaj tytul: \n";
    std::cin>>p.tytul;
    std::cout<<"Podaj autora:  \n";
    std::cin>>p.autor;
    std::cout<<"Podaj wydawce: \n"
    std::cin>>p.wydawca;
}
