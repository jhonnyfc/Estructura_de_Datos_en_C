all: secu

secu: ejecutarSecuenciaEnteros.c pilaEnterosDinamica.c secuenciaEnterosFun.c
	clear
	gcc -Wall -c pilaEnterosDinamica.c
	gcc -Wall -c secuenciaEnterosFun.c
	gcc -Wall -g -o PA1-03_Sec ejecutarSecuenciaEnteros.c secuenciaEnterosFun.o pilaEnterosDinamica.o
	#gcc -Wall -g -o PA1-03_Sec secuenciaEnterosFun.c pilaEnterosDinamica.c ejecutarSecuenciaEnteros.c

play: PA1-03_Sec
	clear
	./PA1-03_Sec

delet:
	clear
	rm *.o
	rm PA1-03_Sec
