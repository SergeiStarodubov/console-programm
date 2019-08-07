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
void toStringArray(int array[], int size);
int checkWinner(int, int);
void renderCompititerOnRoad(int, int);

int main()
{
    system("clear");   
    srand(time(0));
    int road[ ROAD_LENGTH ] = {0};
    for (int i = 0; i < ROAD_LENGTH; i++) 
        road[i] = i;
    register int pos_rabbit = 0;
    register int pos_turtle = 0;
    sayStart();
    while (true)
    {   
        system("clear");
        if (checkWinner(pos_rabbit, pos_turtle) != 0) return 0;
        int* rabbit_move = getMoveRabbit();   
        int* turtle_move = getMoveTurtle();
        puts(" ");
        if (rabbit_move[0] == -1) 
             pos_rabbit = (pos_rabbit - rabbit_move[1] <= 0)? 0 : pos_rabbit - rabbit_move[1] ;
        if (rabbit_move[0] == 1) pos_rabbit += rabbit_move[1];
        if (turtle_move[0] == -1) pos_turtle -= turtle_move[1];
            pos_turtle = (pos_turtle - turtle_move[1] <= 0)? 0 : pos_turtle - turtle_move[1] ;
        if (turtle_move[0] == 1) pos_turtle += turtle_move[1];
        renderCompititerOnRoad(pos_rabbit, pos_turtle);
        sleep(1);
    }   
}


void renderCompititerOnRoad(int pos_rabbit, int pos_turtle)
{
    for (int i = 0; i < 80; i++) {
        if(i == pos_rabbit) printf("R");
        else if(i == pos_turtle) printf("T");
        else if(i == 70) printf("|Finish");
        else printf(" ");
    }
}

int checkWinner(int p_rabbit, int p_turtle)
{
    if (p_rabbit >= 70 && p_turtle >= 70) {
        puts("  TURTLE WINS");
        return 1;
    }
    if(p_rabbit >= 70) {
        puts("  RABBIT WINS");
        return 1;
    }
    if(p_turtle >= 70) {
        puts("  TURTLE WINS");
        return 1;
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
// move[1] == 1 push turtle right
// move[1] == -1 push turtle left
    static int move[2] = {0};
    int randNum;
    randNum = 1 + rand() % 10;
    if(randNum >5) {
        move[0] = 1;
        move[1] = 3;
    } else if (randNum <= 2) {
        move[0] = -1;
        move[1] = 6;
    } else if (randNum > 2 && randNum <= 5) {
        move[0] = 1;
        move[1] = 1;
    }
    return &move[0];
}   

int* getMoveRabbit(void)
{   
// move[1] == 1 push rabbit right
// move[1] == -1 push rabbit left
// move[1] == 0 the rabit has no move
    static int motion[2] = {0};
    int randNum;
    randNum = 1 + rand() % 10;
    if(randNum <= 2) {
        motion[0] = 0;
        motion[1] = 0;
    } else if (randNum > 2 && randNum <=4) {
        motion[0] = 1;
        motion[1] = 9;
    } else if (randNum == 5) {
        motion[0] = -1;
        motion[1] = 12;
    } else if (randNum > 5 && randNum <= 8){
        motion[0] = 1;
        motion[1] = 1;
    } else if (randNum > 8) {
        motion[0] = -1;
        motion[1] = 2;
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
