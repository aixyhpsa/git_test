#ifndef __EPOLL_H__ 
#define __EPOLL_H__ 

#include <vector>
#include <sys/epoll.h>
#include <string.h>
#include <unistd.h>
#include "_channel.h"
#define EVMAX 20

namespace dya
{
//////////////////////////////////////////////////////////////
class Channel;
class Epoll
{
private :
	int m_epfd;
	struct epoll_event *m_evs;
public :
	Epoll();
	~Epoll();
public :
	void addfd(int fd, uint32_t op);
	//std::vector<struct epoll_event> poll(int timeout = -1);
    std::vector<Channel *> poll(int timeout = -1);
    void updateChannel(Channel &ch);
};
//////////////////////////////////////////////////////////////
}
#endif
