#include <stdio.h>
#include <stdlib.h>
#include "colaEnterosLib.h"

void auxAltura(tipoArbolBB nodo, int a, int *alturam, int **alturamin);
void quintos(tipoArbolBB nodo, int a, int amin, int v[], int *y);
void borrarFamilia(tipoArbolBB *root, int v[], int dimension);
int AlturaArbol(tipoArbolBB root, int *hmax, int *hmin);
void printLevelOrder(tipoArbolBB *root);
int EsHoja(tipoArbolBB r);
int semiHoja(tipoArbolBB root);
int calcula(int hmax, int hmin);

int main(){
	tipoElementoArbolBusqueda elem;
	tipoArbolBB arbol;
	int opcion;

	nuevoArbolBB(&arbol);
	do
    {
		printf("--------MENU-------- \n");
		printf("1 - Insertar un elemento en el arbol\n");
		printf("2 - Eliminar un elemento del arbol\n");
		printf("3 - Mostrar el arbol en Preorden\n");
		printf("4 - Mostrar el arbol en Postorden\n");
		printf("5 - Mostrar el arbol en Inorden\n");
		printf("6 - Mostrar el arbol en Anchura/LevelOrder\n");
		printf("7 - Podar\n");
		printf("8 - Salir.\n");
		printf("Escoja una opcion: ");
		scanf("%d",&opcion);
		switch(opcion){
			case 1:
				printf("Introduce el entero: ");
				scanf("%d",&elem);
				insertar(&arbol,elem);
				break;
			case 2:
				printf("Introduce el entero: ");
				scanf("%d",&elem);
				borrar(&arbol,elem);
				break;
			case 3:
				printf("Los elementos del arbol en Preorden son:\n");
				mostrarPreorden(arbol);
				printf("\n");
				break;
			case 4:
				printf("Los elementos del arbol en Postorden son:\n");
				mostrarPostorden(arbol);
				printf("\n");
				break;
			case 5:
				printf("Los elementos del arbol en Inorden son:\n");
				mostrarInorden(arbol);
				printf("\n");
				break;
			case 6:
				printf("Los elementos del arbol en Anchura son:\n");
				printLevelOrder(&arbol);
				printf("\n");
				break;
			case 7:
				printf("\n");
				printf("El arbol antes de podar es Anchura: ");
				printLevelOrder(&arbol);
				printf("\n\n");

				int hmax,hmin;//n : numero de nodos a borarr
				AlturaArbol(arbol,&hmax,&hmin);
				printf("La altura maxima del arbol es %d\n", hmax);
				printf("La altura minima del arbol es %d\n", hmin);
				printf("Se esta podando:...\n");

				int n = calcula(hmax,hmin);
				if (n != 0){
					int *vec,dim = 0;
					vec = (int*)malloc(n*sizeof(int));
					quintos(arbol,1,hmin,vec,&dim);

					///PoDaDo
					borrarFamilia(&arbol,vec,dim);
					free(vec);

					printf("El arbol podado es: ");
					printLevelOrder(&arbol);
					printf("\n");
				}else
					printf("No hay nada que podar\n");
				break;
		}
		printf("\n");
	} while(opcion < 8);

	return 0;
}

void borrarFamilia(tipoArbolBB *root, int v[], int dimension){
	if (dimension > 0){
		printf("Los nodos a eliminar son: \n");
		for (int i=0; i<dimension; i++)
			printf("%d ",v[i]);
		printf("\n");
		for (int i=0; i<dimension; i++)
			borrar(&(*root),v[i]);
	}
	else {
		printf("No hay nada que podar\n");
		printf("\n");
	}
}

void quintos(tipoArbolBB nodo, int a, int amin, int v[], int *y){
	// Recorrido postorden
	if(nodo->izda != NULL)
		quintos(nodo->izda, a+1,amin,v,y);

	if(nodo->dcha != NULL)
		quintos(nodo->dcha, a+1,amin,v,y);
	//Proceso, si es un nodo hoja, y su altura es mayor que la actual del
	//	árbol, actualizamos la altura actual del árbol
	if(a > amin){
		v[*y] = nodo->elem;
		*y = (*y)+1;
		}

}

int calcula(int hmax, int hmin){
	int a,b;
	a = 1;
	b = 1;
	for (int i = 1; i <= hmin; i++)
		a = a*2;
	for (int i = 1; i <= hmax; i++)
		b = b*2;
	return b-a;
}

int AlturaArbol(tipoArbolBB root, int *hmax, int *hmin){
	if (!esVacio(root)){
		*hmax = 1;
		*hmin = 32000;
		auxAltura(root, 1, hmax,&hmin); /* Función auxiliar */
		return *hmax;
	}
	else{
		*hmin = 0;
		return *hmax = 0;
	}
}

/* Función auxiliar para calcular altura. Función recursiva de recorrido en
   postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
   altura de la máxima actual */
void auxAltura(tipoArbolBB nodo, int a, int *alturam, int **alturamin){
	/* Recorrido postorden */
	if(nodo->izda)
		auxAltura(nodo->izda, a+1, alturam,alturamin);
	if(nodo->dcha)
		auxAltura(nodo->dcha, a+1, alturam,alturamin);
	/* Proceso, si es un nodo hoja, y su altura es mayor que la actual del
		árbol, actualizamos la altura actual del árbol */
	if(EsHoja(nodo) && a > *alturam)
		*alturam = a;
	if(semiHoja(nodo) && a < *(*alturamin))
		*(*alturamin) = a;
}

int semiHoja(tipoArbolBB root){
	return !(root->dcha) || !(root->izda);
}

int EsHoja(tipoArbolBB root){
   return !(root->dcha) && !(root->izda);
}
