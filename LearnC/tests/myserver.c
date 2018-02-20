#include<sys/socket.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#define BUFFSZ 128

/* Only reads from a single connection at a time,
would need to fork() a separate server to continue handling messages
for multiple clients */

void syserr( char * msg)
{
	perror(msg);
	exit(-1);
}//end function

int main( void) 
{
	int listensd, acceptedsd, clientlen;
 	struct sockaddr_in saddr; // Server IP address
	struct sockaddr_in caddr; // Client IP address
	int bytesr, bytesw;

	char clientmsg[BUFFSZ];

	// Create socket to receive/send ( read/write) messages
	// and assign returned file/socket descriptor to listensd
	if(( listensd = socket( AF_INET, SOCK_STREAM, 0)) < 0)
		syserr("Error opening socket\n");
	printf("Socket created\n");

	// Zero out memory space of struct saddr and sendBuff
	memset(&saddr, '0', sizeof(saddr));
	memset(clientmsg, '0', sizeof(clientmsg));
	
	// Initialize struct saddr
	saddr.sin_family = AF_INET; /* address family */
	saddr.sin_addr.s_addr = INADDR_ANY; /* IPv4 address */
	saddr.sin_port = htons(2002); /* port number */

	// Bind listening file/socket descripter to socket struct
	if(( bind( listensd, (struct sockaddr *)&saddr, sizeof(saddr))) < 0)
		syserr("Failed to bind socket\n");
	printf("Binded socket\n");
	
	// listen to file descriptor and accept a maximum of 10 client connections
	listen( listensd, 10);
	printf("Awaiting connection\n");

	// Infinitely accept connections and read/write messages to file/socket descriptor
	while(1) {
		// Accept an incoming connection
		// Create a new fd 
		if( ( acceptedsd =  accept( listensd, (struct sockaddr *)&caddr, &clientlen)) < 0)
			syserr("Unable to accept connection\n");
		printf("Connection accepted\n");

		// Inform client of connection
		write( acceptedsd, "I've received your connection\n", BUFFSZ);

		// Read bytes from connected socket
		bytesr = read( acceptedsd, clientmsg, BUFFSZ);
		if ( bytesr < 0) 
			syserr("Error reading from socket\n");
		printf("Received msg: %s\n", clientmsg);
		// Write bytes to connect socket( IE client)
		bytesw = write(acceptedsd, "Received your msg\n", 19);
		if ( bytesw < 0) 
			syserr("ERROR writing message to socket");
	}//end while

	exit(0);
	
}//end main
