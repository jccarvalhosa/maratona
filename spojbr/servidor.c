/*
 * server.c
 *
 *  Created on: 12/05/2011
 *      Author: aluno
 */
#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
//#include <string.h>
//#include <netinet/in.h>

#define NRCON 5    /* Numero de conexoes */
#define BUFFSIZE 32
#define PORTA 5001

int main(void) {
	int ssocket, csocket;
	struct sockaddr_in end_servidor, end_cliente;

	if ((ssocket = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
		perror("Erro criação socket");
		exit(-1);
	}

	/* Construct the server sockaddr_in structure */
	memset(&end_servidor, 0, sizeof(end_servidor)); /* Clear struct */
	end_servidor.sin_family = AF_INET; /* Internet/IP */
	end_servidor.sin_addr.s_addr = htonl(INADDR_ANY); /* Incoming addr */
//	end_servidor.sin_port = htons("5001"); /* server port */
	end_servidor.sin_port = htons(PORTA); /* server port */
	/* Bind the server socket */
	if (bind(ssocket, (struct sockaddr *) &end_servidor, sizeof(end_servidor))
			< 0) {
		perror("erro bind");
		exit(-1);
	}

	/* Listen on the server socket */
	if (listen(ssocket, NRCON) < 0) {
		perror("erro listen");
		exit(-1);
	}
	/* Run until cancelled */
	while (1) {
		unsigned int clientlen = sizeof(end_cliente);
		/* Wait for client connection */
		if ((csocket = accept(ssocket, (struct sockaddr *) &end_cliente,
				&clientlen)) < 0) {
			perror("erro accept");
			exit(-1);
		}
		fprintf(stdout, "Cliente conectado: %s\n",
				inet_ntoa(end_cliente.sin_addr));
	}
	close(ssocket);

	exit(0);
}
