#include <iostream>
#include <cstdlib>

using namespace std;

struct number
	{
		int value;				//wartość
		number *next;			//wskaźnik na następny element
		number *previous;
	};
	
int main()
{
	struct number *head = NULL;		//lista jest pusta
	struct number *tail = NULL;
	struct number *temp = NULL;
	int condition;				//warunek
	
	do 
	{	
	cout << "\n Co chcesz zrobić? \n Wybierz jedną z instrukcji: \n"  //wybor warunku
		 << " 1 - aby dodać element do kolejki \n"
		 << " 2 - aby usunąć element z kolejki \n"
		 << " 3 - aby wyświetlić zawartość kolejki\n"
		 << " CLRL + Z - aby zakończyć program. \n";
	
		cin >> condition; 
		
		switch (condition)
		{
			case 1:
				temp = new number;		//new - operator dynamicznie przydzielanej pamieci
				cout << "Podaj wartosc elementu kolejki:  ";
				cin >> temp->value;
				if (head == NULL)		//kolejka jest pusta
				{
					temp->next = temp->previous = NULL;
					tail = head = temp;
				}
				else					//kolejka jest niepusta
				{
					temp->next = NULL;
					tail->next = temp;
					temp->previous = tail;
					tail = temp;
				}
				break;	
				
			case 2:
				if(head != NULL)
				{
					temp = head;
					if (head == tail)	//jeden element kolejki
					{
						head = tail = NULL;
					}
					else				// wiecej el. kolejki
					{
						head = head->next;
					}
					delete temp;		//zwalniania dynamicznie przydzielonej pamieci
				}
				else
				{
					cout << "kolejka jest pusta!\n";
				}
				break;
				
			case 3:
				if(head !=NULL)
				{
					cout << "Zawartosc kolejki: ";
					temp = head;
					
					while (temp != NULL) // dopoki kolejka jest nie pusta
					{
						cout << temp->value << " ";
						temp = temp->next;
					}
				}
				else
				{
					cout << "Kolejka jest pusta!" << endl;
				}
				break;
				
			default:
				cout << "Musisz wybrac jedna z instrukcji!"
					 << " 1 - aby dodać element do kolejki \n"
		 			 << " 2 - aby usunąć element z kolejki \n"
					 << " 3 - aby wyświetlić zawartość kolejki";
				break;
				
		}
	} while (condition < 4);

	
	return 0;
}