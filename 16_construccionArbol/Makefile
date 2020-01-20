all: arbolBin

arbolBin: arbolBinFun.c PA01_06_preInpost.c
	clear
	gcc -Wall -c arbolBinFun.c
	gcc -Wall -g -o PA01_06_cons PA01_06_preInpost.c arbolBinFun.o

play: PA01_06_cons
	clear
	./PA01_06_cons

delet:
	clear
	rm *.o
	rm PA01_06_cons
