#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 
#include <ctype.h>
#include <time.h>
#include <unistd.h>

int* moveTurtle(void);
int* moveRabbit(void);
void toStringArray(int array[], int size);

int main()
{   
    srand(time(0));
    int road[80] = {0};
    for (int i = 0; i < 80; i++)
        road[i] = i;
    return 0;
}

int* moveTurtle(void)
{   
    static int move[2] = {0};
    int randNum;
    randNum = 1 + rand() % 10;
    if(randNum >5) {
        move[0] = 3;
        move[1] = 1;
    } else if (randNum <= 2) {
        move[0] = 6;
        move[1] = -1;
    } else if (randNum > 2 && randNum <= 5) {
        move[0] = 1;
        move[1] = 1;
    }
    return &move[0];
}   

int* moveRabbit(void)
{   
    static int motion[2] = {0};
    int randNum;
    randNum = 1 + rand() % 10;
    if(randNum <= 2) {
        motion[0] = 0;
        motion[1] = 0;
    } else if (randNum > 2 && randNum <=4) {
        motion[0] = 9;
        motion[1] = 1;
    } else if (randNum == 5) {
        motion[0] = 12;
        motion[1] = -1;
    } else if (randNum > 5 && randNum <= 8){
        motion[0] = 1;
        motion[1] = 1;
    } else if (randNum > 8) {
        motion[0] = 2;
        motion[1] = -1;
    }
    return &motion[0];
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
