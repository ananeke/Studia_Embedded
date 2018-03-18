#include <iostream>
#include <string>

class poczta
{
public:
    std::string nadawca, odbiorca, temat, tresc;
};

void wczytaj(poczta& p)
{
    std::cout<<"Podaj nadawce: \n";
    std::cin>>p.nadawca;
    std::cout<<"Podaj odbiorce: \n";
    std::cin>>p.odbiorca;
    std::cout<<"Podaj temat: \n";
    std::cin>>p.temat;
    std::cout<<"Podaj tresc: \n";
    std::cin>>p.tresc;
}

void wypisz(poczta t)
{
    std::cout<<"nadawca: "<<t.nadawca<<std::endl;
    std::cout<<"odbiorca: "<<t.odbiorca<<std::endl;
    std::cout<<"temat: "<<t.temat<<std::endl;
    std::cout<<"tresc: "<<t.tresc<<std::endl;
}

int main(int argc, char const *argv[])
{
    poczta z;
    wczytaj(z);
    wypisz(z);
}
