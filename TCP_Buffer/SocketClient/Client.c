/*
This is for the project IERG3310

*/
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 87380


int main()
{
    printf("Hello this is client\n");
    int server_fd,client_fd,client_fd2,recevived,bytes = 0,k=0;
    char send_buffer[1000],recv_buffer[1000];

    bzero(send_buffer,sizeof(send_buffer));
    bzero(recv_buffer,sizeof(recv_buffer));

    struct hostent *host;
    struct sockaddr_in server,client,client2;

    host = gethostbyname("127.0.0.1");

    client_fd = socket(AF_INET,SOCK_STREAM,0);

    client.sin_family = AF_INET;
    client.sin_port = htons(3310);
    client.sin_addr = *((struct in_addr *)host->h_addr);

    int size_buffer=0;

    int size_int = sizeof(int);

    printf("size of buffer of SOL_SOCKET,%d\n",size_buffer);

    connect(client_fd,(struct sockaddr *)&client,sizeof(struct sockaddr));

    char * StudentID = "1155018369";
	sprintf(send_buffer,"%s",StudentID);
    send(client_fd,send_buffer,strlen(send_buffer),0);

    recv(client_fd,recv_buffer,1000,0);
    puts(recv_buffer);

    int Server_Port = atoi(recv_buffer);
	unsigned int sin_size = sizeof(struct sockaddr_in);

    server_fd = socket(AF_INET,SOCK_STREAM,0);
    server.sin_family = AF_INET;
    server.sin_port = htons(Server_Port);
    server.sin_addr.s_addr = INADDR_ANY;
    bind(server_fd,(struct sockaddr *)&server,sizeof(struct sockaddr));
    printf("Open Port on %d\n",Server_Port);

    getsockopt(server_fd,SOL_SOCKET,SO_RCVBUF,&size_buffer,(socklen_t *)&size_int);
    size_buffer = BUFFER_SIZE*0.5;
    setsockopt(server_fd,SOL_SOCKET,SO_RCVBUF,(const void *)&size_buffer,size_int);
    getsockopt(server_fd,SOL_SOCKET,SO_RCVBUF,&size_buffer,(socklen_t *)&size_int);

    listen(server_fd,5);

    printf("Waiting for connectting\n");
    client_fd2 = accept(server_fd,(struct sockaddr *)&client2,&sin_size);
    printf("Got connection \n");
    sprintf(send_buffer,"%d",size_buffer);
	send(client_fd,send_buffer,1000,0);
    puts("Test Begin1");
    recevived = 0;
    bytes = 0;
    k=0;
    while(1)
    {
        recevived = recv(client_fd2,recv_buffer,1000,0);
        bytes += recevived;
        if(recevived != 0)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    printf("Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n",k,bytes,size_buffer);
	close(client_fd2);
	close(server_fd);

	strcpy(send_buffer,"Finish1");
	send(client_fd,send_buffer,1000,0);

	server_fd = socket(AF_INET,SOCK_STREAM,0);
	bind(server_fd,(struct sockaddr *)&server,sizeof(struct sockaddr));
	size_buffer = BUFFER_SIZE*1;
    setsockopt(server_fd,SOL_SOCKET,SO_RCVBUF,(const void *)&size_buffer,size_int);
    getsockopt(server_fd,SOL_SOCKET,SO_RCVBUF,&size_buffer,(socklen_t *)&size_int);
    listen(server_fd,5);
    client_fd2 = accept(server_fd,(struct sockaddr *)&client2,&sin_size);
    printf("Got connection \n");
    sprintf(send_buffer,"%d",size_buffer);
	send(client_fd,send_buffer,1000,0);
    puts("Test Begin2");
    recevived = 0;
    bytes = 0;
    k=0;
    while(1)
    {
        recevived = recv(client_fd2,recv_buffer,1000,0);
        bytes += recevived;
        if(recevived != 0)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    printf("Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n",k,bytes,size_buffer);
    printf("isit here");
	close(client_fd2);
	close(server_fd);

	strcpy(send_buffer,"Finish2");
	send(client_fd,send_buffer,1000,0);

	server_fd = socket(AF_INET,SOCK_STREAM,0);

	bind(server_fd,(struct sockaddr *)&server,sizeof(struct sockaddr));
	size_buffer = BUFFER_SIZE*2.5;
    setsockopt(server_fd,SOL_SOCKET,SO_RCVBUF,(const void *)&size_buffer,size_int);
    getsockopt(server_fd,SOL_SOCKET,SO_RCVBUF,&size_buffer,(socklen_t *)&size_int);
    listen(server_fd,5);
    client_fd2 = accept(server_fd,(struct sockaddr *)&client2,&sin_size);
    printf("Got connection \n");
    sprintf(send_buffer,"%d",size_buffer);
	send(client_fd,send_buffer,1000,0);
    puts("Test Begin");
    recevived=0;
    bytes = 0;
    k=0;
    while(1)
    {
        recevived = recv(client_fd2,recv_buffer,1000,0);
        bytes += recevived;
        if(recevived != 0)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    printf("Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n",k,bytes,size_buffer);
	close(client_fd2);
	close(server_fd);

	strcpy(send_buffer,"Finish3");
	send(client_fd,send_buffer,1000,0);

	server_fd = socket(AF_INET,SOCK_STREAM,0);

	bind(server_fd,(struct sockaddr *)&server,sizeof(struct sockaddr));
	size_buffer = BUFFER_SIZE*5;
    setsockopt(server_fd,SOL_SOCKET,SO_RCVBUF,(const void *)&size_buffer,size_int);
    getsockopt(server_fd,SOL_SOCKET,SO_RCVBUF,&size_buffer,(socklen_t *)&size_int);
    listen(server_fd,5);
    client_fd2 = accept(server_fd,(struct sockaddr *)&client2,&sin_size);
    printf("Got connection \n");
    sprintf(send_buffer,"%d",size_buffer);
	send(client_fd,send_buffer,1000,0);
    puts("Test Begin");
    recevived=0;
    bytes = 0;
    k=0;
    while(1)
    {
        recevived = recv(client_fd2,recv_buffer,1000,0);
        bytes += recevived;
        if(recevived != 0)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    printf("Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n",k,bytes,size_buffer);
	close(client_fd2);
	close(server_fd);

	strcpy(send_buffer,"Finish4");
	send(client_fd,send_buffer,1000,0);

	server_fd = socket(AF_INET,SOCK_STREAM,0);

	bind(server_fd,(struct sockaddr *)&server,sizeof(struct sockaddr));
	size_buffer = BUFFER_SIZE*0.005;
    setsockopt(server_fd,SOL_SOCKET,SO_RCVBUF,(const void *)&size_buffer,size_int);
    getsockopt(server_fd,SOL_SOCKET,SO_RCVBUF,&size_buffer,(socklen_t *)&size_int);
    listen(server_fd,5);
    client_fd2 = accept(server_fd,(struct sockaddr *)&client2,&sin_size);
    printf("Got connection \n");
    sprintf(send_buffer,"%d",size_buffer);
	send(client_fd,send_buffer,1000,0);
    puts("Test Begin");
    recevived=0;
    bytes = 0;
    k=0;
    while(1)
    {
        recevived = recv(client_fd2,recv_buffer,1000,0);
        bytes += recevived;
        if(recevived != 0)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    printf("Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n",k,bytes,size_buffer);
	close(client_fd2);
	close(server_fd);

	strcpy(send_buffer,"Finish3");
	send(client_fd,send_buffer,1000,0);

	server_fd = socket(AF_INET,SOCK_STREAM,0);

	bind(server_fd,(struct sockaddr *)&server,sizeof(struct sockaddr));
	size_buffer = BUFFER_SIZE*0.025;
    setsockopt(server_fd,SOL_SOCKET,SO_RCVBUF,(const void *)&size_buffer,size_int);
    getsockopt(server_fd,SOL_SOCKET,SO_RCVBUF,&size_buffer,(socklen_t *)&size_int);
    listen(server_fd,5);
    client_fd2 = accept(server_fd,(struct sockaddr *)&client2,&sin_size);
    printf("Got connection \n");
    sprintf(send_buffer,"%d",size_buffer);
	send(client_fd,send_buffer,1000,0);
    puts("Test Begin");
    recevived=0;
    bytes = 0;
    k=0;
    while(1)
    {
        recevived = recv(client_fd2,recv_buffer,1000,0);
        bytes += recevived;
        if(recevived != 0)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    printf("Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n",k,bytes,size_buffer);
	close(client_fd2);
	close(server_fd);

	strcpy(send_buffer,"Finish4");
	send(client_fd,send_buffer,1000,0);

		server_fd = socket(AF_INET,SOCK_STREAM,0);

	bind(server_fd,(struct sockaddr *)&server,sizeof(struct sockaddr));
	size_buffer = BUFFER_SIZE*0.05;
    setsockopt(server_fd,SOL_SOCKET,SO_RCVBUF,(const void *)&size_buffer,size_int);
    getsockopt(server_fd,SOL_SOCKET,SO_RCVBUF,&size_buffer,(socklen_t *)&size_int);
    listen(server_fd,5);
    client_fd2 = accept(server_fd,(struct sockaddr *)&client2,&sin_size);
    printf("Got connection \n");
    sprintf(send_buffer,"%d",size_buffer);
	send(client_fd,send_buffer,1000,0);
    puts("Test Begin");
    recevived=0;
    bytes = 0;
    k=0;
    while(1)
    {
        recevived = recv(client_fd2,recv_buffer,1000,0);
        bytes += recevived;
        if(recevived != 0)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    printf("Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n",k,bytes,size_buffer);
	close(client_fd2);
	close(server_fd);

	strcpy(send_buffer,"Finish3");
	send(client_fd,send_buffer,1000,0);

	server_fd = socket(AF_INET,SOCK_STREAM,0);

	bind(server_fd,(struct sockaddr *)&server,sizeof(struct sockaddr));
	size_buffer = BUFFER_SIZE*0.125;
    setsockopt(server_fd,SOL_SOCKET,SO_RCVBUF,(const void *)&size_buffer,size_int);
    getsockopt(server_fd,SOL_SOCKET,SO_RCVBUF,&size_buffer,(socklen_t *)&size_int);
    listen(server_fd,5);
    client_fd2 = accept(server_fd,(struct sockaddr *)&client2,&sin_size);
    printf("Got connection \n");
    sprintf(send_buffer,"%d",size_buffer);
	send(client_fd,send_buffer,1000,0);
    puts("Test Begin");
    recevived=0;
    bytes = 0;
    k=0;
    while(1)
    {
        recevived = recv(client_fd2,recv_buffer,1000,0);
        bytes += recevived;
        if(recevived != 0)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    printf("Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n",k,bytes,size_buffer);
	close(client_fd2);
	close(server_fd);

	strcpy(send_buffer,"Finish4");
	send(client_fd,send_buffer,1000,0);

		server_fd = socket(AF_INET,SOCK_STREAM,0);

	bind(server_fd,(struct sockaddr *)&server,sizeof(struct sockaddr));
	size_buffer = BUFFER_SIZE*0.25;
    setsockopt(server_fd,SOL_SOCKET,SO_RCVBUF,(const void *)&size_buffer,size_int);
    getsockopt(server_fd,SOL_SOCKET,SO_RCVBUF,&size_buffer,(socklen_t *)&size_int);
    listen(server_fd,5);
    client_fd2 = accept(server_fd,(struct sockaddr *)&client2,&sin_size);
    printf("Got connection \n");
    sprintf(send_buffer,"%d",size_buffer);
	send(client_fd,send_buffer,1000,0);
    puts("Test Begin");
    recevived=0;
    bytes = 0;
    k=0;
    while(1)
    {
        recevived = recv(client_fd2,recv_buffer,1000,0);
        bytes += recevived;
        if(recevived != 0)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    printf("Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n",k,bytes,size_buffer);
	close(client_fd2);
	close(server_fd);

	strcpy(send_buffer,"Finish3");
	send(client_fd,send_buffer,1000,0);

	return 1;
}
