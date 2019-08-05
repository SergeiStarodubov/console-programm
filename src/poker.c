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
int hasThree(int cards[5][2]);
int hasCare(int cards[5][2]);
int hasFlash(int cards[5][2]);
int hasStreet(int cards[5][2]);
int hasOrederedNum(int numbers[13]);
char* defineWinner(int [][2], int [][2]);
int hasOne(int [][2]);

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
    char* result;
    result = defineWinner(gamer1, gamer2);
    for (int i = 0; i < 5; i++)
    {
        printf("%c", result[i]);
    }
    
    return 0;
}

char* defineWinner(int user1[5][2], int user2[5][2])
{   
    int user1Score[2] = {0};
    int user2Score[2] = {0};
    if (hasStreet(user1) != -1) {
        user1Score[0] = 10;
        user1Score[1] = hasStreet(user1);
    } else if (hasFlash(user1) != -1) {
        user1Score[0] = 9;
        user1Score[1] = hasFlash(user1);
    } else if (hasCare(user1) != -1) {
        user1Score[0] = 8;
        user1Score[1] = hasCare(user1);
    } else if (hasThree(user1) != -1){
        user1Score[0] = 7;
        user1Score[1] = hasThree(user1);
    } else if (hasTwoPair(user1)){
        user1Score[0] = 6;
        user1Score[1] = hasTwoPair(user1);
    } else if (hasPair(user1) != -1) {
        user1Score[0] = 5;
        user1Score[1] = hasPair(user1);
    } else if (hasOne(user1) != -1){
        user1Score[0] = 4;
        user1Score[1] = hasOne(user1);
    }

    if (hasStreet(user2) != -1) {
        user2Score[0] = 10;
        user2Score[1] = hasStreet(user2);
    } else if (hasFlash(user2) != -1) {
        user2Score[0] = 9;
        user2Score[1] = hasFlash(user2);
    } else if (hasCare(user2) != -1) {
        user2Score[0] = 8;
        user2Score[1] = hasCare(user2);
    } else if (hasThree(user2) != -1){
        user2Score[0] = 7;
        user2Score[1] = hasThree(user2);
    } else if (hasTwoPair(user2)){
        user2Score[0] = 6;
        user2Score[1] = hasTwoPair(user2);
    } else if (hasPair(user2) != -1) {
        user2Score[0] = 5;
        user2Score[1] = hasPair(user2);
    } else if (hasOne(user2) != -1){
        user2Score[0] = 4;
        user2Score[1] = hasOne(user2);
    }
    static char case1[5] = "user1";
    static char case2[5] = "user2";
    static char case3[5] = "draft";
    if (user1Score[0] > user2Score[0]) return case1;
    else if (user1Score[0] < user2Score[0]) return case2;
    else {
        if (user1Score[1] > user2Score[1]) return case1;
        else if (user1Score[1] < user2Score[1]) return case2;
        else return case3;
    }
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

int hasOne(int card[5][2])
{
    int* matchesOne = createMatchesMap(card);
    for (int i = 13; i >= 0; i--)
    {
        if(matchesOne[i] == 1) return i;
    }
    return -1;
}

int hasOrederedNum(int* numbers)
{   
    int k = 0;
    for (int i = 0; i <= 8; i++)
    {
        if (
            numbers[i] == 1 &&
            numbers[i+1] == 1 &&
            numbers[i+2] == 1 &&
            numbers[i+3] == 1 &&
            numbers[i+4] == 1 
            ) return i+4;
    
    }
    return -1;
}

int hasStreet(int cards[5][2])
{
    int* matchesStreet = createMatchesMap(cards);
    int suitsStreet[4] = {0};
    for (int i = 0; i < 5; i++)
    {
        int index = cards[i][0];
        suitsStreet[index]++;
    }
    for (int y = 0; y < 5; y++)
    {
        if(suitsStreet[y] == 5 && hasOrederedNum(matchesStreet) != -1) {
            return hasOrederedNum(matchesStreet);
        }
    }
    return -1;
}

int hasFlash(int cards[5][2])
{   
    int* matchesFlash = createMatchesMap(cards);  // faces
    int suitsFlash[4] = {0};
    for (int i = 0; i < 5; i++)
    {
        int index = cards[i][0];
        suitsFlash[index]++;
    }
    for (int y = 0; y < 5; y++)
    {
        if (suitsFlash[y] == 5) {
            for (int c = 13; c >= 0; c--)
            {
                if (c != 0) return c;
            }
            
        }
    }
    return -1;
}

int hasCare(int cards[5][2])
{
    int* matchesCare = createMatchesMap(cards);
    for (int i = 0; i < 13; i++)
    {
        if (matchesCare[i] == 4) return i;
    }
    return -1;
}

int hasThree(int cards[5][2])
{
    int* matchesThree = createMatchesMap(cards);
    for (int i = 0; i < 13; i++)
    {
        if (matchesThree[i] == 3) return i;
    }
    return -1;
}

int hasTwoPair(int cards[5][2])
{   
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
