#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	
	printf("Size of int = %d bytes\n", sizeof(int));
	printf("Size of char = %d bytes\n", sizeof(char));
	int * iptr;
	char * chptr;
	printf("Size of ( int *) = %d bytes\n", sizeof(iptr));
	printf("Size of ( char *) = %d bytes\n", sizeof(chptr));

	exit(0);
}//end main
