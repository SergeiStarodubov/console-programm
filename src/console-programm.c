#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 

double computeCharges(double, int);
void layout(void);
double floorInit(double);
double getHypotenuse(double, double);
int integerPower(int, int);
int multiply(int, int);
void setSquare(int, char);
double getRestByDevide(double, double);
void paintNumber(int);
int getTime(int, int, int);
double getSmallest(double, double, double);
int getPerfect(int);
void typePerfectNumber(int, int);
int getSimpleNumber(int);
void typeSimpleNumbers(int, int);
int reverseNumber(int);
int getNOD(int, int);
int throwCoin(void);
void learnShool(void);

int main(void) 
{	
	learnShool();
	return 0;
}


void learnShool(void)
{	
	srand(2323);
	int response;
	while (1)
	{
		int a = rand() % 10;
		int b = rand() % 10;
		printf("How much is %d times %d?   ",a, b );
		int result = a * b;
		scanf("%d", &response);
		if (response == -1) {
			printf("\nthanks for learning. See you soon\n");
			break;
		}
		while (1)
		{
			if (response == result){
				int talk = rand() % 5;
				switch (talk)
				{
				case 0:
					printf("very good!\n");
					break;
				case 1:
					printf("excellent!\n");
					break;
				case 3:
					printf("nice work!\n");
					break;
				case 4:
					printf("keep up the good work!\n");
					break;
				default:
					printf("very good!\n");
					break;
				}
				break;
			} 
			else 
			{
				int talk = rand() % 5;
				switch (talk)
				{
				case 0:
					printf("No.Please, try again:  ");
					break;
				case 1:
					printf("it is wrong. Try again:  ");
					break;
				case 2:
					printf("Wrong.Please try more:  ");
					break;
				case 3:
					printf("Don't give up!  ");
					break;
				default:
					printf("Nope. Keep trying  ");
					break;
				}
				scanf("%d", &response);
			}
		}
		
	}
	

}

int throwCoin(void)
{
	srand(1);
	int result = rand() % 2;
	return result;
}

int getNOD(int a, int b)
{
	int bigNum = (a > b)? a : b;
	int result = 1;
	for (int i = 1; i <= bigNum; i++)
	{
		if (a % i == 0 && b % i == 0) result = i;
	}
	return result;
}

int reverseNumber(int number) 
{	
	int devider = 1000;
	int mod;
	int rest;
	int one;
	int two;
	int three;
	int four;
	for (int i = 1; i <= 4; i++) 
	{
		mod = floor(number/devider); // 4
		rest = fmod(number,devider); //567
		number = rest;
		devider /= 10;

		switch (i)
		{
		case 1:
			four = mod;
			break;
		case 2:
			three = (mod*10);
		case 3:
			two = (mod*100);
		case 4:
			one = (mod*1000);
		default:
			break;
		}
	}

		printf("%d\n", one + three + two+ four );
	return 0;
}

void typeSimpleNumbers(int a, int b)
{
	for(int i = a; i<=b ; i++) 
	{
		if (getSimpleNumber(i) == 1) printf("%d\n", i);
	}
}

int getSimpleNumber(int num)
{
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0) return 0;
	}
		return 1;
	
}

void typePerfectNumber(int a, int b)
{
	for (int i = a; i <= b; i ++)
	{
		if (getPerfect(i) == 1) printf("%d\n", i);
	}
}

int getPerfect(int num)
{
	int sumOfdevider = 0;
	for (int i = 1; i < num; i++)
	{	
		if (num % i == 0)	sumOfdevider+= i;
	}
		if (sumOfdevider == num) return 1;
		else return 0;
}

double getSmallest (double a, double b, double c)
{
	double smallest;
	if (a < b && a < c)	smallest = a;
	else if (b < a && b < c ) smallest = b; 
	else if (c < a && c < b) smallest = c;
	else smallest = a;
	return smallest;
}

int getTime(int hours, int minutes, int secundes)
{
	int time = hours*60*60 + minutes*60 + secundes;
	return time;
}

void paintNumber(int number) 
{	
	int devider = 1000;
	int output;
	int result;
	for (int i = 0; i < 4; i++)
	{
		output = number/devider;
		printf("%d  ", output);
		result = getRestByDevide(number, devider) * devider;
		devider = devider/10;
		number = result;
	}
	
		
}

double getRestByDevide(double x, double y)
{
	int  base = (x/y);
	double rest = (x/y) - base;
	return rest;
}

void setSquare(int side, char symbol)
{
	for (int i = 0; i < side; i++)
	{
		for (int c = 0; c < side; c++)
		{	
			if(c == side -1) printf("%c\n", symbol);
			else printf("%c", symbol);
		}

		
	}
	
}

int multiply (int a, int b) 
{
	if (a % b == 0) return 1;
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