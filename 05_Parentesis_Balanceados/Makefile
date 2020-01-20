all: pila

pila: pilaEnterosDinamica.c PA1-05_equi.c
	clear
	gcc -Wall -c pilaEnterosDinamica.c
	gcc -Wall -g -o PA1-05_equi PA1-05_equi.c pilaEnterosDinamica.o

play: PA1-05_equi
	clear
	./PA1-05_equi

delet:
	clear
	rm *.o
	rm PA1-05_equi
