main: BiTree.o main.o
	g++ -o main  BiTree.o main.o
BiTree.o: BiTree.h BiTree.cpp
	g++ -c BiTree.cpp
main.o: main.cpp BiTree.h BiTree.cpp
	g++ -c main.cpp
clean:
	rm *.o
