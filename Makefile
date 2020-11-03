a.out: main.o task.o matrix.o
	c++ main.o task.o matrix.o

main.o: Main.cpp Matrix.h
	c++ -c Main.cpp

matrix.o: Matrix.cpp Matrix.h Task.h
	c++ -c Matrix.cpp

task.o: Task.cpp Task.h utility.h
	c++ -c Task.cpp