main:  main.o vote.o
 
main.o: main.cpp vote.h
	g++ -c main.cpp
 
vote.o: vote.cpp vote.h
	g++ -c vote.cpp
.PHONY:. clean
clean:
		rm *.o main
