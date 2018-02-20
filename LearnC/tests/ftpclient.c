#include<sys/socket.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h> // inet_pton, htons

#define BUFFSZ 128
#define IP_ADDR "63.145.117.26"

void syserr( char * msg)
{
	perror(msg);
	exit(-1);
}//End function

int main ( void)
{
	int sfd; // Socket file descriptor
	struct sockaddr_in saddr;
	int bytesr, bytesw;

	char recvMsg[BUFFSZ];
	char sendMsg[BUFFSZ];

	// Create socket file descriptor
	if(( sfd = socket( AF_INET, SOCK_STREAM, 0)) < 0)
		syserr("Error creating socket\n");
	printf("Socket created\n");

	// Zero out memory
	memset(&saddr, 0, sizeof(saddr));
	memset(recvMsg, 0, sizeof(recvMsg));

	// Initialize struct socket address
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(21);
	// inet_pton converts string to in_addr struct
	if( inet_pton(AF_INET, IP_ADDR, &saddr.sin_addr) <= 0)
		syserr("inet_pton error occured\n");

	// Connect to socket descripter with socket address
	if( connect( sfd, ( struct sockaddr *)&saddr, sizeof(saddr)) < 0)
		syserr("Failed to connect\n");
	printf("Connected to server\n");

	// Read/write messages from/to socket descriptor
	while( ( bytesr = read(sfd, recvMsg, BUFFSZ)) > 0) {
		printf("Received message: %s\n", recvMsg);
		read(STDIN_FILENO, sendMsg, BUFFSZ);
		write(sfd, sendMsg, BUFFSZ);
	}//End while

	if ( bytesr < 0)
		syserr("Read error\n");
	
	exit(0);
}//End main
