#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilaDinamicaLib.h"


int esCandidato(char c);

int main (){
	char expre[100];
	tipoArbolBin myTree;
	tipoPila myStack;

	nuevoArbolBin(&myTree);
	nuevaPila(&myStack);

	printf("\t\tPosfija: 531-*42-+\n\n");
	printf("Escribe la expresion en Notacion Posfija: ");
	scanf("%s",expre);
	for (int i=0; i < strlen(expre); i++){
		if (esCandidato(expre[i])){
			tipoElementoPila aux1,aux2;
			aux1 = cima(myStack);
			desapilar(&myStack);
			if (!esNulaPila(myStack)){
				aux2 = cima(myStack);
				desapilar(&myStack);
				myTree = construir(expre[i],aux1,aux2);
			}else{
				myTree = construir(expre[i],aux1,NULL);
			}
		}else{
			myTree = construir(expre[i],NULL,NULL);
		}
		apilar(&myStack,myTree);
	}

	printf("La expresion en Notacion Infija es: ");
	inorden(myTree);
	printf("\n");
	return 0;
}

int esCandidato(char c){
	return (c  < '0') || ('9' < c);//is a number?¿
}
