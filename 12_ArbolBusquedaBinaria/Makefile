all: arbolBusBin

arbolBusBin: arbolBinarioBusquedaFun.c ejecutarArbolBB.c
	clear
	gcc -Wall -c colaEnterosFun.c 
	gcc -Wall -c arbolBinarioBusquedaFun.c
	gcc -Wall -g -o PA1-02_BB ejecutarArbolBB.c arbolBinarioBusquedaFun.o colaEnterosFun.o

play: PA1-02_BB
	clear
	./PA1-02_BB

delet:
	clear
	rm *.o
	rm PA1-02_BB
