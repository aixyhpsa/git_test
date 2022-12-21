#include "_channel.h"

namespace dya
{
////////////////////////////////////////////////
//class Channel
//{
//private :
//	  Epoll &m_ep;
//	  int m_fd;
//	  uint32_t m_events;
//	  uint32_t m_revents;
//	  bool m_inEpoll;
//public :
//	  Channel(Epoll &ep, int fd);
//	  ~Channel();
//public :
//	  void enableReading();
//	  int getfd();
//	  uint32_t getEvents();
//	  bool getInEpoll();
//	  void setInEpoll();
//	  void setRevents(uint32_t ev);
//};
////////////////////////////////////////////////
Channel::Channel(Epoll &ep, int fd): m_ep(ep), m_fd(fd), m_events(0), m_revents(0), m_inEpoll(false) {}

Channel::~Channel() {}

void Channel::enableReading()
{
	m_events = EPOLLIN;
	m_ep.updataChannel(*this);
}

int Channel::getfd() { return m_fd; }

uint32_t Channel::getEvents() { return m_events; }

bool Channel::getInEpoll() { return m_inEpoll; }
 
void Channel::setInEpoll() { m_inEpoll = true; }

void Channel::setRevents(uint32_t ev) { m_revents = ev; }
////////////////////////////////////////////////
}
