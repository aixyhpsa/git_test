#ifndef __EPOLL_H__ 
#define __EPOLL_H__ 

#include <vector>
#include <sys/epoll.h>
#include <string.h>

#define EVMAX 20

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
	std::vector<struct epoll_event> poll();
};

}
#endif
