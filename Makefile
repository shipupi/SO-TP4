all: client myserver wrapper

client: client.c 
	gcc -o client client.c  -I.

myserver: myserver.c 
	gcc -o myserver myserver.c  -I.	

wrapper: wrapper.c
	gcc -o wrapper wrapper.c  -I.	