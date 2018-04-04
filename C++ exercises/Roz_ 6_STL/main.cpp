#include <iostream>
#include <vector>

std::vector <unsigned int> liczby_wejsciowe;

void foo()
{

    int liczba;

    for (int n = 0; n < 10; ++n)
    {
        std::cout<<"Podaj liczbę dodatnią: ";
        std::cin>>liczba;
        liczby_wejsciowe.push_back(liczba);
    }

    for (int i = 0; i < liczby_wejsciowe.size(); ++i)
    {
        std::cout<<liczby_wejsciowe[i]<<std::endl;
    }
}





int main()
{
    foo();
    return 0;
}
