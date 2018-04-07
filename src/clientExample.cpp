/*
 * Author: Jose Simo (2016)
 * Universitat Politecnica de Valencia. AI2-DISCA
 * Creative Commons.
 *
 * TCP client socket example
 * The port number can be passed as a command line argument 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(const char *msg) {perror(msg); exit(0);}

int main(int argc, char *argv[])
{
    int sockfd; 
    int portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    int n, retval;
    
    //Retrieve the server host and port from the command line or use default values.
    if (argc >= 3) {    
        server = gethostbyname(argv[1]);	
		portno = atoi(argv[2]);
    }
    if (argc == 2) {
        server = gethostbyname(argv[1]);	
		portno = 30002;
		fprintf(stdout,"Usage %s hostname port\n", argv[0]);
		fprintf(stdout,"Using default port (30002)\n");
    } 
    if (argc <= 1) {
        server = gethostbyname("192.168.0.103");	
		portno = 30002;
		fprintf(stdout,"Usage %s hostname port\n", argv[0]);
		fprintf(stdout,"Using default host (localhost)\n");
		fprintf(stdout,"Using default port (30002)\n");
    }
    //Check for a valid server host value.
    if (server == NULL) error("ERROR, no such host");
    //Create a socket (Internet domain ipv4, stream-oriented, TCP protocol)
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) error("ERROR opening socket");
    //Prepare the server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    //Connect to the server
    retval = connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr));
    if (retval < 0) error("ERROR connecting");
    //Connection established!
    //Now we can transfer data from/to the server
    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) error("ERROR writing to socket");
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) error("ERROR reading from socket");
    printf("%s\n",buffer);
    //Close communication
    close(sockfd);
    return 0;
}