#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM 20

void zero(int *num1, int *num2, int *sum)
{
	int i = 0;
	
	for (i=0;i<MAX_NUM;i++)
	{
		num1[i] = 0;
		num2[i] = 0;		
	}
	for (i=0;i<MAX_NUM+1;i++)
	{
		sum[i] = 0;
	}
}

int main()
{
    FILE *f1 = fopen ("liczba_1.txt","rt");                 //otwarcie plików
    FILE *f2 = fopen ("liczba_2.txt","rt");
    
    int num1[MAX_NUM];
    int num2[MAX_NUM];

	int i;
	int sum[MAX_NUM+1];

	zero(num1, num2, sum);
	
	//test otwarcia plików
    if ((f1 == 0)||(f2 == 0))
    {
         printf("Nie mozna otworzyc pliku!\n");
    }
    else
    {
  		for(i=0;i<MAX_NUM;i++)
		{
			//odczyt znaku
			num1[i] = fgetc(f1) - '0';
			num2[i] = fgetc(f2) - '0';
		}
	}
	
	for (i=0;i<MAX_NUM;i++)
	{
		sum[(MAX_NUM)-i] += num1[(MAX_NUM-1)-i] + num2[(MAX_NUM-1)-i];
		if (sum[(MAX_NUM)-i] >= 10)
		{
			sum[(MAX_NUM)-i] -= 10;
			sum[(MAX_NUM-1)-i] += 1 ;
		}

	}
	
	for (i=0;i<MAX_NUM+1;i++)
	{
		printf("%d",sum[i]);
	}
	
	return 0;
}