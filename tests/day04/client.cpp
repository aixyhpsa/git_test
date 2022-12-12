#include "_socket.h"
#include "_epoll.h"
#include <iostream>
#include <cassert>

int main()
{
	dya::InetAddress local("192.168.45.128", 5001);
	dya::Socket conn;

	assert(conn.connect(local));

	char buff[100] = {0};
	strcpy(buff, "this is client");
	send(conn.getfd(), buff, sizeof(buff), 0);
	recv(conn.getfd(), buff, sizeof(buff), 0);
	puts(buff);
	return 0;
}
