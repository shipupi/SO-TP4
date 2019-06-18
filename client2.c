
// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#include <stdlib.h> 
#include <signal.h> 

#define PORTSIZE 10

   
int main(int argc, char const *argv[]) 
{
    int port = atoi(argv[1]); 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    
    char buffer[1024] = {0}; 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(port); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not sarribaported \n"); 
        return -1; 
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 
    char string[100];
    while(1) {
        sleep(2);
        memset(string,0,100);
        printf("Enter response:\n");
        // printf("read: %s\n", string);
        gets(string);
        string[strlen(string)] = '\n';
        // printf("%s\n", string);
        send(sock , string , strlen(string) , 0 ); 
        // valread = read( sock , buffer, 1024); 
        // printf("%s\n", buffer);
    }


    // valread = read( sock , buffer, 1024); 
    // printf("%s\n",buffer ); 

    //entendido
    //#0854780*
    //nokia
    return 0;
} 



