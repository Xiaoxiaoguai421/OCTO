main: main.o SparseMatrix.o
	g++ -o main main.o SparseMatrix.o
main.o: main.cpp SparseMatrix.cpp SparseMatrix.h
	g++ -c main.cpp
SpareMatrix.o: SparseMatrix.cpp SparseMatrix.h
	g++ -c SparseMatrix.cpp
clean:
	rm -rf *.o
