#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/socket.h>

a


#define BUFFER_SIZE 256


int cree_socket_tcp_client(int argc,
char** argv)
{
struct sockaddr_in adresse;
int sock;
if (argc != 3)
{
fprintf(stderr, "Usage : %s adresse port\n",
argv[0]);
exit(0);
}
if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
{
fprintf(stderr, "Erreur socket\n");
return -1;
}
memset(&adresse, 0, sizeof(struct sockaddr_in));
adresse.sin_family = AF_INET;
adresse.sin_port = htons(atoi(argv[2]));
inet_aton(argv[1], &adresse.sin_addr);
if (connect(sock, (struct sockaddr*) &adresse,
sizeof(struct sockaddr_in)) < 0)
{
close(sock);
fprintf(stderr, "Erreur connect\n");
return -1;
}
return sock;
}

int main(int argc , char **argv){

char message[100];
char message2[100];
int sock_client;

sock_client = cree_socket_tcp_client(int argc, char** argv);
while(1){
scanf("%s",&message); 
write(stock_client, &message ,100*sizeof char);

read(stock_client, &message2 , 100*sizeof char);
printf ("%s", &message2);

}	
	
			
}