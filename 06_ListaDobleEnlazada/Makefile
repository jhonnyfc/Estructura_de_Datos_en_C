all: colaDo

colaDo: colaDobleCaracteresFun.c ejecutarColaDobleCaracteres.c
	clear
	gcc -Wall -c colaDobleCaracteresFun.c
	gcc -Wall -g -o PA1-06_do ejecutarColaDobleCaracteres.c colaDobleCaracteresFun.o

play: PA1-06_do
	clear
	./PA1-06_do

delet:
	clear
	rm *.o
	rm PA1-06_do
