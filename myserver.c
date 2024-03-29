#include <time.h>
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
    while(challenge < 11) {
        clearScreen();
        printf("%s", questions[challenge]);
        bzero(buff, MAX); 
    
        // Challenge specific functions
        if (challenge == 3)
        {
            ebadf();
        } else if (challenge == 6) {
            mixedFds();
        } else if (challenge == 8) {
            quine();
        } else if (challenge == 9) {
            gdbme();
        }


        printf("%s", investigar[challenge]);
        // read the message from client and copy it in buffer 
        length = read(sockfd, buff, sizeof(buff)); 
        if(length == 0) {
            // Client was closed
            printf("closing...\n");
            exit(1);
        }

        


        //printf("%s\n", buff);
        //printf("%s\n", answers[challenge]);
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
    if(0){
        _start(); 
    }
    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cli; 
  
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        // printf("socket creation failed...\n"); 
        exit(0); 
    } 
    // else
        // printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
    
    int port = PORTNUMBER;
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(port); 
    // printf("Creating port %d\n", port);
    // Binding newly created socket to given IP and verification 
    int one = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one));
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        // printf("socket bind failed...\n"); 
        exit(0); 
    } 
    // else
        // printf("Socket successfully binded..\n"); 
  
    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { 
        // printf("Listen failed...\n"); 
        exit(0); 
    } 
    // else
        // printf("Server listening..\n"); 
    len = sizeof(cli); 
  
    // Accept the data packet from client and verification 
    connfd = accept(sockfd, (SA*)&cli, &len); 
    if (connfd < 0) { 
        // printf("server acccept failed...\n"); 
        exit(0); 
    } 
    // Function for chatting between client and server 
    func(connfd); 
  
    // After chatting close the socket 
    close(sockfd); 
    printf("Resolviste todos los acertijos :) \n");
}

void clearScreen() {
    printf("\e[1;1H\e[2J");
}

void quine() {
    // http://www.cplusplus.com/reference/cstdlib/system/
    int i;
    // printf ("Checking if processor is available...");
    if (system(NULL)) puts ("Ok");
    else exit (EXIT_FAILURE);
    // printf ("Executing command DIR...\n");
    i=system ("gcc -o quine quine.c ");
    // printf("The return value was: %d\n", i);

    if(i != 0) {
        return;
    }
    
    printf("¡Genial!, ya lograron meter un programa en quine.c, veamos si hace lo que corresponde:\n");
    i=system ("./quine | diff quine.c -");
    if (i == 0)
    {
        char * a = malloc(1000);
        strcpy(a, "¡Genial! la respuesta a este acertijo es ");
        strcat(a, answers[8]);
        printf("%s\n", a);
        free(a);

    } else {
        printf("diff returned: %d\n", i);
    }
}

void gdbme() {
    int b = 10;
    if (b == 5) {
        char * a = malloc(1000);
        strcpy(a, "La respuesta es: ");
        strcat(a, answers[9]);
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

void mixedFds() {
    srand(time(NULL));
    const char * words[] = {"la", "respuesta", "es", answers[6]};
    int i,j,k;
    for (i = 0; i < 4; ++i)
    {
        int l = strlen(words[i]);
        for (j = 0; j < l; ++j)
        {
            int amount = rand() % 4 + 1;
            for (k = 0; k < amount; ++k)
            {
                int rdChar = rand() % 26;
                fprintf(stderr,"%c", rdChar + 'a');
                fflush(stderr);
            }
            fprintf(stdout, "%c", words[i][j]);
            amount = rand() % 4 + 1;
            fflush(stdout);
            for (k = 0; k < amount; ++k)
            {
                int rdChar = rand() % 26;
                fprintf(stderr, "%c", rdChar + 'a');
                fflush(stderr);
            }
        }
        fprintf(stdout, " ");
        fflush(stdout);
    }

    printf("\n");
}