all: hw2

hw2: main.o Number.o Atom.o Variable.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 main.o Number.o Atom.o Variable.o -lgtest
else
	g++ -o hw2 main.o Number.o Atom.o Variable.o -lgtest -lpthread
endif

main.o: main.cpp utTerm.h
	g++ -std=gnu++0x -c main.cpp
Number.o: Number.h Number.cpp
	g++ -std=gnu++0x -c Number.cpp
Atom.o: Atom.h Atom.cpp
	g++ -std=gnu++0x -c Atom.cpp
Variable.o: Variable.h Variable.cpp
	g++ -std=gnu++0x -c Variable.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw2
endif

