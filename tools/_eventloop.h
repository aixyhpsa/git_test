#ifndef __EVENTLOOP_H__
#define __EVENTLOOP_H__

#include "_epoll.h"
#include "_channel.h"

namespace dya
{
//////////////////////////////////////////////////
class Epoll;
class Channel;

class Eventloop
{
private :
    Epoll *m_ep;
    bool m_quit;
public :
    Eventloop();
    ~Eventloop();
public :
    void loop();
    void updateChannel(Channel &ch);
};
//////////////////////////////////////////////////
}
#endif
