#ifndef __CHANNEL_H__
#define __CHANNEL_H__

#include "_epoll.h"
#include "_socket.h"
namespace dya
{
////////////////////////////////////////////////
class Epoll;
class Channel
{
private :
	  Epoll &m_ep;
	  int m_fd;
	  uint32_t m_events;	//需要对m_fd监听的事件们
	  uint32_t m_revents;	//使epoll_wait返回的那个事件
	  bool m_inEpoll;
public :
	  Channel(Epoll &ep, int fd);
	  ~Channel();
public :
	  void enableReading();
	  int getfd();
	  uint32_t getEvents();
	  bool getInEpoll();
	  void setInEpoll();
	  void setRevents(uint32_t ev);
};

////////////////////////////////////////////////
}
#endif
