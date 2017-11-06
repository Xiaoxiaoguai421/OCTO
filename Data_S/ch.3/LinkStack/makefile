main: main.o LinkStack.o
	g++ -o main main.o LinkStack.o
main.o: main.cpp LinkStack.cpp LinkStack.h
	g++ -c main.cpp
LinkStack.o: LinkStack.cpp LinkStack.h
	g++ -c LinkStack.cpp
clean:
	rm -rf *.o
