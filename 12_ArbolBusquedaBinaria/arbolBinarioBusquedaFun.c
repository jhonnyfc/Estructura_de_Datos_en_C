#include<stdio.h>
#include<stdlib.h>
#include "colaEnterosLib.h"

void nuevoArbolBB(tipoArbolBB *rootR){
	*rootR = NULL;
}

void errorArbolBB(char s[]){
	printf("%s\n", s);
}

void insertar(tipoArbolBB *rootR, tipoElementoArbolBusqueda elem){
	if (esVacio(*rootR)){
		/*celdaArbolBusqueda *newNodo;
		newNodo = (celdaArbolBusqueda*)malloc(sizeof(celdaArbolBusqueda));

		newNodo->elem = elem;

		newNodo->izda = NULL;
		newNodo->dcha = NULL;
		*rootR = newNodo;*/

		*rootR = malloc(sizeof(celdaArbolBusqueda));
		(*rootR)->elem = elem;

		(*rootR)->izda = (*rootR)->dcha = NULL;

	}else if ((*rootR)->elem == elem){
		errorArbolBB("El elemto ya esta en el arbol\n");

	}else if (elem < (*rootR)->elem){
		insertar(&(*rootR)->izda,elem);

	}else{
		insertar(&(*rootR)->dcha,elem);
	}
}

void borrar(tipoArbolBB *rootR, tipoElementoArbolBusqueda elem){
	if (esVacio(*rootR)){
		errorArbolBB("El aRboL EsVaCio XD BOrrar\n");

	}else if ((*rootR)->elem == elem){
		if (esVacio((*rootR)->izda) && esVacio((*rootR)->dcha)){//es HOJA
			free(*rootR);
			*rootR = NULL;

		}else if (esVacio((*rootR)->izda)){ // No tiene hijos izquierdos
				celdaArbolBusqueda *auxNodo;

				auxNodo = *rootR;
				*rootR = (*rootR)->dcha;

				free(auxNodo);

			}else if (esVacio((*rootR)->dcha)){ // No tine hjos derechos
				celdaArbolBusqueda *auxNodo;

				auxNodo = *rootR;
				*rootR = (*rootR)->izda;

				free(auxNodo);

			}else{//tiene dos hijos
				tipoElementoArbolBusqueda elemSuc = sucesor((*rootR)->dcha);

				(*rootR)->elem = elemSuc;

				borrar(&(*rootR)->dcha,elemSuc);
			}
	}else if(elem < (*rootR)->elem){
		borrar(&(*rootR)->izda,elem);
	}else{
		borrar(&(*rootR)->dcha,elem);
	}

}

tipoElementoArbolBusqueda sucesor(tipoArbolBB rootR){
    //elemento más pequeño del Arbol del subarbol hijo derecho
    if (esVacio(rootR->izda))
        return rootR->elem;
    else
        return sucesor(rootR->izda);
}

void mostrarPreorden(tipoArbolBB rootR){
    if (!esVacio(rootR)){
	    printf("%d ",rootR->elem);
	    if (!esVacio(rootR->izda)){
	        mostrarPreorden(rootR->izda);
	    }
	    if (!esVacio(rootR->dcha)){
	        mostrarPreorden(rootR->dcha);
	    }
    }else{
        errorArbolBB("El aRboL EsVaCio PRE XD\n");
    }
}

void mostrarInorden(tipoArbolBB rootR){
	if (!esVacio(rootR)){
        if (!esVacio(rootR->izda)){
            mostrarInorden(rootR->izda);
        }
        printf("%d ",rootR->elem);
        if (!esVacio(rootR->dcha)){
            mostrarInorden(rootR->dcha);
        }
    }else{
        errorArbolBB("El aRboL EsVaCio INO XD\n");
    }
}

void mostrarPostorden(tipoArbolBB rootR){
    if (!esVacio(rootR)){
	    if (!esVacio(rootR->izda)){
	        mostrarPostorden(rootR->izda);
	    }
	    if (!esVacio(rootR->dcha)){
	        mostrarPostorden(rootR->dcha);
	    }
	    printf("%d ",rootR->elem);
    }else{
        errorArbolBB("El aRboL EsVaCio POst XD\n");
    }
}

int esVacio(tipoArbolBB rootR){
	return rootR == NULL;
}

void printLevelOrder(tipoArbolBB *root) {
	celdaArbolBusqueda *auxTree = *root;
	tipoArbolBB treeOut;

	tipoCola myQueue;
	nuevaCola(&myQueue);
    encolar(&myQueue,*auxTree);
	nuevoArbolBB(&treeOut);

    while (!esNulaCola(myQueue)){
    	*auxTree = frente(myQueue);
    	desencolar(&myQueue);
        printf("%d ", (*auxTree).elem);
		insertar(&treeOut,(*auxTree).elem);

        //Enqueue left child
        if ( auxTree->izda != NULL)
        	encolar(&myQueue, *auxTree->izda);

        //Enqueue right child
        if ( auxTree->dcha != NULL)
        	encolar(&myQueue, *auxTree->dcha);
    }
	*root = treeOut;
    free(auxTree);
}
