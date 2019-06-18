
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <signal.h>
#include <sys/shm.h>          /* For share memory*/

int main (int argc, char *argv[]){


	int pip[2];
	pipe(pip);

	int id;

	id = fork();

	 if (id == -1) {
      perror("Error en fork");
      exit(EXIT_FAILURE);
    } else if (id == 0) {
    	// Soy el hijo


      dup2(pip[1], 5);
	  char *args[2];
      args[0] = "";
      args[1] = NULL;
      execv("./server", args);

      perror("Error en exec");
      exit(EXIT_FAILURE);
    }


    // Soy el padre

    printf("Waiting for children...\n");

    char * buffer = malloc(512);
    while(1) {
	    read(pip[0], buffer, 512);
	    printf("Llego algo al pipe 5: \n-------------------\n%s\n-------------------\n", buffer);
    }

}