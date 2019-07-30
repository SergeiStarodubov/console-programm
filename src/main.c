#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 

void bubbleSorting(int []);
void toStringArray(int [], int);
int main() {    
	int arr[10] = {1,5,4,9,10,21,2,42,8,6};
	toStringArray(arr, 10);
    return 0;
}

void bubbleSorting(int array [])
{
	
}

void toStringArray(int array[], int size)
{	

	for (int i = 0; i < size; i++)
	{
		if (i == 0)	printf("[%d,", array[i]);
		else if  (i == size -1)printf("%d]", array[i]);
		else printf("%d,", array[i]);
	}
	
}
