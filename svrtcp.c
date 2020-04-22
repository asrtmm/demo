#include "svrtcp.h"



int cearte_sock(int *sockfd, int port)
{
	int fd;
	struct sockaddr_in server_sockaddr;
	if((fd=socket(AF_INET,SOCK_STREAM,0)==-1)){
		perror("socket");
		return -1;
	}
	if(listen(fd,20)==-1){
		perror("listen");
		return -1;
	}
	server_sockaddr.sin_family=AF_INET;
	server_sockaddr.sin_port=htons(port);
	server_sockaddr.sin_addr.s_addr=INADDR_ANY;
	bzero(server_sockaddr.sin_zero,8);
	
	if(bind(fd,(struct sockaddr_in *)&server_sockaddr,sizeof(struct sockaddr))==-1){
		perror("bind");
		return -1;
	}

	if(listen(fd,10)==-1){
		perror("listen");
		return -1;
	}
	*sockfd = fd;
	return 0;
}

int tcprecv(int fd,int *client_fd, (struct sockaddr_in *) client_sockaddr, char *buf, long *size)
{
	int client_fd, sin_size, recv_size=0,recvbyte;
	int max_recv_size;
	max_recv_size = *size > MAXDATASIZE ? *size:MAXDATASIZE;
	if(*client_fd == NULL){
		if((client_fd=accept(fd,(struct sockaddr *)&client_sockaddr),&sin_size)==-1){
			perror("accept");
			return -1;
		}	
	}

	while(recv_size<*size){
		if((recvbyte=recv(client_fd,buf+recv_size,max_recv_size)==-1)){
			perror("recv");
			return -1;
		}
		recv_size+=recvbyte;
	}


}
