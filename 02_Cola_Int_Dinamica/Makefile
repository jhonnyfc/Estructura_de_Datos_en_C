all: cola

cola: ejecutarColaEnteros.c
	clear
	gcc -Wall -c colaEnterosFun.c 
	gcc -Wall -g -o PA1-02_Cola ejecutarColaEnteros.c colaEnterosFun.o

play: PA1-02_Cola
	clear
	./PA1-02_Cola

delet:
	clear
	rm *.o
	rm PA1-02_Cola
