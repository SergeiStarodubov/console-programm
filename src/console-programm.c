#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 

void learnShool(void);

int main(void) 
{	
	learnShool();
	return 0;
}


void learnShool(void)
{	
	int amountOfAns = 0;
	int seed = rand() % 1000;
	int response;
	srand(seed);
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
