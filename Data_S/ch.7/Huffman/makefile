main: main.o Huffman.o
	g++  main.o Huffman.o -o main -g
main.o: main.cpp Huffman.cpp Huffman.h
	g++ -c main.cpp
Huffman.o: Huffman.cpp Huffman.h
	g++ -c Huffman.cpp
clean:
	rm *.o
