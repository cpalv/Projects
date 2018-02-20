#include<stdio.h>

int main(int argc, char *argv[]) 
{
	int i = 0;

	// go through each string in argv
	// We skip argv[0] because we dgaf about the prog name
	// ARGC is the ARGUMENT COUNTER, 
	// Counts total number of arguments on cmd line
	printf("argc: %d\n", argc);
	for( i = 1; i < argc; i++) {
		printf("argv[%d]: %s\n", i, argv[i]);
	}

	// Let's make our own array of strings
	char *states[] = { "California", "Oregon", "Washington", "Texas"};
	int num_states = 4;

	for( i = 0; i < num_states; i++) {
		printf("state[%d]: %s\n", i, states[i]);
	}
	return 0;
}
