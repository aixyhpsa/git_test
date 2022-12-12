#include "_socket.h"

namespace dya
{
////////////////////////////////////////////////////////////////////
Socket::Socket():m_fd(-1) {}

Socket::~Socket() {}

int Socket::getfd() { return m_fd; }

bool Socket::bind(InetAddress &inetAddr) 
{
	m_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (m_fd == -1)
		return false;
	::bind(m_fd, (sockaddr *)&inetAddr.m_addr, inetAddr.m_len);
	return true;
}

void Socket::listen()
{
	::listen(m_fd, SOMAXCONN);
}

bool Socket::connect(InetAddress &inetAddr)
{
	m_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (m_fd == -1)
		return false;
	::connect(m_fd, (sockaddr *)&inetAddr.m_addr, inetAddr.m_len);
	return true;
}

int Socket::accept(InetAddress &inetaddr)
{
	return ::accept(m_fd, (sockaddr *)&inetaddr.m_addr, &inetaddr.m_len);
}
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//空白，给accept当参数
InetAddress::InetAddress(): m_len(sizeof(struct sockaddr_in))
{
	memset(&m_addr, 0, sizeof(m_addr));
}
//给listen或connect当参数
InetAddress::InetAddress(const char *ip, int port)
{
	memset(&m_addr, 0, sizeof(m_addr));
	m_addr.sin_family = AF_INET;
	m_addr.sin_addr.s_addr = inet_addr(ip);
	m_addr.sin_port = htons(port);
	m_len = sizeof(m_addr);
}

InetAddress::~InetAddress(){}
////////////////////////////////////////////////////////////////////
}
