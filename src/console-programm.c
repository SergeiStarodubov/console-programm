/*
 ============================================================================
 Name        : console-programm.c
 Author      : Starodubov
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b, c;
	printf("input three different integers: ");
	scanf("%d%d%d",&a, &b, &c );
	printf("sum is %d\n", a + b + c);
	printf("average is %d\n", (a + b + c) /3);
	printf("product is %d\n", a*b*c);

	int smallest, biggest;

	if (a > b && a > c) biggest = a;
	if (b > a && b > c) biggest = b;
	if (c > a && c > b) biggest = c;

	if (a < b && a < c) smallest = a;
	if (b < a && b < c) smallest = b;
	if (c < a && c < b) smallest = c;

	printf("smallest is %d\n", smallest);
	printf("biggest is %d", biggest);

	return 0;
}
