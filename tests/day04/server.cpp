#include <iostream>
#include <cassert>
#include <memory>
#include "_socket.h"
#include "_epoll.h"

int main(int argc, char *argv[])
{
	std::unique_ptr<dya::InetAddress> local(new dya::InetAddress("192.168.45.128", 5001));
	std::unique_ptr<dya::Socket> listen(new dya::Socket);
	listen->bind(*local);
	listen->listen();

	std::unique_ptr<dya::Epoll> ep(new dya::Epoll);
	ep->addfd(listen->getfd());

	std::string buff;
	buff.resize(512);
	while (true)
	{
		auto result = ep->poll();
		for (int i=0; i<result.size(); i++)
		{
			if (result[i].data.fd == listen->getfd())
			{
				std::unique_ptr<dya::InetAddress> remote(new dya::InetAddress);
				//dya::InetAddress remote;
				int client = listen->accept(*remote);
				if (client == -1) continue;
			ep->addfd(client);
			}
			else
			{
				buff.clear();
				recv(result[i].data.fd, (char *)buff.c_str(), buff.capacity(), 0);
				std::cout << buff << "\n";
				buff = "OK hello client";
				send(result[i].data.fd, buff.c_str(), buff.size(), 0);
			}

		}
	}

	return 0;
}
