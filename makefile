CC = g++

lab2: exercise1p5 exercise1p11while exercise1p11for

exercise1p5:
	cd exercise2 && g++ exercise1p5.cpp -o exercise1p5 && ./exercise1p5

exercise1p11while:
	cd exercise2 && g++ exercise1p11while.cpp -o exercise1p11while && ./exercise1p11while

exercise1p11for:
	cd exercise2 && g++ exercise1p11for.cpp -o exercise1p11for && ./exercise1p11for

