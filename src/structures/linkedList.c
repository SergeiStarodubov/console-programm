#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 
#include <ctype.h>
#include <time.h>
#include <unistd.h>

typedef struct node
{
    char data;
    struct node* ptrNode;
} Node;

void insert(Node*** ptr, char value);
char delete(Node*** ptr, char value);
void printList(Node** curPtr);
void instructions(void);
int isEmpty(Node** ptr);

int main(void) {
    instructions();
    Node** startPtr = NULL;
    int choice;
    char symbol;

    printf("? ");
    scanf("%d", &choice);

    while (choice != 3 )
    {
        switch (choice)
        {
        case 1:
            puts("Enter symbol: ");
            scanf("%c", &symbol);
            insert(&startPtr, symbol);
            printList(startPtr);
        break;
        case 2:
            if (!isEmpty(startPtr)){
                puts("Enter symbol to be deleted");
                scanf("%c", &symbol);
                if (delete(&startPtr, symbol)) {
                    printf("%c was deleted\n ", symbol);
                    printList(startPtr);
                } else puts("The symbol is not found");
            } else puts("List is empty");
        break;
        default:
            puts("Invalid choice");
            instructions();
            break;
        }
        printf("? ");
        scanf("%d", &choice);
    }
    puts("End of run.");
    return 0;
}

void instructions(void)
{
    puts("Enter your choice:");
    puts("1 - to insert an element into linked list");
    puts("2 - to delete an element of linked lis");
    puts("3 - to exit from programm");
}
void insert(Node*** ptr, char value)
{

}
char delete(Node*** ptr, char value)
{

}
void printList(Node** curPtr)
{

}
