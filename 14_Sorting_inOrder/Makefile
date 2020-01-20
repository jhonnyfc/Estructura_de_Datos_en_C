all: arbolBusBin

arbolBusBin: arbolBinarioBusquedaFun.c PA1_04_SortBB.c
	clear
	gcc -Wall -c arbolBinarioBusquedaFun.c
	gcc -Wall -g -o PA1_04_SBB PA1_04_SortBB.c arbolBinarioBusquedaFun.o

play: PA1_04_SBB
	clear
	./PA1_04_SBB

delet:
	clear
	rm *.o
	rm PA1_04_SBB
