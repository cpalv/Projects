#include<stdlib.h>
#include<stdio.h>

char * rw(char str[]);

int main(void)
{

	int i, sz;
	char str[] = "This is a str with text";
	char * c = str;

	sz = sizeof(str);

	printf("* c is located at [ %p ]\n", &c);
	printf("and contains address [ %p ] which is %c\n", c, *c);
	printf("[");
	for( c = str; i < sz; c++, i++) {
		printf("%c",*c);
	}	
	printf("]\n");
	printf("c currently contains address [ %p ]\n", c);
	c = rw(str);
	printf("c now contains address [ %p ]\n", c);
	printf("* c is %c?\n", *c);

}

char * rw(char str[]) {
	char * c = str;
	return &(*c);
}
	
