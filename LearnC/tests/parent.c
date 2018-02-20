#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main ( void) {
	int i, myid = 0;
	pid_t parent, mypid;

	for( i = 1; i < 9; i++) {
		switch( parent = fork()) {
			case -1:
				perror("F err\n");
				exit(-1);
			case 0:
				myid = i;
				break;
			default:
				break;
			}//End switch
		if(parent)
			break;
	}//End for
	mypid = getpid();
	if( parent)
		printf("I am a parent myid: %d mypid: %ld\n", myid, mypid);
	else
		printf("I am a child myid: %d mypid: %ld\n", myid, mypid);

	exit(0);
}//End main
