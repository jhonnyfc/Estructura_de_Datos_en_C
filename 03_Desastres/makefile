all: desatres

desatres: pilaEnterosDinamica.c PA1_03.c
	clear
	gcc -Wall -c pilaEnterosDinamica.c
	gcc -Wall -g -o PA1_03 PA1_03.c pilaEnterosDinamica.o

play: PA1_03
	clear
	./PA1_03

delet:
	clear
	rm *.o
	rm PA1_03
	
