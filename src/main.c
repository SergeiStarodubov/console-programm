#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 
#include <ctype.h>

void bubbleSorting(int [], int);
void toStringArray(int [], int);
void addSet(void);
int includesInt(int [], int, int);
void throwDuces(void);
void bookTicket(void);
int checkFreePlace(int [],int, int);
int setPlace(int [], int);
void setNumberByRef(int *, int);
void convertToUpper(char *);
void printString(const char *);
void boobleSortByRefs(int[], int);
size_t getLenght(float[]);
void copyString(char[], char[], int);
void deck(void);
void func(void(*callback)(void));
void saySome(void);

int main() { 
	float numbers [10] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.10};
	float* pointer;
	pointer = &numbers[0];
	printf("%.1f\n", *(numbers+3));
	printf("%.1f\n", *(pointer+3));
	printf("%.1f\n", pointer[3]);
	return 0;
}


void func(void (*callback)(void))
{
	(*callback)();
}

void saySome(void)
{
	puts("hello there");
}
void deck(void)
{
	void shuffle(char*[] );
	char *suits[4] = {"spades", "cube", "diamond", "hearts"};
	char *faces[13] = {
		"Ace", "Deuce","Three",
		"Four","Five", "Six",
		"Seven","Eight","Nine", 
		"Ten","Jack","Queen",
		"King"};
	int checkRepeat [4][13] = {0};
	shuffle(faces);
}
void shuffle(char *suit[])
{
	printf("%s\n", suit[0]);
}

void copyString(char string[], char string2[], int size)
{
	char *copy = &string[0];

	for (int i = 0; i < size; i++)
	{
		string2[i] = *copy;
		copy++; 	
	}
	
}

size_t getLenght(float arr[]) {
	return sizeof(*arr);
}

void boobleSortByRefs(int array[], int size)
{
	void swap(int*, int*);
	bool isSorted = true;
	for (int i = 0; i < size-1; i++)
	{
		if (array[i] > array[i+1]) {
			swap(&array[i], &array[i+1]);
			isSorted = false;
		}
	}
	if (!isSorted) boobleSortByRefs(array,size);
}

void swap(int *ptr1, int *ptr2)
{
	int tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}

void printString(const char *pointer)
{
	for (; *pointer != '\0'; pointer++)
	{
		printf("%c", *pointer);
	}
	
}

void convertToUpper(char *str )
{
	while (*str != '\0')
	{	
		*str = islower(*str) ? toupper(*str) : *str;
		*str++;
	}
}

void setNumberByRef(int *number, int value)
{
	*number = value;
}


void bookTicket(void)
{
	int skyPriority[5] = {0};
	int econom[5] = {0};
	int curPlace;
	while (1)
	{
		printf("please, input 1 for sky priority\n");
		printf("please, input 2 for econom\n");
		scanf("%d", &curPlace);
		if (curPlace == 1) {
			int res = setPlace(skyPriority, 5);
			if (res == 0) {
				printf("permit it? -> ");
				int permission;
				scanf("%d", &permission);
				permission == 1 ? setPlace(econom,5) : printf("Next fly is in 3 hour\n"); 
			}

		} else if (curPlace == 2) {
			int result = setPlace(econom, 5);
			if (result == 0) {
				printf("permit it? -> ");
				int permission;
				scanf("%d", &permission);
				permission == 'y' ? setPlace(skyPriority,5) : printf("Next fly is in 3 hour\n"); 
			} 
		}
		toStringArray(econom, 5);	
		toStringArray(skyPriority, 5);	
	}
}

int checkFreePlace(int array[], int size, int place)
{
	if (place > size) return 0;
	if (array[place] == 0) return 1;
	else return 0;
}

int setPlace(int array[],int size)
{
	for (int i = 0; i < size; i++)
	{
		if(checkFreePlace(array, size, i) == 1) {
			array[i] = 1;
			return 1;
		}
	}
	return 0;
	
}


void throwDuces(void)
{	
	static int overall[15] = {0};
	int duce1, duce2, result;
	for (int i = 0; i < 36000; i++)
	{
		duce1 = 1 + rand() % 6;
		duce2 = 1 + rand() % 6;
		result = duce2 + duce1;
		overall[result] += 1;
	}

	toStringArray(overall, 15);
	
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
