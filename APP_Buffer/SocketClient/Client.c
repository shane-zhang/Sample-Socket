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
    char send_buffer[1000],recv_buffer[1000],recv_buffer1[10],recv_buffer5[50],recv_buffer10[100],recv_buffer25[250],recv_buffer50[500],recv_buffer200[2000],recv_buffer500[5000],recv_buffer1000[10000];

    bzero(send_buffer,sizeof(send_buffer));
    bzero(recv_buffer,sizeof(recv_buffer));

    struct hostent *host;
    struct sockaddr_in server,client,client2;

    host = gethostbyname("127.0.0.1");

    client_fd = socket(AF_INET,SOCK_STREAM,0);

    client.sin_family = AF_INET;
    client.sin_port = htons(3310);
    client.sin_addr = *((struct in_addr *)host->h_addr);

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

    listen(server_fd,5);

    printf("Waiting for connectting\n");
    client_fd2 = accept(server_fd,(struct sockaddr *)&client2,&sin_size);
    printf("Got connection \n");
    sprintf(send_buffer,"%d B",1000);
	send(client_fd,send_buffer,1000,0);
    puts("Test Begin Org");
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
    printf("Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n",k,bytes,1000);
	close(client_fd2);
	close(server_fd);

	sprintf(send_buffer,"Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n%s\n",k,bytes,1000,"Finish ORG test");
	send(client_fd,send_buffer,1000,0);

	server_fd = socket(AF_INET,SOCK_STREAM,0);
	bind(server_fd,(struct sockaddr *)&server,sizeof(struct sockaddr));

    listen(server_fd,5);
    client_fd2 = accept(server_fd,(struct sockaddr *)&client2,&sin_size);
    printf("Got connection \n");
    sprintf(send_buffer,"%d B",10);
	send(client_fd,send_buffer,1000,0);
    puts("Test Begin 1%");
    recevived = 0;
    bytes = 0;
    k=0;
    while(1)
    {
        recevived = recv(client_fd2,recv_buffer1,10,0);
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
    printf("Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n",k,bytes,10);
	close(client_fd2);
	close(server_fd);

	sprintf(send_buffer,"Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n%s\n",k,bytes,10,"Finish 10 B test");
	send(client_fd,send_buffer,1000,0);


	server_fd = socket(AF_INET,SOCK_STREAM,0);

	bind(server_fd,(struct sockaddr *)&server,sizeof(struct sockaddr));
    listen(server_fd,5);
    client_fd2 = accept(server_fd,(struct sockaddr *)&client2,&sin_size);
    printf("Got connection \n");
    sprintf(send_buffer,"%d B",50);
	send(client_fd,send_buffer,1000,0);
    puts("Test Begin 5%");
    recevived=0;
    bytes = 0;
    k=0;
    while(1)
    {
        recevived = recv(client_fd2,recv_buffer5,50,0);
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
    printf("Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n",k,bytes,50);
	close(client_fd2);
	close(server_fd);

	sprintf(send_buffer,"Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n%s\n",k,bytes,50,"Finish 50 B test");
	send(client_fd,send_buffer,1000,0);

	server_fd = socket(AF_INET,SOCK_STREAM,0);

	bind(server_fd,(struct sockaddr *)&server,sizeof(struct sockaddr));
    listen(server_fd,5);
    client_fd2 = accept(server_fd,(struct sockaddr *)&client2,&sin_size);
    printf("Got connection \n");
    sprintf(send_buffer,"%d B",100);
	send(client_fd,send_buffer,1000,0);
    puts("Test Begin 10%");
    recevived=0;
    bytes = 0;
    k=0;
    while(1)
    {
        recevived = recv(client_fd2,recv_buffer10,100,0);
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
    printf("Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n",k,bytes,100);
	close(client_fd2);
	close(server_fd);

	sprintf(send_buffer,"Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n%s\n",k,bytes,100,"Finish 100 B test");
	send(client_fd,send_buffer,1000,0);

	server_fd = socket(AF_INET,SOCK_STREAM,0);

	bind(server_fd,(struct sockaddr *)&server,sizeof(struct sockaddr));
    listen(server_fd,5);
    client_fd2 = accept(server_fd,(struct sockaddr *)&client2,&sin_size);
    printf("Got connection \n");
    sprintf(send_buffer,"%d B",250);
	send(client_fd,send_buffer,1000,0);
    puts("Test Begin 25%");
    recevived=0;
    bytes = 0;
    k=0;
    while(1)
    {
        recevived = recv(client_fd2,recv_buffer25,250,0);
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
    printf("Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n",k,bytes,250);
	close(client_fd2);
	close(server_fd);

	sprintf(send_buffer,"Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n%s\n",k,bytes,250,"Finish 250 B test");
	send(client_fd,send_buffer,1000,0);


	server_fd = socket(AF_INET,SOCK_STREAM,0);

	bind(server_fd,(struct sockaddr *)&server,sizeof(struct sockaddr));
    listen(server_fd,5);
    client_fd2 = accept(server_fd,(struct sockaddr *)&client2,&sin_size);
    printf("Got connection \n");
    sprintf(send_buffer,"%d B",500);
	send(client_fd,send_buffer,1000,0);
    puts("Test Begin 50%");
    recevived=0;
    bytes = 0;
    k=0;
    while(1)
    {
        recevived = recv(client_fd2,recv_buffer50,500,0);
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
    printf("Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n",k,bytes,500);
	close(client_fd2);
	close(server_fd);

	sprintf(send_buffer,"Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n%s\n",k,bytes,500,"Finish 500 B test");
	send(client_fd,send_buffer,1000,0);

	server_fd = socket(AF_INET,SOCK_STREAM,0);

	bind(server_fd,(struct sockaddr *)&server,sizeof(struct sockaddr));
    listen(server_fd,5);
    client_fd2 = accept(server_fd,(struct sockaddr *)&client2,&sin_size);
    printf("Got connection \n");
    sprintf(send_buffer,"%d B",2000);
	send(client_fd,send_buffer,1000,0);
    puts("Test Begin 200%");
    recevived=0;
    bytes = 0;
    k=0;
    while(1)
    {
        recevived = recv(client_fd2,recv_buffer200,2000,0);
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
    printf("Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n",k,bytes,2000);
	close(client_fd2);
	close(server_fd);

	sprintf(send_buffer,"Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n%s\n",k,bytes,2000,"Finish 2000 B test");
	send(client_fd,send_buffer,1000,0);

	server_fd = socket(AF_INET,SOCK_STREAM,0);

	bind(server_fd,(struct sockaddr *)&server,sizeof(struct sockaddr));
    listen(server_fd,5);
    client_fd2 = accept(server_fd,(struct sockaddr *)&client2,&sin_size);
    printf("Got connection \n");
    sprintf(send_buffer,"%d B",5000);
	send(client_fd,send_buffer,1000,0);
    puts("Test Begin 500%");
    recevived=0;
    bytes = 0;
    k=0;
    while(1)
    {
        recevived = recv(client_fd2,recv_buffer500,5000,0);
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
    printf("Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n",k,bytes,5000);
	close(client_fd2);
	close(server_fd);

	sprintf(send_buffer,"Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n%s\n",k,bytes,5000,"Finish 5000 B test");
	send(client_fd,send_buffer,1000,0);

	server_fd = socket(AF_INET,SOCK_STREAM,0);

	bind(server_fd,(struct sockaddr *)&server,sizeof(struct sockaddr));    listen(server_fd,5);
    client_fd2 = accept(server_fd,(struct sockaddr *)&client2,&sin_size);
    printf("Got connection \n");
    sprintf(send_buffer,"%d B",10000);
	send(client_fd,send_buffer,1000,0);
    puts("Test Begin 1000%");
    recevived=0;
    bytes = 0;
    k=0;
    while(1)
    {
        recevived = recv(client_fd2,recv_buffer1000,10000,0);
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
    printf("Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n",k,bytes,10000);
	close(client_fd2);
	close(server_fd);

	sprintf(send_buffer,"Received:%d pkgs,packets:%d bytes,buffer:%d bytes\n%s\n",k,bytes,10000,"Finish 10000 B test");
	send(client_fd,send_buffer,1000,0);


	return 1;
}
