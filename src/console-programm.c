
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int row = 0;
	for (int i = 0; i <= row; i++) {
		if (i == row) {
			printf("*\n");
			i = 0;
			row++;
		}
		if (row >10) break;
		printf("*");
	}
	int row2 = 12;
	for (int i = 11; i >= 1; i--) {
		if (i <= 1) {
			i = --row2;
			printf("*\n");
		} else printf("*");
	}
	return 0;
}
