#ifndef SERVERSTRINGS_H
#define SERVERSTRINGS_H

static const char *answers[] = {\
	"entendido\n",
	"#0854780*\n",
	"hola\n",
	"cabeza de calabaza\n",
	"easter_egg\n",
	".runme\n",
	"indeterminado\n",
	"this is awesome\n",
	"cachiporra\n",
	"gdb rules\n",
	"/lib/x86_64-linux-gnu/ld-2.19.so\n"
};

static const char *questions[] = {\
	"------------- DESAFIO -------------\n \
Bienvenidos al TP4 y felicitaciones, ya resolvieron el primer acertijo. \n\
En este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.\n\
Además tendrán que investigar otras preguntas para responder durante la defensa.\n\
El desafío final consiste en crear un servidor que se comporte igual que yo, además del cliente para comunicarse con el mismo.\n\
Deberán estar atentos a los desafios ocultos.\n\
Para verificar que sus respuestas tienen el formato correcto respondan a este desafío con \"entendido\\n\"\n\
\n----- PREGUNTA PARA INVESTIGAR -----\n\
¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?\n\n\
(nosotros usamos el programa lsof)\n\n",
	"------------- DESAFIO -------------\n# \033[D \033[A \033[A \033[D \033[B \033[C \033[B \033[D *\n\n----- PREGUNTA PARA INVESTIGAR -----\n¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?\n",
	"------------- DESAFIO -------------\n.... --- .-.. .-\n\n----- PREGUNTA PARA INVESTIGAR -----\n¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?\n",
	"------------- DESAFIO -------------\nEBADF... abrilo y verás\n\n----- PREGUNTA PARA INVESTIGAR -----\n¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?\n",
	"------------- DESAFIO -------------\nrespuesta = strings[224]\n\n----- PREGUNTA PARA INVESTIGAR -----\n¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?\n",
	"Pregunta 5\n",
	"Pregunta 6\n",
	"Pregunta 7\n",
	"Pregunta 8\n",
	"Pregunta 9\n",
	"Pregunta 10\n",
	"Pregunta 11\n"
};

#endif


