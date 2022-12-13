#include "_epoll.h"

namespace dya
{
////////////////////////////////////////////////////////////////
Epoll::Epoll() 
{
	m_epfd = epoll_create(1);
	memset(&m_ev, 0, sizeof(m_ev));
}

Epoll::~Epoll() {}

void Epoll::addfd(int fd)
{
	m_ev.events = EPOLLIN;
	m_ev.data.fd = fd;
	epoll_ctl(m_epfd, EPOLL_CTL_ADD, fd, &m_ev);
}

std::vector<struct epoll_event> Epoll::poll()
{
	std::vector<struct epoll_event> events;
	struct epoll_event temp[EVMAX]; 
	int count = epoll_wait(m_epfd, temp, EVMAX, -1);
	for (int i=0; i<count; i++)
	{
		events.push_back(temp[i]);
	}
	return events;
}
////////////////////////////////////////////////////////////////
}
