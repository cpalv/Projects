#include<stdlib.h>
#include<stdio.h>

int main( void) {
	int t = 1;

	printf("T = %d\n", t);
	if(t)
		printf("True\n");
	else
		printf("False\n");

	t = 0;
	printf("T = %d\n", t);
	if(t)
		printf("True\n");
	else
		printf("False\n");
	
	t = -1;
	printf("T = %d\n", t);
	if(t)
		printf("True\n");
	else
		printf("False\n");

	exit(0);
}//End main
