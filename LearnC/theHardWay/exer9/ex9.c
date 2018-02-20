#include<stdio.h>

int main ( int argc, char *argv[])
{
	int i = 0;
	printf("Increment Loop\n");
	while (i < 25) {
		printf("%d ", i);
		i++;
	}
	printf("\n");
	// Extra Credit
	// Make While loop count backwards from 25 using j--
	int j = 25;
	printf("Decrement Loop\n");
	while( j > 0) {
		printf("%d ", j);
		j--;
	}
	printf("\n");
	return 0;
}
