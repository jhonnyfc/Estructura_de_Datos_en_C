all: minMon

minMon: minMonticuloFun.c ejecutarMinMonticulo.c
	clear
	gcc -Wall -c minMonticuloFun.c
	gcc -Wall -g -o PA1-03_minM ejecutarMinMonticulo.c minMonticuloFun.o

play: PA1-03_minM
	clear
	./PA1-03_minM

delet:
	clear
	rm *.o
	rm PA1-03_minM
