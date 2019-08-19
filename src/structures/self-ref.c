#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 
#include <ctype.h>
#include <time.h>
#include <unistd.h>


typedef struct listNode
{
    int data;
    struct listNode* next;
} ListNode;

int main(void)
{
    ListNode node1 = {10 , NULL};
    ListNode node2 = {20 , (ListNode*) &node1};
    ListNode node3 = {3 , (ListNode*) &node2};
    ListNode node4 = {4 , (ListNode*) &node3};
    printf("value of node is %d\n",node4.next->next->data);
    return 0;
}
