all: SortminMon

SortminMon: minMonticuloFun.c PA1_05_SortMont.c
	clear
	gcc -Wall -c minMonticuloFun.c
	gcc -Wall -g -o PA1_05_Sort  PA1_05_SortMont.c minMonticuloFun.o

play: PA1_05_Sort
	clear
	./PA1_05_Sort

delet:
	clear
	rm *.o
	rm PA1_05_Sort
