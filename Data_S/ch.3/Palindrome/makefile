main: main.o DualStack.o
	g++ -o main main.o DualStack.o
main.o: main.cpp DualStack.cpp DualStack.h
	g++ -c main.cpp
DualStack.o: DualStack.cpp DualStack.h
	g++ -c DualStack.cpp
clean:
	rm -rf *.o
