#ifndef __SOCKET_H__
#define __SOCKET_H__
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
namespace dya
{
////////////////////////////////////////////////////////////////////
class InetAddress
{
public :
	struct sockaddr_in m_addr;
	socklen_t m_len;
public :
	//空白，给accept当参数
	InetAddress();
	//给listen或connect当参数
	InetAddress(const char *ip, int port);
	~InetAddress();
};
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
class Socket
{
private :
	int m_fd;
public :
	Socket();
	~Socket();
public :
	bool bind(InetAddress &inetAddr);
	void listen();
	bool connect(InetAddress &inetAddr);
	int getfd();
	int accept(InetAddress &inetAddr);
	void setNonBlack();
};
////////////////////////////////////////////////////////////////////
}
#endif
