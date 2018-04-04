#include <iostream>
#include <vector>

int main()
{
    std::vector <unsigned int> liczby_wejsciowe;
    int liczba;

    do
    {
        std::cout<<"Podaj liczbę dodatnią: ";
        std::cin>>liczba;
        liczby_wejsciowe.push_back(liczba);
    }
    while (liczba);

    for (int i = 0; i < liczby_wejsciowe.size(); ++i)
    {
        std::cout<<liczby_wejsciowe[i]<<std::endl;
    }
    return 0;
}
