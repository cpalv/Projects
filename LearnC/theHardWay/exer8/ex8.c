#include<stdio.h>

int main (int argc, char*argv[]) {

	int i = 0;

	if( argc == 1 ) {
		printf("You only have one argument. You suck!\n");
	} else if ( argc > 1 && argc < 4 ) {
		printf("Here are your args\n");
//	Omits program name from printed output
		for( i = 1; i < argc; i++) {
			printf("%s ", argv[i]);
		}
//	Prints all arguments in argv
//		for( i = 0; i < argc; i++) {
//			printf("%s ", argv[i]);
//		}
		printf("\n");
	} else {
		printf("DAFUQ is wrong with you! You have too many args!\n");
	}

	return 0;
}
