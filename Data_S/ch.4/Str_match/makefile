main: main.o FUNC.o
	g++ -o main main.o FUNC.o
main.o: main.cpp match.cpp
	g++ -c main.cpp
FUNC.o: FUNC.cpp FUNC.h
	g++ -c FUNC.cpp
clean:
	rm -rf *.o
