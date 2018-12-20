#include "pipe_networking.h"

	int PIPING = 0;

void sighandler(int signo){
	remove(PIPE_SERVER);
	exit(0);
}

void sighand2(int signo){
	PIPING = 1;
}

int main() {


  int *to_client;
  int from_client;
  while(1){signal(SIGINT,sighandler);
  to_client = malloc(sizeof(int));
  from_client = server_handshake( to_client );
  
  	while(1){

		char * b1;
		char * b2;

		b1 = malloc(BUFFER_SIZE);
		//printf("wow4\n");
		b2 = malloc(BUFFER_SIZE);
		printf("[server] waiting for client\n");
		read(from_client,b1,BUFFER_SIZE);		  		signal(SIGPIPE,sighand2);
  		if(PIPING){
  			break;
  		}
		printf("%s\n",b1);

		sprintf(b2,"size of the input: %d",strlen(b1));
		printf("[server] send info to client\n");
		write(*to_client,b2,BUFFER_SIZE);
		free(b1);
		free(b2);

	}
	PIPING = 0;
	close(*to_client);
	close(from_client);
	free(to_client);
	printf("[server] re-establishing pipe\n");
	}
	printf("helo!\n");
	return 0;
}
