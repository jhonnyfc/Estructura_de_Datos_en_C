all: arbolBin

arbolBin: arbolBinFun.c pilaDinamicaFun.c PA1_05_pti_1.c
	clear
	gcc -Wall -c arbolBinFun.c
	gcc -Wall -c pilaDinamicaFun.c
	gcc -Wall -g -o PA1_05_o1 PA1_05_pti_1.c arbolBinFun.o pilaDinamicaFun.o

play: PA1_05_o1
	clear
	./PA1_05_o1

delet:
	clear
	rm *.o
	rm PA1_05_o1
