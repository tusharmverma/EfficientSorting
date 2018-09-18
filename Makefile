oop : main.o 
	clang++ -g -o oop main.o 
	clang++ -g -Wall -Wextra -std=c++14 -pedantic -c main.cpp
clean:
	rm *.o oop06