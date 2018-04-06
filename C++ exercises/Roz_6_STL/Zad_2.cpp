#include <iostream>
#include <vector>

int main()
{
    std::vector <unsigned int> liczby_wejsciowe;
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
    return 0;
}
