main: main.o MGraph.o
		g++ -o main main.o MGraph.o
main.o: main.cpp MGraph.cpp MGraph.h
		gcc -c main.cpp
MGraph.o: MGraph.cpp MGraph.h
		gcc -c MGraph.cpp
clean: 
		rm -rf *.o
