#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#define ROAD_LENGTH 80

int* getMoveTurtle(void);
int* getMoveRabbit(void);
void sayStart(void);
void toStringArray(char array[], int size);
int checkWinner(int*, int*);
void renderCompititerOnRoad(int*, int*, const int[ROAD_LENGTH]);

int main()
{   
    srand(time(0));
    int road[ ROAD_LENGTH ] = {0};
    for (int i = 0; i < ROAD_LENGTH; i++) road[i] = i;
    int* p_rabbit = &road[0];
    int* p_turtle = &road[75];
    sayStart();
    while (true)
    {   
        if (checkWinner(p_rabbit, p_turtle) != 0) return;
        sleep(1);
    }   
    return 0;
}

void renderCompititerOnRoad(int* p_rabbit, int* p_turtle ,const int road[ROAD_LENGTH])
{
    
}

/*  if function return 1 the winner is rabbit 
    if function return -1 the winner turtle    
    if function return 0 the competition keeps going still */ 
int checkWinner(int* p_rabbit, int* p_turtle)
{
    if (*p_rabbit >= 70 && *p_turtle >= 70) {
        puts("TURTLE WINS");
        return -1;
    }
    if(*p_rabbit >= 70) {
        puts("RABBIT WINS");
        return 1;
    }
    if(*p_turtle >= 70) {
        puts("TURTLE WINS");
        return -1;
    }
    return 0;
}


void sayStart(void)
{
    puts("BANG");
    puts("AND THE'RE OFF");
}


int* getMoveTurtle(void)
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

int* getMoveRabbit(void)
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

void toStringArray(char array[], int size)
{	

	for (int i = 0; i < size; i++)
	{
		if (i == 0)	printf("[%c,", array[i]);
		else if  (i == size -1)printf("%c]\n", array[i]);
		else printf("%c,", array[i]);
	}
	
}
