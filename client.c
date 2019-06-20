
// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#include <stdlib.h> 
#include <signal.h> 

#define PORTSIZE 10
// #define PORT 23423 // Port de consigna
#define PORT 12345 // Port de nuestro server
   
int main(int argc, char const *argv[]) 
{
    int port = PORT; 
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


    // char * ans1 = "entendido\n";
    // send(sock , ans1 , strlen(ans1) , 0 );  
    // sleep(1);
    // char * ans2 = "#0854780*\n";
    // send(sock , ans2 , strlen(ans2) , 0 );  
    // sleep(1);
    // char * ans3 = "nokia\n";
    // send(sock , ans3 , strlen(ans3) , 0 );  
    // sleep(1);
    // char * ans4 = "cabeza de calabaza\n";
    // send(sock , ans4 , strlen(ans4) , 0 );  
    // sleep(1);
    // char * ans5 = "easter_egg\n";
    // send(sock , ans5 , strlen(ans5) , 0 );  
    // sleep(1);
    // char * ans6 = ".runme\n";
    // send(sock , ans6 , strlen(ans6) , 0 );  
    // sleep(1);
    // char * ans7 = "indeterminado\n";
    // send(sock , ans7 , strlen(ans7) , 0 );  
    // sleep(1);
    // char * ans8 = "this is awesome\n";
    // send(sock , ans8 , strlen(ans8) , 0 );  
    // sleep(1);
    // char * ans9 = "cachiporra\n";
    // send(sock , ans9 , strlen(ans9) , 0 );  
    // sleep(1);
    // char * ans10 = "gdb rules\n";
    // send(sock , ans10 , strlen(ans10) , 0 );  
    // sleep(1);
    // char * ans11 = "/lib/x86_64-linux-gnu/ld-2.19.so\n";
    // send(sock , ans11 , strlen(ans11) , 0 );  
    // sleep(1);
    
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
    //cabeza de calabaza
    return 0;
} 



