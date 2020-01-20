#include<stdio.h>
#include "listaOrdenadaEnteros.h"
#include <stdbool.h>
#include <stdlib.h>

void nuevaLista(tipoLista *lisT){
	lisT->ini = NULL;
	lisT->fin = NULL;
}

void insertar(tipoLista *lisT, tipoElementoLista elem){//se insertan de menor a mayor
	celdaLista *aux;
	aux = (celdaLista*)malloc(sizeof(celdaLista));
	aux->elem = elem;

	if (esNulaLista(*lisT)){
		lisT->ini = aux;
		lisT->fin = aux;
		aux->ant = NULL;
		aux->sig = NULL;
	}else{
		if (elem < lisT->ini->elem){//Se inserta al prinicipio
			aux->sig = lisT->ini;
			aux->ant = NULL;
			lisT->ini->ant = aux;
			lisT->ini = aux;

		}else if (elem > lisT->fin->elem){//Se inserta al final
			aux->ant = lisT->fin;
			aux->sig = NULL;
			lisT->fin->sig = aux;
			lisT->fin = aux;

		}else{//se busa su posicion en la lista
			celdaLista *auxRe = lisT->ini;
			celdaLista *auxAnt;
			bool esMayor = true;

			while (auxRe != NULL && esMayor){
				if (elem > auxRe->elem)
					esMayor = false;
				auxAnt = auxRe;
				auxRe = auxRe->sig;
			}
			if (auxAnt->elem < elem && elem < auxRe->elem){
				auxAnt->sig = aux;
				auxRe->ant = aux;
				aux->ant = auxAnt;
				aux->sig = auxRe;
			}

		}
	}
}

void eliminarMenor(tipoLista *lisT){
	celdaLista *aux;

	if (!esNulaLista(*lisT)){
		aux = lisT->ini;
		lisT->ini = aux->sig;
		aux->sig->ant = NULL;
		free(aux);
	}else{
		printf("la lsita es nula\n");
	}
}

void eliminarMayor(tipoLista *lisT){
	celdaLista *aux;

	if (!esNulaLista(*lisT)){
		aux = lisT->fin;
		lisT->fin = aux->ant;
		aux->ant->sig = NULL;
		free(aux);
	}else{
		printf("la lsita es nula\n");
	}
}

tipoElementoLista consultarMenor(tipoLista lisT){
	if (!esNulaLista(lisT)){
		return lisT.ini->elem;
	}else{
		printf("la lsita es nula\n");
		return -999;
	}
}

tipoElementoLista consultarMayor(tipoLista lisT){
	if (!esNulaLista(lisT)){
		return lisT.fin->elem;
	}else{
		printf("la lsita es nula\n");
		return -999;
	}
}

int estaElemento(tipoLista lisT, tipoElementoLista elem){
	if (!esNulaLista(lisT)){
		celdaLista *auxRe = lisT.ini;
		celdaLista *auxAnt;
		int esMenor = 1;
		while (auxRe != NULL && esMenor){
			if (elem < auxRe->elem)
				esMenor = 0;
			auxAnt = auxRe;
			auxRe = auxRe->sig;
		}
		if (auxAnt->elem == elem){
			return 1;
		}else{
			return 0;
		}
		return 0;
	}else{
		printf("la lsita es nula\n");
		return 0;
	}
}

int esNulaLista(tipoLista lisT){
	return lisT.ini == NULL && lisT.fin == NULL;
}

void concatenar (tipoLista *lisT1, tipoLista *lisT2){

	/*while (esNulaLista(*lisT2)){
		insertar(lisT1,consultarMenor(lisT2));
		eliminarMenor(lisT2));
	}*/

	//ALgoritmo de concatenacion
	celdaLista *auxRe1 = lisT1->ini;
	celdaLista *auxRe2 = lisT2->ini;
	celdaLista *aux;
	tipoElementoLista elAux;

	while (auxRe2 != NULL) {//
		elAux = auxRe2->elem;

		if (auxRe1->elem > elAux) {//Insertar al prinicipio
			celdaLista *auxIn;
			auxIn = (celdaLista*)malloc(sizeof(celdaLista));

			auxIn->elem = elAux;
			auxIn->ant = NULL;
			auxRe1->ant = auxIn;
			auxIn->sig = auxRe1;
			lisT1->ini = auxIn;

		}else{
			int esMenor = 1;
			while (esMenor && auxRe1 != NULL){
				if (auxRe1->elem < elAux)
					esMenor = 0;
				aux = auxRe1;
				auxRe1 = auxRe1->sig;
			}

			if (auxRe1 == NULL){//al final
				celdaLista *auxIn;
				auxIn = (celdaLista*)malloc(sizeof(celdaLista));

				auxIn->elem = elAux;
				auxIn->ant = aux;
				auxIn->sig = NULL;
				aux->sig = auxIn;
				lisT1->fin = auxIn;

			}else if (aux->elem < elAux && elAux < auxRe1->elem){//en medio
				celdaLista *auxIn;
				auxIn = (celdaLista*)malloc(sizeof(celdaLista));

				auxIn->elem = elAux;
				auxIn->ant = aux;
				auxRe1->ant = auxIn;
				auxIn->sig = auxRe1;
				aux->sig = auxIn;
			}
		}

		//initialization
		auxRe1 = lisT1->ini;


		aux = auxRe2;
		auxRe2 = auxRe2->sig;
		free(aux);
	}
	free(auxRe2);

	lisT2->ini = NULL;
	lisT2->fin = NULL;
}

void imprimirLista (tipoLista lisT){
	if (!esNulaLista(lisT)){
		celdaLista *auxRe = lisT.ini;

		while (auxRe != NULL){
			printf("%d ", auxRe->elem);
			auxRe = auxRe->sig;
		}

		printf("\n");
	}else{
		printf("la lsita es nula\n");
	}
}
