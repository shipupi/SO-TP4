#include <netdb.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 

#include "myserver.h"
#include "serverStrings.h"
#define MAX 80 
#define PORTNUMBER 12345


#define SA struct sockaddr 

// Function designed for chat between client and server. 
void func(int sockfd) 
{ 
    char buff[MAX]; 
    int challenge = 0;
    int length;
    // infinite loop for chat 
    while(1) {
        clearScreen();
        printf("%s", questions[challenge]);
        bzero(buff, MAX); 
  
        // read the message from client and copy it in buffer 
        length = read(sockfd, buff, sizeof(buff)); 
        if(length == 0) {
            // Client was closed
            printf("closing...\n");
            exit(1);
        }

        // Challenge specific functions
        if (challenge == 3)
        {
            ebadf();
        }

        printf("%s\n", buff);
        printf("%s\n", answers[challenge]);
        // print buffer which contains the client contents
        if (strcmp(buff, answers[challenge]) == 0)
        {
            printf("respuesta correcta\n");
            challenge++;
        } else {
            printf("respuesta incorrecta: %s\n", buff);
        }
        sleep(1);
    } 
} 
  
// Driver function 
int main() 
{ 
    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cli; 
  
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
    
    int port = PORTNUMBER;
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(port); 
    // printf("Creating port %d\n", port);
    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
  
    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    len = sizeof(cli); 
  
    // Accept the data packet from client and verification 
    connfd = accept(sockfd, (SA*)&cli, &len); 
    if (connfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    // Function for chatting between client and server 
    func(connfd); 
  
    // After chatting close the socket 
    close(sockfd); 
} 

void clearScreen() {
    printf("\e[1;1H\e[2J");
}


void gdbme() {
    int b = 10;
    if (b == 5) {

        char * a = malloc(1000);
        strcpy(a, " La respuesta es: ");
        strcat(a, answers[10]);
        printf("%s\n", a);
        free(a);
    } else {
        printf("Try again!\n");
    }
    
}

void ebadf() {

    char * a = malloc(1000);
    strcpy(a, " La respuesta es: ");
    strcat(a, answers[3]);
    write(5, a, strlen(a));
    free(a);
}

