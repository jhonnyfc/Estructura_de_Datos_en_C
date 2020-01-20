all: pila

pila: ejecutarPilaEnteros.c
	clear
	gcc -Wall -c pilaEnterosDinamica.c 
	gcc -Wall -g -o PA1-01_Pila ejecutarPilaEnteros.c pilaEnterosDinamica.o

play: PA1-01_Pila
	clear
	./PA1-01_Pila

delet:
	clear
	rm *.o
	rm PA1-01_Pila
