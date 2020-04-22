#include "server.h"





int main()
{
	int sockfd;


	if((sockfd=socket(AF_INET,SOCK_STREAM,0)==-1)){
		perror("socket");
		return -1;
	}
}
