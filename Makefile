all: client client2 myserver

client: client.c 
	gcc -o client client.c  -I.

client2: client2.c 
	gcc -o client2 client2.c  -I.

myserver: myserver.c 
	gcc -o myserver myserver.c  -I.	
