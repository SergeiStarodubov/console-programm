#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 
#include <ctype.h>
#include <time.h>
#include <unistd.h>

typedef struct {
    const char* face;
    const char* suit;
} Card;

void fillDesk(Card* const wDesk, const char* wFace[], const char* wSuit[]);
void shuffle(Card* const wDeck);
void deal (Card* const wDeck);

int main(void)
{
    Card deck[52];
    const char* suit[4] = {"hearts", "diamonds", "clubs", "spades"};
    const char* face[13] = {
		"Deuce","Three",
		"Four","Five", "Six",
		"Seven","Eight","Nine", 
		"Ten","Jack","Queen",
		"King", "Ace"};
    srand(time(NULL));
    fillDesk(deck, face, suit);
    shuffle(deck);
    deal(deck);
    return 0;
}

void fillDesk(Card* const wDesk, const char* wFace[], const char* wSuit[])
{
    int i;
    for (int i = 0; i < 52 ; i++)
    {
        wDesk[i].face = wFace[ i % 13 ];
        wDesk[i].suit = wSuit[ i / 13 ];
    }
}

void shuffle(Card* const wDeck)
{
    int i;
    int j;
    Card temp;
    for (int i = 0; i < 52; i++)
    {
        j = rand() % 52;
        temp = wDeck[i];
        wDeck[i] = wDeck[j];
        wDeck[j] = temp;
    }
}

void deal ( Card* const wDeck )
{
    int i;
    for (int i = 0; i < 52; i++)
        printf("%s of %s\n", wDeck[i].face, wDeck [i].suit);
}
