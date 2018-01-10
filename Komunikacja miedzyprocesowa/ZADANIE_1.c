#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define  MAX_ELEMS 5

int count = 0;

struct List
{
	int value;
	struct List* next;
};

struct List* head = NULL;

struct List* GetNewList(int x)
{
	struct List* newList = (struct List*)malloc(sizeof(struct List));
	newList->value = x;
	newList->next = NULL;
	return newList;
}

void PushBack(int x)
{
	struct List* temp = head;
	struct List* newList = GetNewList(x);
	int d = -1;
	if (count < MAX_ELEMS)
	{
		count++;
		if(head == NULL)
		{
			head = newList;
			return;
		}
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newList;
	}
	if (count == MAX_ELEMS)
	{
		count++;
		printf("%d\n",d);
		return;
	}
}

void Print()
{
	struct List* temp = head;
	printf("Ilosc wezlow %d\n", (count<MAX_ELEMS)?count:count-1);
	while(temp != NULL)
	{
		printf("Wartosc: %d\n",temp->value);
		temp = temp->next;
	}
	printf("\n");
}

int Pop(struct List** head)
{
    int retval = -1;
    struct List* next_node = NULL;

    if (*head == NULL)
    {
        return printf("%d\n",retval);
    }

    next_node = (*head)->next;
    retval = (*head)->value;
    free(*head);
    *head = next_node;
		count--;

    return retval;
}

//////////////////////////////Watki
int is_full = 0;
pthread_mutex_t my_mutex;
pthread_cond_t buff_cond_full, buff_cond_empty;

void* foo_write()
{
	int i = 0;
	while(1)
	{
		pthread_mutex_lock(&my_mutex);

			while(is_full == 1)
			{
				pthread_cond_wait(&buff_cond_empty, &my_mutex);
			}

			PushBack(5);
			printf("Write id: %li\n\n", pthread_self());

			is_full = 1;
			pthread_cond_signal(&buff_cond_full);

		pthread_mutex_unlock(&my_mutex);
	}
	pthread_exit(NULL);
}

void* foo_read()
{
	int index = 0;

	while(1) {
		pthread_mutex_lock(&my_mutex);

			while(is_full == 0)
			{
				pthread_cond_wait(&buff_cond_full, &my_mutex);
			}

			printf("READ index = %d | %li\n\n", index++, pthread_self());
			Print();

			//Pop();

			is_full = 0;
			pthread_cond_signal(&buff_cond_empty);

		pthread_mutex_unlock(&my_mutex);
	}
	pthread_exit(NULL);
}


int main()
{
	pthread_t thread_write, thread_read,thread_write_2,thread_read_2;
	pthread_mutex_init(&my_mutex, NULL);
	pthread_cond_init(&buff_cond_full,  NULL);

	pthread_create(&thread_write, NULL, foo_write, NULL);
	pthread_create(&thread_write_2, NULL, foo_write, NULL);
	pthread_create(&thread_read,  NULL, foo_read,  NULL);
	pthread_create(&thread_read_2,  NULL, foo_read,  NULL);

	pthread_join(thread_write, NULL);
	pthread_join(thread_write_2, NULL);
	pthread_join(thread_read, NULL);
	pthread_join(thread_read_2, NULL);

	pthread_mutex_destroy(&my_mutex);


	pthread_cond_destroy(&buff_cond_empty);
	pthread_cond_destroy(&buff_cond_full);
  return 0;
}
