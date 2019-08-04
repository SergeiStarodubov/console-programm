#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 
#include <ctype.h>
#include <time.h>

//helpers to develop
void toStringArray(int array[], int size);
void lookAtUserCards(const int userCards[5][2], const char* faces[], const char* suits[]);
//work functions
void shuffle(int wDeck[][13]);
void deal(const int wDeck [] [13], const char* wFace[], const char* wSuit[], int user1[5][2], int user2[5][2]);
int hasPair(int[5][2]);
int hasTwoPair(int cards[5][2]);
int* createMatchesMap(int cards[5][2]);


int main ()
{   
    int gamer1[5][2] = {0};
    int gamer2[5][2] = {0};
    const char* suit[4] = {"hearts", "diamonds", "clubs", "spades"};
    const char* face[13] = {
		"Deuce","Three",
		"Four","Five", "Six",
		"Seven","Eight","Nine", 
		"Ten","Jack","Queen",
		"King", "Ace"};
    
    int deck [4][13] = {0};
    srand(time(0));
    shuffle(deck);
    deal(deck,face,suit, gamer1, gamer2);
    int res = hasTwoPair(gamer1);
    printf("%d\n", res);
    return 0;
}

int* createMatchesMap(int cards[5][2])
{
    static int matches[13] = {0};
    for (int i = 0; i < 5; i++)
    {
        int face = cards[i][1];
        matches[face]++;
    }
    return  matches;
}

int hasTwoPair(int cards[5][2])
{   
    puts("hasTwoPair");
    int* matchesTwoPair = createMatchesMap(cards);
    int semaphor = false;
    for (int y = 0; y < 13; y++)
    {
     if(matchesTwoPair[y] == 2 && semaphor) return y;  
     if(matchesTwoPair[y] == 2 && !semaphor) semaphor = true;
    }
    return -1;
}

int hasPair(int cards[5][2])
{
    puts("hasPair");
    int* matchesPair = createMatchesMap(cards);
    for (int y = 0; y < 13; y++)
    {
     if( matchesPair[y] == 2) return y;
    }
    return -1;
}

void deal (const int wDeck[][13], const char* wFace[], const char* wSuit[], int user1[5][2], int user2[5][2])
{
    int card;
    int row; // face
    int column; //suit

    for (card = 0; card < 52; card++)
    {
        for (row  = 0; row < 4; row++)
        {
            for (column = 0; column < 13 ; column++)
            {
                if (wDeck[row][column] == card && card < 5) 
                {
                    user1[card][0] = row;
                    user1[card][1] = column;
                } else if ((wDeck[row][column] == card && card >= 5 && card < 10)){
                    int index = card - 5;
                    user2[index][0] = row;
                    user2[index][1] = column;
                }
                
            }
            
        }
        
    }
    
}

void shuffle(int wDeck[][13])
{
    int row; //face
    int column; //suit
    int card;

    for (card = 0; card < 52; card++)
    {
        do
        {
            row = rand() % 4;
            column = rand() % 13;
        } while (wDeck[row][column] != 0);
        wDeck[row][column] = card;
    }
    
}

void lookAtUserCards(const int userCards[5][2], const char* faces[], const char* suits[])
{
    for (int i = 0; i < 5; i++)
    {   
            int suit_user = userCards[i][0];
            int face_user = userCards[i][1];
            printf("player - %s -> %s\n", faces[face_user], suits[suit_user] );
    }
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
