#include "_epoll.h"

namespace dya
{
////////////////////////////////////////////////////////////////
//class Epoll
//{
//private :
//	  int m_epfd;
//    struct epoll_event *m_evs;
//public :
//    Epoll();
//    ~Epoll();
//public :
//    void addfd(int fd, uint32_t op);
//    std::vector<struct epoll_event> poll(int timeout = -1);
//    std::vector<Channel *> poll(int timeout = -1);
//    void updataChannel(Channel &ch);
//};
////////////////////////////////////////////////////////////////
void Epoll::updataChannel(Channel &ch)
{
	struct epoll_event ev;
	memset(&ev, 0, sizeof(ev));
	ev.events = ch.getEvents();
	ev.data.ptr = &ch;
	if (ch.getInEpoll() == 0)
	{
		ch.setInEpoll();
		epoll_ctl(m_epfd, EPOLL_CTL_ADD, ch.getfd(), &ev);
	}
	else
		epoll_ctl(m_epfd, EPOLL_CTL_MOD, ch.getfd(), &ev);
}


Epoll::Epoll() 
{
	m_epfd = epoll_create(1);
	m_evs = new struct epoll_event[EVMAX];
	memset(m_evs, 0, sizeof(struct epoll_event)*EVMAX);
}

Epoll::~Epoll() 
{
	if (m_epfd != -1)
	{
		close(m_epfd);
		m_epfd = -1;
	}
	delete [] m_evs;
}

void Epoll::addfd(int fd, uint32_t op)
{
	struct epoll_event ev;
	memset(&ev, 0, sizeof(ev));
	ev.events = op;
	ev.data.fd = fd;
	epoll_ctl(m_epfd, EPOLL_CTL_ADD, fd, &ev);
}

std::vector<Channel *> Epoll::poll(int timeout)
{
	std::vector<Channel *> events;
	int count = epoll_wait(m_epfd, m_evs, EVMAX, timeout);
	if(count == -1)
		return events;
	for (int i=0; i<count; i++)
	{
		Channel *ch = (Channel *)m_evs[i].data.ptr;
		ch->setRevents(m_evs[i].events);
		events.push_back(ch);
	}
	return events;
}

//std::vector<struct epoll_event> Epoll::poll(int timeout)
//{
//	std::vector<struct epoll_event> events;
//	int count = epoll_wait(m_epfd, m_evs, EVMAX, timeout);
//	if(count == -1)
//	return events;
//  for (int i=0; i<count; i++)
//  {
//		events.push_back(m_evs[i]);
//	}
//	return events;
//}

////////////////////////////////////////////////////////////////
}
