CC = g++

all:
	g++ helloworld.cpp -o helloworld && ./helloworld
	g++ helloTest.cpp -o helloTest && ./helloTest

test:
	chmod +x helloworld
	./helloTest

clean:
	$(RM) helloworld helloTest
