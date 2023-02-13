#include "_eventloop.h"
namespace dya
{
//////////////////////////////////////////////////
//class Eventloop
//{
//private :
//    Epoll *m_ep;
//    bool m_quit;
//public :
//    Eventloop();
//    ~Eventloop();
//public :
//    void loop();
//    void updateChannel(Channel &ch);
//};
//////////////////////////////////////////////////
Eventloop::Eventloop(): m_ep(nullptr), m_quit(false) { m_ep = new Epoll(); }

Eventloop::~Eventloop() { delete m_ep; }

void Eventloop::loop()
{
	while(!m_quit)
	{
		std::vector<Channel *> chs;
		chs = m_ep->poll();
		for (int i=0; i<chs.size(); i++)
		{
			chs[i]->handleEvent();
		}
	}
}
void Eventloop::updateChannel(Channel &ch)
{
	m_ep->updateChannel(ch);
}
//////////////////////////////////////////////////
}
