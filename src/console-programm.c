
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double computeCharges(double, int);
void layout(void);
double floorInit(double);
double getHypotenuse(double, double);

int main(void) {
	double y = getHypotenuse(10, 10);
	printf("!!!!!!!!!%.1f", y);
	return 0;
}


double getHypotenuse(double a, double b) {
	double tmp = pow(a,2) + pow(b,2);
	printf("&&&&&%.2f\n", tmp);
	double c = sqrt(tmp);
	printf("-----%.2f\n", c);
	return c;
}

double floorInit(double number) {
	double anotherNum = floor(number*100 + 0.5)/100;
	return anotherNum;
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
