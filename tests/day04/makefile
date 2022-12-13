head=-I../../tools
obj=../../tools

all : server client

server : server.cpp $(obj)/_epoll.o $(obj)/_socket.o
	g++ -g -std=c++1y -O2 -o server server.cpp $(obj)/_epoll.o $(obj)/_socket.o $(head) 

client : client.cpp $(obj)/_epoll.o $(obj)/_socket.o
	g++ -g -std=c++1y -O2 -o client client.cpp $(obj)/_epoll.o $(obj)/_socket.o $(head) 

clear :
	rm -f server client

