
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double computeCharges(double, int);
void layout(void);
double floorInit(double);

int x = 5;
int main(void) {
	double n = floorInit(5.5);
	printf("%.1f", n);
	return 0;
}

double floorInit(double number) {
	return floor(number);
}
void layout (void) {
	printf("car      hours    charge\n");
}
double computeCharges(double hours, int id) {
	double result;
	if (hours <= 3) result = 2;
	else if ( hours > 3) {
		result = (hours - 3)*0.5;
	} else if (hours >= 24) result = 10;
	printf(" %d   	 %.1f      %.1f\n", id, hours, result );
	return result;
}
