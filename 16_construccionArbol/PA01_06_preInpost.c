#include<stdio.h>
#include "arbolBin.h"

tipoArbolBin buildTree(int inOrd[], int preOrd[], int ini, int fin);
int search(int inOrd[], int ini, int fin, tipoElementoArbolBin value);

int main(){
	tipoArbolBin myTree;
	nuevoArbolBin(&myTree);

	int dim;
	printf("El programa construye el Arbol a partir de\n");
	printf("sus recorridos en inOrder y preOrder\n");
	printf("Introduce el numero de elementos: \n");
	//scanf("%d",&dim);
	dim = 9;
	printf("%d\n", dim);

	int inOrd[] = {2,7,4,8,1,5,3,9,6};	//Definir con dim
	int preOrd[] = {1,2,4,7,8,3,5,6,9};

	printf("Introduce la notacino en inOrden: \n");
	/*for (int i = 0; i< dim; i++){
		scanf("%d",&inOrd[i]);
	}*/
	for (int i = 0; i< dim; i++){
		printf("%d ",inOrd[i]);
	}
	printf("\n");

	printf("Introduce la notacino en preOrden: \n");
	/*for (int i = 0; i< dim; i++){
		scanf("%d",&preOrden[i]);
	}*/
	for (int i = 0; i< dim; i++){
		printf("%d ",preOrd[i]);
	}
	printf("\n");

	myTree = buildTree(inOrd,preOrd,0,dim-1);

	printf("El arbol en porstOrden es: \n");
	postorden(myTree);
	printf("\n");

	return 0;
}

tipoArbolBin buildTree(int inOrd[], int preOrd[], int ini, int fin){
	static int preIndex = 0;

	if ( (fin - ini) < 0){
		return NULL;
	}

	tipoArbolBin nodo;
	nodo = construir(preOrd[preIndex],NULL,NULL);
	preIndex++;

	if (ini == fin){
		return nodo;
	}

	int inIndex = search(inOrd,ini,fin,nodo->elem);

	nodo->izda = buildTree(inOrd,preOrd,ini,inIndex-1);
	nodo->dcha = buildTree(inOrd,preOrd,inIndex+1,fin);

	return nodo;
}

int search(int inOrd[], int ini, int fin, tipoElementoArbolBin value){
	for (int i = ini; i <= fin; i++) {
		if (inOrd[i] == value)
			return i;
	}
	return -1;
}
