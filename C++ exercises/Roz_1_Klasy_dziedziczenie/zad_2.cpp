#include <iostream>
#include <string>

class poczta
{
public:
    std::string nadawca, odbiorca, temat, tresc;
};

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
    z.nadawca = "kowalski";
    wypisz(z);
}
