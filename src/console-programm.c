
#include <stdio.h>
#include <stdlib.h>

double computeCharges(double, int);
void layout(void);

int x = 5;
int main(void) {
	layout();
	computeCharges(15,1);
	computeCharges(5,2);
	return 0;
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
