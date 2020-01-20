all: arbolBin

arbolBin: arbolBinFun.c ejecutarArbolBin.c
	clear
	gcc -Wall -c arbolBinFun.c
	gcc -Wall -g -o PA1-01 ejecutarArbolBin.c arbolBinFun.o

play: PA1-01
	clear
	./PA1-01

delet:
	clear
	rm PA1-01
	rm *.o
