#include<stdio.h>
#include "arbolBin.h"

int main(){
	tipoArbolBin arbol1,arbol2;
	int i,num,dim;

	nuevoArbolBin(&arbol1);
	nuevoArbolBin(&arbol2);

	printf("Cuantos numeros quieren que tenga el arbol : \n");
	scanf("%d",&dim);

	printf("Introduce %d numeros para crear el arbol: ",dim);
	scanf("%d",&num);
	arbol1=construir(num,NULL,NULL);
	for(i=1;i<=dim;i++){
		scanf("%d",&num);
		arbol2=construir(num,NULL,NULL);
		scanf("%d",&num);
		arbol1=construir(num,arbol1,arbol2);
	}
	printf("El elemento de la raiz es %d\n",devolverRaiz(arbol1));
	printf("El arbol es preorden // profundidad es: ");
	preorden(arbol1);
	printf("\n");
	printf("\nEl arbol es inorden es: ");
	inorden(arbol1);
	printf("\n");
	printf("\nEl arbol es postorden es: ");
	postorden(arbol1);
	printf("\n");
}
