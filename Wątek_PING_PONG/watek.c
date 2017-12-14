#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#define BUF_SIZE 10

char bufor[BUF_SIZE];
int pelny = 0;
pthread_mutex_t straznik;						//mutex
pthread_cond_t bufor_pelny, bufor_pusty;		//zmienne warunkowe

void* zapis(void *arg)
{
	int i = 0;
	while(1)
	{
		pthread_mutex_lock(&straznik);				//mutex blokujacy zapewniajacy operacje atomowa
		
			while(pelny == 1)						//zapobieganie wybudzaniu przez procesor tzw. spurious wakeup
			{
				pthread_cond_wait(&bufor_pusty, &straznik);
			}

			if(i%2)
			{
				memcpy(bufor, "PING!", BUF_SIZE);
			}
			else
			{
				memcpy(bufor, "PONG!", BUF_SIZE);
			}
			i++;
			pelny = 1;
			pthread_cond_signal(&bufor_pelny);		// zapelnienie bufora zapisu - informacja dla watka odczytu
		
		pthread_mutex_unlock(&straznik);			//mutex odblokowujacy
	}
	pthread_exit(NULL);
}

void* odczyt(void *arg)
{
	char lbufor[BUF_SIZE];
	int index = 0;
	
	while(1)
	{
		pthread_mutex_lock(&straznik);
		
			while(pelny == 0)
			{
				pthread_cond_wait(&bufor_pelny,&straznik);
			}
			memcpy(lbufor, bufor, BUF_SIZE);
			printf("%s\n",lbufor);
			pelny = 0;
			pthread_cond_signal(&bufor_pusty);
		
		pthread_mutex_unlock(&straznik);
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t thread_zapis,thread_odczyt;
	
	pthread_mutex_init(&straznik, NULL);					//init mutexu
	
	pthread_cond_init(&bufor_pusty, NULL);					// inity zmiennych warunkowych
	pthread_cond_init(&bufor_pelny, NULL);
	
	pthread_create(&thread_zapis, NULL, zapis, NULL);		//tworzenie watkow
	pthread_create(&thread_odczyt, NULL, odczyt, NULL);
	
	pthread_join(thread_zapis, NULL);						//watek czeka az sie zakonczy 
	pthread_join(thread_odczyt, NULL);
	
	pthread_mutex_destroy(&straznik);						// usuwanie mutexu
	
	pthread_cond_destroy(&bufor_pelny);						// usuwanie zmiennej warunkowej
	pthread_cond_destroy(&bufor_pusty);
	
	return 0;
}





































