#ifndef SERVERSTRINGS_H
#define SERVERSTRINGS_H

static const char *answers[] = {\
	"entendido\n",
	"#0854780*\n",
	"hola\n",
	"cabeza de calabaza\n",
	"main\n",
	".plt\n",
	"indeterminado\n",
	"this is awesome\n",
	"cachiporra\n",
	"gdb rules\n",
	"/lib/x86_64-linux-gnu/ld-2.19.so\n"
};

static const char *questions[] = {
	"------------- DESAFIO -------------\nBienvenidos al TP4 y felicitaciones, ya resolvieron el primer acertijo. \nEn este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.\nAdemás tendrán que investigar otras preguntas para responder durante la defensa.\nEl desafío final consiste en crear un servidor que se comporte igual que yo, además del cliente para comunicarse con el mismo.\nDeberán estar atentos a los desafios ocultos.\nPara verificar que sus respuestas tienen el formato correcto respondan a este desafío con \"entendido\\n\"\n\n",
	"------------- DESAFIO -------------\n# \\033[D \\033[A \\033[A \\033[D \\033[B \\033[C \\033[B \\033[D *\n\n",
	"------------- DESAFIO -------------\n.... --- .-.. .-\n\n",
	"------------- DESAFIO -------------\nEBADF... abrilo y verás\n\n",
	"------------- DESAFIO -------------\nrespuesta = strings[224]\n\n",
	"------------- DESAFIO -------------\n.rela.dyn .rela.plt .init ? .text .fini\n\n",
	"------------- DESAFIO -------------\nmixed fds\n",
	"------------- DESAFIO -------------\nTango Hotel India Sierra India Sierra Alfa Whiskey Echo Sierra Oscar Mike Echo\n\n",
	"------------- DESAFIO -------------\nquine\n",
	"------------- DESAFIO -------------\nb gdbme y encontrá el valor mágico\n\n",
	"------------- DESAFIO -------------\n/lib/x86_64-linux-gnu/libc-2.19.so ?\n\n"
};

static const char *investigar[] = {
	"----- PREGUNTA PARA INVESTIGAR -----\n¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?\n\n(nosotros usamos el programa lsof)\n\n",
	"----- PREGUNTA PARA INVESTIGAR -----\n¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?\n",
	"----- PREGUNTA PARA INVESTIGAR -----\n¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?\n",
	"----- PREGUNTA PARA INVESTIGAR -----\n¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?\n",
	"----- PREGUNTA PARA INVESTIGAR -----\n¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?\n",
	"----- PREGUNTA PARA INVESTIGAR -----\nUn servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes. ¿Qué conviene más?\n",
	"----- PREGUNTA PARA INVESTIGAR -----\n¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?\n",
	"----- PREGUNTA PARA INVESTIGAR -----\n¿Qué aplicaciones se pueden utilizar para ver el tráfico por la red?\n",
	"----- PREGUNTA PARA INVESTIGAR -----\nsockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y pipes?\n",
	"----- PREGUNTA PARA INVESTIGAR -----\n¿Cuáles son las características del protocolo SCTP?\n",
	"----- PREGUNTA PARA INVESTIGAR -----\n¿Qué es un RFC?\n"
};

#endif


