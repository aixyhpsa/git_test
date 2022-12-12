#include <iostream>
#include <cassert>
#include "_socket.h"
#include "_epoll.h"

int main(int argc, char *argv[])
{
	dya::InetAddress local("192.168.45.128", 5001);
	dya::Socket listen;
	listen.bind(local);
	listen.listen();
	dya::InetAddress remote;
	int client = listen.accept(remote);

	assert(client != -1);

	char buff[100] = {0};
	recv(client, buff, sizeof(buff), 0);
	puts(buff);
	strcpy(buff, "OK hello world");
	send(client, buff, sizeof(buff), 0);
	return 0;
}
