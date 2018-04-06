#include <iostream>
#include <vector>
#include <algorithm>



void odwraca(std::vector<int>& v)
{
    std::reverse(v.begin(), v.end());
    for (unsigned int i = 0; i < v.size(); ++i)
    {
        std::cout<<v[i]<<std::endl;
    }
}

void sort_rosnaco(std::vector<int>& v)
{
    std::sort(v.begin(), v.end());
    for (unsigned int i = 0; i < v.size(); ++i)
    {
        std::cout<<v[i]<<std::endl;
    }
}

void sort_malejaco(std::vector<int>& v)
{
    std::sort(v.rbegin(), v.rend());
    for (unsigned int i = 0; i < v.size(); ++i)
    {
        std::cout<<v[i]<<std::endl;
    }
}


int main()
{
    std::vector <int> liczby_wejsciowe;
    int liczba;

    for (int n = 0; n < 4; ++n)
    {
        std::cout<<"Podaj liczbę dodatnią: ";
        std::cin>>liczba;
        liczby_wejsciowe.push_back(liczba);
    }

    for (unsigned int i = 0; i < liczby_wejsciowe.size(); ++i)
    {
        std::cout<<liczby_wejsciowe[i]<<std::endl;
    }
    std::cout<<"Vector odwrócony: "<<std::endl;
    odwraca(liczby_wejsciowe);
    std::cout<<"Vector posortowany rosnąco: "<<std::endl;
    sort_rosnaco(liczby_wejsciowe);
    std::cout<<"Vector posortowany majlejąco: "<<std::endl;
    sort_malejaco(liczby_wejsciowe);
    return 0;
}
