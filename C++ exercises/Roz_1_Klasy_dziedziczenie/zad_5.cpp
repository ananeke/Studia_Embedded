#include <iostream>
#include <string>

struct poczta
{
    std::string nadawca, odbiorca, temat, tresc;
    void wczytaj();
    void wypisz();
};

void poczta::wczytaj()
{
    std::cout<<"Podaj nadawce: \n";
    std::cin>>nadawca;
    std::cout<<"Podaj odbiorce: \n";
    std::cin>>odbiorca;
    std::cout<<"Podaj temat: \n";
    std::cin>>temat;
    std::cout<<"Podaj tresc: \n";
    std::cin>>tresc;
}

void poczta::wypisz()
{
    std::cout<<"nadawca: "<<nadawca<<std::endl;
    std::cout<<"odbiorca: "<<odbiorca<<std::endl;
    std::cout<<"temat: "<<temat<<std::endl;
    std::cout<<"tresc: "<<tresc<<std::endl;
}

int main(int argc, char const *argv[])
{
    poczta z;
    z.wczytaj();
    z.wypisz();
}
