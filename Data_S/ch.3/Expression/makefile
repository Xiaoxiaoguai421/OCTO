main: main.o SeqStack.o
	g++ -o main main.o SeqStack.o
main.o: main.cpp SeqStack.cpp SeqStack.h
	g++ -c main.cpp
SeqStack.o: SeqStack.cpp SeqStack.h
	g++ -c SeqStack.cpp
clean:
	rm -rf *.o
