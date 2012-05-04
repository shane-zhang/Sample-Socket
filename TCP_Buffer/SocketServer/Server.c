/*
This is for the project IERG3310

*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/time.h>
#define TIME_TEST 3000

int main()
{

    printf("Hello This is server\n");

    int server_fd,client_fd,client_fd2,opcode=1;
    struct hostent *host;
    char send_buffer[1000],recv_buffer[1000];

	int i;

	bzero(send_buffer,sizeof(send_buffer));
	bzero(recv_buffer,sizeof(recv_buffer));

    struct sockaddr_in server,client,client2;

    server_fd = socket(AF_INET,SOCK_STREAM,0);
    setsockopt(server_fd,SOL_SOCKET,SO_REUSEADDR,&opcode,sizeof(int));

    server.sin_family = AF_INET;
    server.sin_port = htons(3310);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd,(struct sockaddr *)&server,sizeof(struct sockaddr));

    listen(server_fd,5);

    unsigned int sin_size = sizeof(struct sockaddr_in);

    printf("Waiting for connectting\n");
    client_fd = accept(server_fd,(struct sockaddr *)&client,&sin_size);
    printf("Got connection \n");

    recv(client_fd,recv_buffer,1000,0);
    puts(recv_buffer);

    int TCP_Port = rand()%10000 + 20000;

    sprintf(send_buffer,"%d",TCP_Port);

    send(client_fd,send_buffer,1000,0);

	sleep(1);

	struct timeval start,end;
	long mtime,seconds,useconds;

    host = gethostbyname("127.0.0.1");
    int k;

    client_fd2 = socket(AF_INET,SOCK_STREAM,0);

	printf("%d\n",TCP_Port);
    client2.sin_family = AF_INET;
    client2.sin_port = htons(TCP_Port);
    client2.sin_addr = *((struct in_addr *)host->h_addr);

    connect(client_fd2,(struct sockaddr *)&client2,sizeof(struct sockaddr));
	recv(client_fd,recv_buffer,1000,0);
	puts(recv_buffer);
	puts("Test Begin1");
	k = 0;

    for(i=0; i<1000; i++)
    {
        send_buffer[i] = 'a';
    }
    send_buffer[999]= '\0';

	gettimeofday(&start,NULL);

	mtime = 0;

	while(mtime<TIME_TEST)
	{
		gettimeofday(&end,NULL);
		send(client_fd2,send_buffer,strlen(send_buffer),0);
		seconds =end.tv_sec-start.tv_sec;
		useconds = end.tv_usec-start.tv_usec;

		mtime = ((seconds)*1000 + useconds/1000.0);
		k++;
	}
	printf("send:%d pks\n",k);
	close(client_fd2);
	recv(client_fd,recv_buffer,1000,0);
	puts(recv_buffer);

	client_fd2 = socket(AF_INET,SOCK_STREAM,0);
	connect(client_fd2,(struct sockaddr *)&client2,sizeof(struct sockaddr));
	recv(client_fd,recv_buffer,1000,0);
	puts(recv_buffer);
	puts("Test Begin2");
	k = 0;

    for(i=0; i<1000; i++)
    {
        send_buffer[i] = 'a';
    }
    send_buffer[999]= '\0';

	gettimeofday(&start,NULL);

	mtime = 0;
	while(mtime<TIME_TEST)
	{
		gettimeofday(&end,NULL);
		send(client_fd2,send_buffer,strlen(send_buffer),0);
		seconds =end.tv_sec-start.tv_sec;
		useconds = end.tv_usec-start.tv_usec;

		mtime = ((seconds)*1000 + useconds/1000.0);
		k++;
	}



	printf("send:%d pks\n",k);
	close(client_fd2);
	recv(client_fd,recv_buffer,1000,0);
	puts(recv_buffer);

	client_fd2 = socket(AF_INET,SOCK_STREAM,0);
	connect(client_fd2,(struct sockaddr *)&client2,sizeof(struct sockaddr));
	recv(client_fd,recv_buffer,1000,0);
	puts(recv_buffer);
	puts("Test Begin3");
	k = 0;


    for(i=0; i<1000; i++)
    {
        send_buffer[i] = 'a';
    }
    send_buffer[999]= '\0';

	gettimeofday(&start,NULL);

	mtime = 0;
	while(mtime<TIME_TEST)
	{
		gettimeofday(&end,NULL);
		send(client_fd2,send_buffer,strlen(send_buffer),0);
		seconds =end.tv_sec-start.tv_sec;
		useconds = end.tv_usec-start.tv_usec;

		mtime = ((seconds)*1000 + useconds/1000.0);
		k++;
	}

	printf("send:%d pks\n",k);
	close(client_fd2);
	recv(client_fd,recv_buffer,1000,0);
	puts(recv_buffer);

	client_fd2 = socket(AF_INET,SOCK_STREAM,0);
	connect(client_fd2,(struct sockaddr *)&client2,sizeof(struct sockaddr));
	recv(client_fd,recv_buffer,1000,0);
	puts(recv_buffer);
	puts("Test Begin4");
	k = 0;


    for(i=0; i<1000; i++)
    {
        send_buffer[i] = 'a';
    }
    send_buffer[999]= '\0';

	gettimeofday(&start,NULL);

	mtime = 0;
	while(mtime<TIME_TEST)
	{
		gettimeofday(&end,NULL);
		send(client_fd2,send_buffer,strlen(send_buffer),0);
		seconds =end.tv_sec-start.tv_sec;
		useconds = end.tv_usec-start.tv_usec;

		mtime = ((seconds)*1000 + useconds/1000.0);
		k++;
	}

	printf("send:%d pks\n",k);
	close(client_fd2);
	recv(client_fd,recv_buffer,1000,0);
	puts(recv_buffer);

		client_fd2 = socket(AF_INET,SOCK_STREAM,0);
	connect(client_fd2,(struct sockaddr *)&client2,sizeof(struct sockaddr));
	recv(client_fd,recv_buffer,1000,0);
	puts(recv_buffer);
	puts("Test Begin4");
	k = 0;


    for(i=0; i<1000; i++)
    {
        send_buffer[i] = 'a';
    }
    send_buffer[999]= '\0';

	gettimeofday(&start,NULL);

	mtime = 0;
	while(mtime<TIME_TEST)
	{
		gettimeofday(&end,NULL);
		send(client_fd2,send_buffer,strlen(send_buffer),0);
		seconds =end.tv_sec-start.tv_sec;
		useconds = end.tv_usec-start.tv_usec;

		mtime = ((seconds)*1000 + useconds/1000.0);
		k++;
	}

	printf("send:%d pks\n",k);
	close(client_fd2);
	recv(client_fd,recv_buffer,1000,0);
	puts(recv_buffer);

		client_fd2 = socket(AF_INET,SOCK_STREAM,0);
	connect(client_fd2,(struct sockaddr *)&client2,sizeof(struct sockaddr));
	recv(client_fd,recv_buffer,1000,0);
	puts(recv_buffer);
	puts("Test Begin4");
	k = 0;


    for(i=0; i<1000; i++)
    {
        send_buffer[i] = 'a';
    }
    send_buffer[999]= '\0';

	gettimeofday(&start,NULL);

	mtime = 0;
	while(mtime<TIME_TEST)
	{
		gettimeofday(&end,NULL);
		send(client_fd2,send_buffer,strlen(send_buffer),0);
		seconds =end.tv_sec-start.tv_sec;
		useconds = end.tv_usec-start.tv_usec;

		mtime = ((seconds)*1000 + useconds/1000.0);
		k++;
	}

	printf("send:%d pks\n",k);
	close(client_fd2);
	recv(client_fd,recv_buffer,1000,0);
	puts(recv_buffer);

		client_fd2 = socket(AF_INET,SOCK_STREAM,0);
	connect(client_fd2,(struct sockaddr *)&client2,sizeof(struct sockaddr));
	recv(client_fd,recv_buffer,1000,0);
	puts(recv_buffer);
	puts("Test Begin4");
	k = 0;


    for(i=0; i<1000; i++)
    {
        send_buffer[i] = 'a';
    }
    send_buffer[999]= '\0';

	gettimeofday(&start,NULL);

	mtime = 0;
	while(mtime<TIME_TEST)
	{
		gettimeofday(&end,NULL);
		send(client_fd2,send_buffer,strlen(send_buffer),0);
		seconds =end.tv_sec-start.tv_sec;
		useconds = end.tv_usec-start.tv_usec;

		mtime = ((seconds)*1000 + useconds/1000.0);
		k++;
	}

	printf("send:%d pks\n",k);
	close(client_fd2);
	recv(client_fd,recv_buffer,1000,0);
	puts(recv_buffer);

		client_fd2 = socket(AF_INET,SOCK_STREAM,0);
	connect(client_fd2,(struct sockaddr *)&client2,sizeof(struct sockaddr));
	recv(client_fd,recv_buffer,1000,0);
	puts(recv_buffer);
	puts("Test Begin4");
	k = 0;


    for(i=0; i<1000; i++)
    {
        send_buffer[i] = 'a';
    }
    send_buffer[999]= '\0';

	gettimeofday(&start,NULL);

	mtime = 0;
	while(mtime<TIME_TEST)
	{
		gettimeofday(&end,NULL);
		send(client_fd2,send_buffer,strlen(send_buffer),0);
		seconds =end.tv_sec-start.tv_sec;
		useconds = end.tv_usec-start.tv_usec;

		mtime = ((seconds)*1000 + useconds/1000.0);
		k++;
	}

	printf("send:%d pks\n",k);
	close(client_fd2);
	recv(client_fd,recv_buffer,1000,0);
	puts(recv_buffer);

		client_fd2 = socket(AF_INET,SOCK_STREAM,0);
	connect(client_fd2,(struct sockaddr *)&client2,sizeof(struct sockaddr));
	recv(client_fd,recv_buffer,1000,0);
	puts(recv_buffer);
	puts("Test Begin4");
	k = 0;


    for(i=0; i<1000; i++)
    {
        send_buffer[i] = 'a';
    }
    send_buffer[999]= '\0';

	gettimeofday(&start,NULL);

	mtime = 0;
	while(mtime<TIME_TEST)
	{
		gettimeofday(&end,NULL);
		send(client_fd2,send_buffer,strlen(send_buffer),0);
		seconds =end.tv_sec-start.tv_sec;
		useconds = end.tv_usec-start.tv_usec;

		mtime = ((seconds)*1000 + useconds/1000.0);
		k++;
	}

	printf("send:%d pks\n",k);
	close(client_fd2);
	recv(client_fd,recv_buffer,1000,0);
	puts(recv_buffer);

	return 1;
}
