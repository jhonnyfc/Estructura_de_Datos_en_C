all: lista

lista: listaOrdenadaIntFun.c ejecutarListaOrdenadaEnteros.c
	clear
	gcc -Wall -c listaOrdenadaIntFun.c
	gcc -Wall -g -o PA1-09 ejecutarListaOrdenadaEnteros.c listaOrdenadaIntFun.o

play: PA1-09
	clear
	./PA1-09

delet:
	clear
	rm *.o
	rm PA1-09
