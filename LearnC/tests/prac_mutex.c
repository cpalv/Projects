#include<stdlib.h>
#include<stdio.h>
#include<string.h> // strerror() - returns pointer to string describing error number :)
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
/* compile with -pthread :) */
#include<pthread.h>
// TIME for fun, HA! get it? ;)
#include<sys/time.h>

/*
 * A practical mutex example
 * you'll notice that without mutex we will most
 * likely never see "both" jobs complete
 *
 * Uncomment code related to mutex and you'll see a difference
 * mutex will lock variables from being accessed by other 
 * sections of code/functions attempting to access this region
 */

/* Some global variables for threads to play with */
pthread_t tid[2];
int counter;
// Our mutex lock :)
pthread_mutex_t lock;

void* do_things( void *arg)
{
	// lock the global variables this thread
	// is currently working with from being
	// accessed by other threads
	pthread_mutex_lock(&lock);

	unsigned long t = 0;
	counter += 1;

	printf("Job %d started\n", counter);

	for(t=0; t < (0xFFFFFFFF); t++);

	printf("Job %d finished\n", counter);

	// free the global variables :)
	pthread_mutex_unlock(&lock);

	//pthread_exit(NULL);
	return NULL;
}//end funct

int main(void)
{
	int i = 0, rc;
	unsigned long j;
	struct timeval s_time, e_time;
	pid_t pid;

	// initialize mutexing
	if( pthread_mutex_init(&lock, NULL) != 0) {
		fprintf(stderr, "Mutex init failed\n");
	}//end if

	gettimeofday(&s_time, NULL);
	while( i < 2 ) {
		rc = pthread_create( &(tid[i]), NULL, &do_things, NULL);
		if( rc != 0 )
			fprintf(stderr, "Unable to create thread : [ %s ]", strerror(rc));
		i++;
	}//end while

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	gettimeofday(&e_time, NULL);
	// One day I'll remember how to spell destory :)
	pthread_mutex_destroy(&lock);
	
	printf("\nThread stats:\n");
	printf("s_time.tv_sec = %ld\ts_time.tv_usec = %ld\n", s_time.tv_sec, s_time.tv_usec);
	printf("e_time.tv_sec = %ld\te_time.tv_usec = %ld\n", e_time.tv_sec, e_time.tv_usec);
	printf("Time delta = %d s\n\n", (e_time.tv_sec - s_time.tv_sec));

	// Zero structs and restart!
	memset( &s_time, 0, sizeof(struct timeval));
	memset( &e_time, 0, sizeof(struct timeval));

	gettimeofday(&s_time, NULL);
	switch( pid = fork()){
		case -1:
			perror("Bad fork");
			break;
		case 0://child
			break;
		default://parent
			break;
	}//end switch

	if( pid ) {
		printf("I am the parent! PID [ %ld ]\n", getpid());
		for(j=0; j < (0xFFFFFFFF); j++);
		printf("Parent done!\n");
	} else {
		printf("I am the child! PID [ %ld ]\n", getpid());
		for(j=0; j < (0xFFFFFFFF); j++);
		printf("Child exiting!\n");
		exit(0);
	}//end if

	// wait for child to finish and get time :)
	waitpid(pid, NULL, 0);
	gettimeofday(&e_time, NULL);

	printf("\nProcess stats:\n");
	printf("s_time.tv_sec = %ld\ts_time.tv_usec = %ld\n", s_time.tv_sec, s_time.tv_usec);
	printf("e_time.tv_sec = %ld\te_time.tv_usec = %ld\n", e_time.tv_sec, e_time.tv_usec);
	printf("Time delta = %d s\n\n", (e_time.tv_sec - s_time.tv_sec));
	printf("Parent exiting :)... Good bye cruel world!\n");

	exit(0);	
}//end main

/*
 * OBSERVATIONS:
 * after adding the mutex code,
 * each job completes individually
 * it feels a bit like forking a subprocess??
 *
 * I wonder which would be faster???
 * Since a thread is waiting on completion of 
 * another threads task, seems like we're hitting some 
 * "stall" cycles ;)
 *
 * Undoubtly there would be more overhead forking an additional child?


	main() -----------------------------------------thread_join()-------------->
				|									^
				|									|
				thread()~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


 * Run the program and check the stats :)
 * So far ( ie, without extensive testing ) it appears
 * that forking a child is faster than having two threads work with the same variable
 *
 $ man 2 fork
 NOTES
        Under  Linux,  fork()  is implemented using copy-on-write pages, so the only penalty that it incurs is
       the time and memory required to duplicate the parent's page tables,
	   and to create a unique task structure for the child.

 * However, thinking about it a bit more
 * since, both process aren't actually working on the SAME variable and instead 
 * both have copies of their own variable ( 4:20!) 


	main() ------------------------------------------------------->
				|
				|
				fork()~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>


 * Cannot currently think of a situation where mutex threads would be better than process
 * the trade offs are apparent
 * 
 * I guess the only thing I can really think of is thread goes and does work
 * and updates a variable ( counter? ) maybe and an another thread goes and does other work
 * and then updates the same variable.  Another simple program idea? ;)
 *
 * The above wouldn't be possible necessarily with forked processes since there 
 * would be tandum variables and I do not think two process could grab each others data
 * 
 * At least, not in usrland ;;)
 */
