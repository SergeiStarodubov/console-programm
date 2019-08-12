#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 
#include <ctype.h>
#include <time.h>
#include <string.h>

int searchAlphabetIndex(char);

int main(void)
{   
    char alphabet[] = {
        'a', 'b', 'c',
        'd', 'e', 'f',
        'g', 'h', 'i',
        'j', 'k', 'l',
        'm', 'n', 'o',
        'p', 'q', 'r',
        's', 't', 'u',
        'v', 'w', 'x',
        'y','z'
    };
    int matches[28] = {0};
    char text[] = {"to be or not to be, that is the qustion"};
    for (int  i = 0; i < strlen(text); i++)
    {
        if(isalpha(text[i])){
            int index = searchAlphabetIndex(text[i]);
            matches[index]++;
        }
    }
    for (int c = 0; c < sizeof(alphabet); c++)
        printf("%c -> %d\n", alphabet[c], matches[c]);
    
    return 0;
}

int searchAlphabetIndex(char letter)
{
     char alphabet[] = {
        'a', 'b', 'c',
        'd', 'e', 'f',
        'g', 'h', 'i',
        'j', 'k', 'l',
        'm', 'n', 'o',
        'p', 'q', 'r',
        's', 't', 'u',
        'v', 'w', 'x',
        'y','z'
    };
    for (int i = 0; i < strlen(alphabet); i++)
        if(letter == alphabet[i]) return i;  
}
