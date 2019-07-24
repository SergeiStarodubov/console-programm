
#include <stdio.h>
#include <stdlib.h>

void useLocal(void);
void useStaticLocal(void);
void useGlobal(void);
int x = 5;
int main(void) {

	useGlobal();
	useGlobal();
	return 0;
}

void useLocal(void) {
	int x = 200;
	printf("%d", x);
	x++;
}

void useStaticLocal(void) {
	static int x = 300;
	printf("%d", x);
	x++;
}

void useGlobal(void) {
	x += 10;
	printf("%d", x);
}
