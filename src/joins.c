#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 
#include <ctype.h>
#include <time.h>
#include <unistd.h>

union num {
    int x;
    double y;
};

typedef struct {
    char* model;
    char* color;
} Car;

int main(void)
{
    Car car1;
    car1.model = "BMW";
    car1.color = "FFF";

    union num number;
    number.x = 100;
    printf("%d\n", number.x);  
    printf("%.2f\n", number.y);  
    number.y = 100;
    printf("%d\n", number.x);  
    printf("%.2f\n", number.y);  
    enum months {HELLO, WORLD};
    printf("enum : %d\n", HELLO);
    return 0;
}