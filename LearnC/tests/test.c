#include<stdlib.h>
#include<stdio.h>
#include<tgmath.h>

int main(void)
{
	int x = 2;
	int y;
	y = floor(2.5);
	printf("y = %d\n", y);

	int z = 1 % 2;
	printf("z = %d\n", z);

	int sz, i = 0;
	char * c;
	char str[] = "Test message";
	sz = sizeof(str);


	for ( c = str; i < sz; c++, i++) {
		printf("Address of C [&c = %p] address contained in C [c = %p] address deferenced [*c = %c]\n", &c, c, * c);
	}

}
