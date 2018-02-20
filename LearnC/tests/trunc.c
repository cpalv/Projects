#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(void) {
	int fdin, trunc;
	
	fdin = open("1", O_RDWR, 0600);
	fprintf(stdout,"size of fdin in bytes: %d\n", fdin);
	trunc = ftruncate(fdin, 10);
	fprintf(stdout,"size of fdin after truncate: %d\n", trunc);

	exit(0);

}//
