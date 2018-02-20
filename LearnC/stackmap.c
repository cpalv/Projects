#include<stdio.h>

unsigned long long *get_rbp() {
	asm("mov %rsp, %rax");
}//end funct

unsigned long long *get_rsp() {
	asm("mov %rbp, %rax");
}//end funct

int main(void)
{

	unsigned long long * main_rbp = 0, * main_rsp = 0;
	int i = 0;

	printf("x86-64 Stack\n");
	printf("+---------------+\n");
	for( i = 0; i < 5; i++)
		printf("|\t\t|\n");
	main_rbp = get_rbp();
	printf("%p\n", main_rbp);
	main_rsp = get_rsp();
	printf("%p\n", main_rsp);
	printf("%p\n", &i);
}//end main
