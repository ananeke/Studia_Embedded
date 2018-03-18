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
