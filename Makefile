all: webget

webget: apps/webget.cc util/address.cc util/socket.cc util/file_descriptor.cc
	g++ -std=c++20 -Iutil -o apps/webget apps/webget.cc util/address.cc util/socket.cc util/file_descriptor.cc -lstdc++

clean:
	rm -f apps/webget