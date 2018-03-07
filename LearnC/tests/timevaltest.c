#include<stdlib.h>
#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>

int main(void)
{

	struct timeval s_time, r_time;
	int i = 0;

	gettimeofday(&s_time, NULL);
	for( i = 0; i < 10; i++) {
		printf("Start Microseconds = %ld\n", s_time.tv_usec);
		sleep(1);
	}//end for
	gettimeofday(&r_time, NULL);
	printf("End Microseconds = %ld\n", r_time.tv_usec);

	exit(0);

}//end main
