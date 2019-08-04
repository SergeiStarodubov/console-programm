#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 
#include <ctype.h>
#include <time.h>

void shuffle(int wDeck[][13]);
void deal(const int wDeck [] [13], const char* wFace[], const char* wSuit[], int user1[5][2], int user2[5][2]);
bool hasTwo(int[5][2]);

int main ()
{   
    int gamer1[5][2] = {0};
    int gamer2[5][2] = {0};
    const char* suit[4] = {"hearts", "diamonds", "clubs", "spades"};
    const char* face[13] = {
		"Ace", "Deuce","Three",
		"Four","Five", "Six",
		"Seven","Eight","Nine", 
		"Ten","Jack","Queen",
		"King"};
    
    int deck [4][13] = {0};
    srand(time(0));
    shuffle(deck);
    deal(deck,face,suit, gamer1, gamer2);

    for (int i = 0; i < 5; i++)
    {   
            int suit_user = gamer1[i][0];
            int face_user = gamer1[i][1];
            printf("1 - %s -> %s\n", face[face_user], suit[suit_user] );
    }
    for (int y = 0; y < 5; y++)
    {   
            int suit_user = gamer2[y][0];
            int face_user = gamer2[y][1];
            printf("2 - %s -> %s\n", face[face_user], suit[suit_user] );
    }
    
    return 0;
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
    int row;
    int column;
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
