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
	ep->addfd(listen->getfd(), EPOLLIN);

	const int bplen = 128;
	std::unique_ptr<char []> bp(new char[bplen]);
	//std::unique_ptr<dya::InetAddress> remote(new dya::InetAddress);
	while (true)
	{
		auto result = ep->poll();
		for (int i=0; i<result.size(); i++)
		{
			if (result[i].data.fd == listen->getfd())
			{
				dya::InetAddress remote;
				int client = listen->accept(remote);
				if (client == -1) continue;
				ep->addfd(client, EPOLLIN);
			}
			else
			{
				memset((char *)bp.get(), 0, bplen);
				int count = recv(result[i].data.fd, (char *)bp.get(), bplen, 0);
				if (count <= 0)
				{
					close(result[i].data.fd);
					continue;
				}
				puts(bp.get());
				strcpy((char *)bp.get(), "OK hello client");
				send(result[i].data.fd, bp.get(),strlen(bp.get()), 0);
			}

		}
	}

	return 0;
}
