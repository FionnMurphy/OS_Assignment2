#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]){
	int p[3][2];
	for(int i = 0; i < 3; i++){
		pipe(p[i]);
	}
	char message = 'a';

	if(fork() == 0){
		for(int i = 0; i < 2; i++){
			char recv_msg;
			read(p[0][0], &recv_msg, 1);
			printf("received message: '%c' \n", recv_msg);
			recv_msg = recv_msg + 1;
			write(p[1][1], &recv_msg, 1);
		}
		exit(0);
	}
	if(fork() == 0){
		for(int i = 0; i < 2; i++){
			char recv_msg;
			read(p[1][0], &recv_msg, 1);
			printf("received message: '%c' \n", recv_msg);
			recv_msg = recv_msg + 1;
			write(p[2][1], &recv_msg, 1);
		}
		exit(0);
	}

	write(p[0][1], &message, 1);
	
	for(int i = 0; i < 2; i++){
		char recv_msg;
		read(p[2][0], &recv_msg, 1);
		printf("received message: '%c' \n", recv_msg);
		recv_msg = recv_msg + 1;	
		write(p[0][1], &recv_msg, 1);
	}
	printf("Done\n");
	return 0;
}
