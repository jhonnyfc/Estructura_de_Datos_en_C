#include <stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include "arbolBinarioBusqueda.h"

int main(){
	tipoArbolBB treeBB;
	nuevoArbolBB(&treeBB);

	printf("Program que utiliza la funcion mostrar inOrden del arbol\n");
	printf("binario para ordeanr los numeros\n");
	printf("Introduce elementos para ordenar. 0 para terminar: \n");

	int inNum;
	scanf("%d",&inNum);
	while (inNum != 0){
		insertar(&treeBB,inNum);
		scanf("%d",&inNum);
	}
	if (!esVacio(treeBB)){
		printf("Los numeros ordenados son: \n");
		mostrarInorden(treeBB);
		printf("\n");
	}else{
		printf("No se ha introducido nuingun dato valido \n");

	}
	return 0;
}