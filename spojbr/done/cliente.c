/*
 * cliente.c
 *
 *  Created on: 12/05/2011
 *      Author: aluno
 */
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define BUFFSIZE 32

int main(int argc, char *argv[]) {
	argc = 3;

	int csocket;
	struct sockaddr_in end_servidor;
	char buffer[BUFFSIZE];
	char mensagem[15] = "Ola Mundo";
	unsigned int comprimento;
	int recebido = 0;

	if (argc != 3) {
		fprintf(stderr, "Utilize: Cliente <server_ip> <port>\n");
		exit(1);
	}
	/* Create the TCP socket */
	if ((csocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		perror("Erro na criacao do socket");
		exit(-1);
	}
	/* Construct the server sockaddr_in structure */
	memset(&end_servidor, 0, sizeof(end_servidor)); /* Clear struct */
	end_servidor.sin_family = AF_INET; /* Internet/IP */
	end_servidor.sin_addr.s_addr = inet_addr(argv[1]); /* IP address */
	end_servidor.sin_port = htons(atoi(argv[2])); /* server port */
	/* Establish connection */
	if (connect(csocket, (struct sockaddr *) &end_servidor, sizeof(end_servidor)) < 0) {
		perror("erro no conect");
		exit(-1);
	}

	fprintf(stdout, "\n");
	close(csocket);
	exit(0);
}
