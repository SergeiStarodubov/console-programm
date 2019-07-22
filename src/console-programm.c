
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num;
	int sum = 0;

	printf("input number: ");
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		int tmp;
		scanf("%d", &tmp);
		sum+= tmp;
	}
	printf("sum is %d", sum);
	return 0;
}
