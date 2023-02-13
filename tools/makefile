#C++标准
std=-std=c++1y
#优化等级
optimize=-O2

all : _epoll.o _socket.o _channel.o _eventloop.o

_epoll.o : _epoll.cpp _epoll.h _channel.cpp _channel.h
	g++ $(std) $(optimize) -c -o _epoll.o _epoll.cpp

_socket.o : _socket.cpp _socket.h
	g++ $(std) $(optimize) -c -o _socket.o _socket.cpp

_channel.o : _channel.cpp _channel.h _epoll.cpp _epoll.h
	g++ $(std) $(optimize) -c -o _channel.o _channel.cpp

_eventloop.o : _eventloop.cpp _eventloop.h _epoll.cpp _epoll.h _channel.cpp _channel.h
	g++ $(std) $(optimize) -c -o _eventloop.o _eventloop.cpp

clean :
	rm -f _epoll.o _socket.o _channel.o _eventloop.o
