main: main.o funcs.o
	g++ -o main main.o funcs.o

funcs.o: funcs.cpp funcs.h

main.o: main.cpp funcs.h


clean:
	rm -f main.o funcs.o  main tests