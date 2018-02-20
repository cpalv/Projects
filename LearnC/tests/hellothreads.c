#include<stdio.h>
#include<stdlib.h>	// atoi function
#include<pthread.h>	// pthread functions

void * PrintHello( void * threadid)
{
	long tid;
	tid = ( long ) threadid;
	printf("Hello, world! My thread id is: %ld\n", tid);
	pthread_exit(NULL);
}// end function

int main( int argc, char * argv[])
{
	pthread_t * threads;
	int rc;		// return code
	int numt;	// number of threads 
	long t;

	if( argc != 2){
		fprintf(stderr,"HOLY FUCK! Need at least two args!\n");
		fprintf(stderr,"Usage: %s <number of desired threads>\n", argv[0]);
		exit(-1);
	}//end if
	
	numt = atoi(argv[1]);	// convert string to int
	threads = malloc(numt*sizeof(pthread_t));
	
	for( t = 0; t < numt; t++){
		printf("I'm main, creating thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, ( void *)t);
		if(rc){
			fprintf(stderr,"ERROR: return code from pthread_create() is: %d\n", rc);
			exit(-1);
		}//end if
	}//end for

	/* Free data*/
	free(threads);
	/* Last thing main should do*/
	pthread_exit(NULL);
}//end main
