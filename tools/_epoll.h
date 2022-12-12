#ifndef __EPOLL_H__ 
#define __EPOLL_H__ 

#include <vector>
#include <sys/epoll.h>
#include <string.h>

#define TIMEOUT -1
#define EVMAX 10

namespace dya
{

class Epoll
{
private :
	int m_epfd;
	struct epoll_event m_ev;
public :
	Epoll();
	~Epoll();
public :
	void addfd(int fd);
	void poll(std::vector<struct epoll_event> &events);
};

}
#endif
