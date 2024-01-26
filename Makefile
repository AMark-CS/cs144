all: webget

webget: apps/webget.cc
	gcc -std=c++11 -Iutil -o apps/webget apps/webget.cc -lstdc++

clean:
	rm -f apps/webget