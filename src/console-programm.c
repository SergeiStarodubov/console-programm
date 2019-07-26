
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double computeCharges(double, int);
void layout(void);
double floorInit(double);
double getHypotenuse(double, double);
int integerPower(int, int);

int main(void) {

	return 0;
}

int integerPower(int a, int b)
 {
	int result = 1;
	for (int i = 0; i < b; i++)
		result *= a;
	return result;
}

double getHypotenuse(double a, double b) 
{
	double tmp = pow(a,2) + pow(b,2);
	double c = sqrt(tmp);
	return c;
}

double floorInit(double number) 
{
	double anotherNum = floor(number*100 + 0.5)/100;
	return anotherNum;
}

void layout (void) 
{
	printf("car      hours    charge\n");
}

double computeCharges(double hours, int id) 
{
	double result;
	if (hours <= 3) result = 2;
	else if ( hours > 3) {
		result = (hours - 3)*0.5;
	} else if (hours >= 24) result = 10;
	printf(" %d   	 %.1f      %.1f\n", id, hours, result );
	return result;
}