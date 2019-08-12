#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 
#include <ctype.h>
#include <time.h>

int main(void)
{   

    char arr[6];
    puts("input numbers:");
    gets(arr);
    puts("you have inputed");
    for (int i = 0; i < sizeof(arr); i++)
    {   
        printf("%c\n", toupper(arr[i]));
    }
    
    return 0;
}