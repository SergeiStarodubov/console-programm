#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 

void bubbleSorting(int [], int);
void toStringArray(int [], int);
void addSet(void);
int includesInt(int [], int, int);

int main() {    
	addSet();
    return 0;
}

void addSet(void)
{
	int array[5] = {0};
	int num;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &num);
		if(includesInt(array, 5, num) != 1 ) array[i] = num;
	}
	toStringArray(array, 5);
	
}

int includesInt(int array[], int size, int number)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == number) return 1;
	}
	return 0;	
}

void bubbleSorting(int array [], int size)
{
	int semaphor = 1;
	for (int i = 0; i < size-1; i++)
	{
		if (array[i] > array[i+1]) {
			int tmp = array[i];
			array[i] = array[i+1];
			array[i+1] = tmp;
			semaphor = 0;
		}
	}
	if (semaphor == 0) bubbleSorting(array, size);
}

void toStringArray(int array[], int size)
{	

	for (int i = 0; i < size; i++)
	{
		if (i == 0)	printf("[%d,", array[i]);
		else if  (i == size -1)printf("%d]\n", array[i]);
		else printf("%d,", array[i]);
	}
	
}
