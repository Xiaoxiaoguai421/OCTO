main: main.o SeqQueue.o
	g++ -o main main.o SeqQueue.o
main.o: main.cpp SeqQueue.cpp SeqQueue.h
	g++ -c main.cpp
SeqQueueq.o: SeqQueue.cpp SeqQueue.h
	g++ -c SeqQueue.cpp
clean:
	rm -rf *.o
