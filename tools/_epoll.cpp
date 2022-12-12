#include "_epoll.h"

namespace dya
{

Epoll::Epoll() : m_epfd(-1) 
{
	memset(&m_ev, 0, sizeof(m_ev));
}

Epoll::~Epoll()
{
	m_epfd = -1;
	memset(&m_ev, 0, sizeof(m_ev));
}
void Epoll::addfd(int fd)
{
	m_ev.events = EPOLLIN;
	m_ev.data.fd = fd;
	epoll_ctl(m_epfd, EPOLL_CTL_ADD, fd, &m_ev);
}

void Epoll::poll(std::vector<struct epoll_event> &events)
{
	struct epoll_event temp[EVMAX]; 
	int count = epoll_wait(m_epfd, temp, EVMAX, TIMEOUT);
	for (int i=0; i<count; i++)
	{
		events.push_back(temp[i]);
	}
}

}
