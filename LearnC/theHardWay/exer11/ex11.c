#include<stdio.h>

int main(int argc, char *argv[]) 
{
	int numbers[4] = { 0 };
	char name[4] = { 'a' };

	// Print out the contents of the raw arrays
	printf("elements in numbers[] array: %d %d %d %d\n",
			numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("elements in name[] array: %c %c %c %c\n",
			name[0], name[1], name[2], name[3]);

	// Print out the char array name[] as a string
	printf("name[] array as a string: %s\n", name);

	// Initialize each index in numbers[] array
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;
}
