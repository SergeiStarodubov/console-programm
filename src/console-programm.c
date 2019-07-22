
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int sum = 0;
	int n = 0;
	int count = 0;
	while (1) {
		scanf("%d", &n);
		if (n !=999) {
			sum += n;
			count++;
		}
		else break;
	}
	printf("sum is %.2f", (float) sum/count);
	return 0;

}
