#include <iostream>
#include <cassert>
#include <memory>
#include "_socket.h"
#include "_epoll.h"

int main(int argc, char *argv[])
{
	std::unique_ptr<dya::InetAddress> local(new dya::InetAddress("192.168.45.128", 5001));
	std::unique_ptr<dya::Socket> listen(new dya::Socket);
	//dya::InetAddress local("192.168.45.128", 5001);
	//dya::Socket listen;
	listen->bind(*local);
	listen->listen();
	std::unique_ptr<dya::InetAddress> remote(new dya::InetAddress);
	//dya::InetAddress remote;
	int client = listen->accept(*remote);

	assert(client != -1);

	char buff[100] = {0};
	recv(client, buff, sizeof(buff), 0);
	puts(buff);
	strcpy(buff, "OK hello world");
	send(client, buff, sizeof(buff), 0);
	return 0;
}
