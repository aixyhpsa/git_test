head=-I../../tools
obj=../../tools/_epoll.o ../../tools/_socket.o ../../tools/_channel.o

all : server client

server : server.cpp $(obj)
	g++ -g -std=c++1y -o server server.cpp $(obj) $(head) 

client : client.cpp ../../tools/_socket.o
	g++ -g -std=c++1y -o client client.cpp ../../tools/_socket.o $(head) 

clear :
	rm -f server client

