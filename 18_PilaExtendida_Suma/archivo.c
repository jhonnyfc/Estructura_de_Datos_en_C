#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "pilaExtendida.h"

int sumaStacks(tipoPila *,tipoPila *);

int main (){
	tipoPila myStack1,myStack2;
	nuevaPila(&myStack1);
	nuevaPila(&myStack2);
	printf("*******************************************************\n");
	printf("**  El programa solo considera numeros entre 0 y 9  ***\n");
	printf("*******************************************************\n\n");

	printf("Introduce los digitos del primer numero, separado por espacions. \n");
	printf("Para terminar, introduce 111 \n");
	tipoElementoPila num;
	scanf("%d",&num);
	while(num != 111){
		if (num > -1 || num < 10){
			apilar(&myStack1,num);
			scanf("%d",&num);
		}
	}

	printf("\nIntroduce los digitos del segunda numero, separado por espacions. \n");
	printf("Para terminar, introduce 111 \n");
	scanf("%d",&num);
	while(num != 111){
		if (num > -1 || num < 10){
			apilar(&myStack2,num);
			scanf("%d",&num);
		}
	}

	tipoElementoPila minValido,maxValido;

	printf("\nIntroduce el menor digito valido: \n");
	scanf("%d",&minValido);
	printf("Introduce el mayor digito valido:\n");
	scanf("%d",&maxValido);

	for (int i = maxValido+1; i < 10; i++){
		borrar(&myStack1,i);
		borrar(&myStack2,i);
	}
	for (int i = minValido-1; i > -1; i--){
		borrar(&myStack1,i);
		borrar(&myStack2,i);
	}

	/*
	printf("\n");
	while (!esNulaPila(myStack1)){
		printf("%d",cima(myStack1));
		desapilar(&myStack1);
	}
	printf(" + ");
	while (!esNulaPila(myStack2)){
		printf("%d",cima(myStack2));
		desapilar(&myStack2);
	}
	printf("= ");s*/

	printf("\nLa suma es: %d \n",sumaStacks(&myStack1,&myStack2) );
	return 0;
}

int sumaStacks(tipoPila *Stack1,tipoPila *Stack2){
	int suma = 0;
	int sumaux = 0;
	int it=1;
	tipoPila myStack1 = *Stack1;
	tipoPila myStack2 = *Stack2;

	while (!esNulaPila(myStack1) && !esNulaPila(myStack2)){
		sumaux = cima(myStack1) + cima(myStack2) + sumaux;
		if (sumaux >= 10){
			int sumxd = (sumaux-10);
			sumaux = 1;
			suma = suma + sumxd*it;
		}else{
			suma = suma + sumaux*it;
			sumaux = 0;
		}
		it = it * 10;
		desapilar(&myStack1);
		desapilar(&myStack2);
	}

	while(!esNulaPila(myStack1)){
		sumaux = cima(myStack1) + sumaux;
		if (sumaux >= 10){
			int sumxd = (sumaux-10);
			sumaux = 1;

			suma = suma + sumxd*it;
		}else{
			suma = suma + sumaux*it;
			sumaux = 0;
		}
		it = it * 10;
		desapilar(&myStack1);
	}

	while(!esNulaPila(myStack2)){
		sumaux = cima(myStack2) + sumaux;
		if (sumaux >= 10){
			int sumxd = (sumaux-10);
			sumaux = 1;
			suma = suma + sumxd*it;
		}else{
			suma = suma + sumaux*it;
			sumaux = 0;
		}
		it = it * 10;
		desapilar(&myStack2);
	}

	if (sumaux == 1){
		suma = suma + sumaux *it;
	}

	return suma;
}
