main: main.o InBiThrTree.o
	g++ -o  main main.o InBiThrTree.o -g
main.o: main.cpp InBiThrTree.h InBiThrTree.cpp
	g++ -c main.cpp
InBiThrTree.o: InBiThrTree.h InBiThrTree.cpp
	g++ -c InBiThrTree.cpp
clean:
	rm *.o
