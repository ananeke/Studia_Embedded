#include <stdio.h>

int dane[6];
int rozmiar;

void wyswietl_stos()
{
    printf("\n");
    printf("----------------");
    printf("ZAWARTOSC STOSU:");
    printf("----------------\n");

    int i;
    if (rozmiar==0)
        printf("pusty\n");
    else
    {
        for (i=rozmiar; i>=1; i--)
        {
            printf("%d \n",dane[i]);
        }
    }

    printf("----------------\n\n");
}

void push()
{
    if (rozmiar>=5)
    {
        printf("Stos pelny!");
    }
    else
    {
        printf("\n PUSH (jaka liczbe polozyc na stosie): ");

        rozmiar=rozmiar+1;
        scanf("%d",&dane[rozmiar]);
    }
}

void pop()
{
    if (rozmiar>=1)
    {
        printf("\n POP - nastapi usuniecie ze stosu liczby: %d",dane[rozmiar]);

        rozmiar=rozmiar-1;
    }
    else
    {
        printf("Stos pusty!");
    }
}

void size()
{
    printf("Liczba elementow na stosie: %d",rozmiar);

}

void empty()
{

    if (rozmiar==0)
        printf("\n EMPTY (stos pusty?) ->  TRUE");
    else
        printf("EMPTY (stos pusty?) ->  FALSE");
}

void sort()
{
    int i,j;

    for (i=1;i<rozmiar;i++)
        for (j=rozmiar-1;j>=i;j--)
            if (dane[j]<dane[j-1])
            {
                int temp=dane[j-1];
                dane[j-1]=dane[j];
                dane[j]=temp;
            }
}









int main()
{

    int wybor;
    rozmiar=0;

    do
    {
        wyswietl_stos();

        printf("MENU GLOWNE STOSU: \n");
        printf("------------------------------------------\n");
        printf("1. PUSH (dodaje element na szczyt stosu) \n");
        printf("2. POP (usuwa element ze szczytu stosu) \n");
        printf("3. SIZE (ile elementow na stosie) \n");
        printf("4. EMPTY (czy stos jest pusty?) \n");
        printf("5. SORT (sortowanie elementow stosu) \n");
        printf("6. Koniec programu \n");
        printf("------------------------------------------\n");
        printf("Wybor: ");
        scanf("%d",&wybor);

        switch (wybor)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            size();
            break;

        case 4:
            empty();
            break;

        case 5:
            sort();
            break;

        }

    }
    while (wybor != 6);

    return 0;
}
