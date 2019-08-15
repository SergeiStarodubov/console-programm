#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 
#include <ctype.h>
#include <time.h>
#include <unistd.h>

typedef struct 
{
    char lastName[15];
    char firstName[15];
    int customerNumber;
    
    struct 
    {
        char phone[11];
        int zip;
    } personal;
    

} Customer;

void main(void)
{   
    Customer one = {"Starodubov", "Sergey", 28, {"89272087077", 123451}};
    Customer* pointer = &one;
    printf("%d\n",pointer->personal.zip);
}