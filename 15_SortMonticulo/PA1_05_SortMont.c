#include<stdio.h>
#include "minMonticulo.h"

void reflote(tipoMinMonticulo *minMon, int N);
/****************************/
void intercambio(tipoMinMonticulo *minMon,int a,int b);

int main(){
	int numEl;
	tipoElementoMinMonticulo elem;
	tipoMinMonticulo minMon;

	printf("Introduzca todos el numero de elemntos a ordenar: ");
	scanf("%d",&numEl);
	nuevoMinMonticulo(&minMon,numEl);

	printf("Introduzca los elemntos a ordenar: ");
	for (int i = 0; i < numEl; ++i){
		scanf("%d",&elem);
		insertarMinMonticulo(&minMon,elem);
	}

	for (int i=numEl; i>0; i--){
		reflote(&minMon,i);
		intercambio(&minMon,i-1,0);
	}

	printf("\n");
	printf("Los elemntos ordenados son\n");
	mostrarAnchura(minMon);
	return 0;
}

void reflote(tipoMinMonticulo *minMon, int dim){
	for (int i=dim-1; i>0; i--){
		if (minMon->array[(i+1)/2-1] < minMon->array[i])
			intercambio(minMon,(i+1)/2-1,i);
	}
}
/***************************************/
void intercambio(tipoMinMonticulo *minMon,int a,int b){
	tipoElementoMinMonticulo aux;
	aux = minMon->array[a];
	minMon->array[a] = minMon->array[b];
	minMon->array[b] = aux;
}