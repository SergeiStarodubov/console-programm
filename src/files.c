#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 
#include <ctype.h>
#include <time.h>
#include <unistd.h>

int main() {
    int account;
    char name[30];
    float balance;

    FILE* ptr;

    if ((ptr = fopen("clients.dat", "w")) == NULL) puts("the file is not found");
    else {
        puts("--------------");
        scanf("%d%s%1f", &account, name, &balance);
        while (!feof(stdin))
            fprintf(ptr, "%d %s %.2f\n", account, name, balance);
        fclose(ptr);
    }
    return 0;
}