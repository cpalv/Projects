#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main (int argc, char *argv[]) {

	int fd, fdp[2];
	struct test {
		int num1;
		int num2;
		int num3;
	}t1;
	struct test t2 = { 1, 2, 3};


	printf("From a File\n");
	fd = open("intest", O_RDWR | O_CREAT, 0600);
	write(fd, &t2, sizeof(t2));
	read(fd, &t1, sizeof(t1));
	close(fd);
	printf("num1: %d\nnum2: %d\nnum3: %d\n", t1.num1, t1.num2, t1.num3); 

	printf("From a Pipe\n");
	pipe(fdp);
	write(fdp[1], &t2, sizeof(t2));
	close(fdp[1]);
	read(fdp[0], &t1, sizeof(t1));
	close(fdp[0]);
	printf("num1: %d\nnum2: %d\nnum3: %d\n", t1.num1, t1.num2, t1.num3); 
}//end main
