#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
// Compile with -pthread
#include<pthread.h>
#define MAX_T 1000000

// Sleepy threads :)
void tsleep( void);
void syserr(const char * msg);

int main(void)
{

	char errmsg[64] = {'\0'};
	int i, rc;
	pthread_t threads[MAX_T];

	for( i = 0; i < MAX_T; i++) {
		rc = pthread_create( &threads[i], NULL, (void *)tsleep, NULL);
		sprintf(errmsg, "Unable to create thread id %d!", i);
		if( rc)
			syserr(errmsg);
	}
	exit(0);
}//end main

void tsleep(void)
{
	printf("Going to sleep...\n");
	sleep(1000);
	pthread_exit(NULL);
}

void syserr(const char * msg)
{

	perror(msg);
	exit(0);

}
