#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 
#include <ctype.h>
#include <time.h>

/*
    The algoritm to shuffle card set. We need to get two address of array cells randomly
    and swap each other by used tempreral variable. Repeat this action during cards 
    is getting mixed up 
 */
int main()
{   
    int seed = time(0);
    srand(seed);
    int desk [4][13] = {0};
    int value = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            desk[i][j] = value++;
        }
        
    }
    int count = 0;
    int tempIndex;
    while(count < 1000)
    {
        int randI1 = rand() % 4;
        int randI2 = rand() % 4;
        int randJ1 = rand() % 13;
        int randJ2 = rand() % 13;
        tempIndex = desk[randI1][randJ1]; 
        desk[randI1][randJ1] = desk[randI2][randJ2];
        desk[randI2][randJ2] = tempIndex;
        count++;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            printf("%d\n", desk[i][j]);
        }
        
    }
    return 0;
}