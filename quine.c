#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main (int argc, char *argv[]){
	int fd = open("./quine.c", O_RDONLY);
	char buf[1024];
	int buflen;
	while((buflen = read(fd, buf, 1024)) > 0)
	{
	    write(1, buf, buflen);
	}
	close(fd);
}