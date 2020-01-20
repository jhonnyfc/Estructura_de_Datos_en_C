#include<stdio.h>
#include "minMonticulo.h"
#include <stdlib.h>

void nuevoMinMonticulo(tipoMinMonticulo *rootMO, int dim){
	tipoMinMonticulo *moROOt;
	moROOt = (tipoMinMonticulo*)malloc(sizeof(tipoMinMonticulo));
	moROOt->numEl = dim;
	moROOt->pos = -1;
	moROOt->array = (int*)malloc(dim*sizeof(int));

	*rootMO = *moROOt;
}

void errorMinMonticulo(char s[]){
	printf("%s\n", s);
}

void insertarMinMonticulo(tipoMinMonticulo *rootMO, tipoElementoMinMonticulo elem){
	if (!estaLleno(*rootMO)){
		if (estaElem(*rootMO,elem) != -1){
			errorMinMonticulo("El elemto YA eSta en el monticulo\n");

		}else{
			rootMO->pos++;
			rootMO->array[rootMO->pos] = elem;

			//Hay que Reflotar el elemto par ponerlo
			//en la posicoin correspondinete
			//comparandolo con sus padres
			//en Estecaso en un MIN monticulo

			int pIn 	= rootMO->pos;
			int pPar 	= (pIn-1)/2;

			while(pPar >= 0 && (rootMO->array[pPar] > rootMO->array[pIn]) ){//Refolte
				//if ((*rootMO)->array[pPar] > (*rootMO)->array[pIn]){
					int aux = rootMO->array[pPar];
					rootMO->array[pPar] = rootMO->array[pIn];
					rootMO->array[pIn] = aux;
				//}

				pIn 	=  pPar;
			 	pPar 	= (pIn-1)/2;
			}
		}
	}else{
		errorMinMonticulo("El minMonticulo eStA LLeNo NO se Puede insertar\n");
	}
}

int estaElem(tipoMinMonticulo rootMO, tipoElementoMinMonticulo elem){
	if (!esVacio(rootMO))
		for (int i = 0; i <= rootMO.pos; ++i){
			if (rootMO.array[i] == elem){
				return i;
			}
		}

	return -1;
}

void eliminarElemento(tipoMinMonticulo *rootMO, tipoElementoMinMonticulo elem){
	int pOut;

	if (!esVacio(*rootMO)){
		if ((pOut = estaElem(*rootMO,elem)) == -1){
			errorMinMonticulo("El elemto NO esta en el monticulo no se Puede eliminar\n");
		}else{
			int pFi = rootMO->pos;

			rootMO->array[pOut] = rootMO->array[pFi];
			rootMO->pos--;

			//Hay que Hundir el elemto par ponerlo
			//en la posicoin correspondinete
			//comparandolo con sus hijos
			//en Estecaso en un MIN monticulo

			pFi = rootMO->pos;//atualizamos la posicon final auxiliar
			int lim 	= (pFi-1)/2;//la posicion del ultimo Nodo padre posible
			int pS 		= pOut;
			int pHI,pHD;

			if (pFi >= (pS*2+2)){
				pHI = pS*2+1;
				pHD = pS*2+2;
			}else if (pFi >= (pS*2+1)){
				pHI = pS*2+1;
				pHD = -1;
			}else{
				pHI = -1;
				pHD = -1;
			}

			while(pS <= lim){//Hundimiento
				if (pHD == -1 && pHI != -1){//Solo tine hijo izquierdo
					if (rootMO->array[pHI] < rootMO->array[pS]){
						int aux = rootMO->array[pHI];
						rootMO->array[pHI] = rootMO->array[pS];
						rootMO->array[pS] = aux;
					}
					pS = pHI;
				}else if (pHD != -1){//Tien hijo izquierdo y derecho
					if (rootMO->array[pHI] < rootMO->array[pHD]){//H izquierdo menor
						if (rootMO->array[pHI] < rootMO->array[pS]){
							int aux = rootMO->array[pHI];
							rootMO->array[pHI] = rootMO->array[pS];
							rootMO->array[pS] = aux;
						}
						pS = pHI;
					}else{//H derecho menor
						if (rootMO->array[pHD] < rootMO->array[pS]){
							int aux = rootMO->array[pHD];
							rootMO->array[pHD] = rootMO->array[pS];
							rootMO->array[pS] = aux;
						}
						pS = pHD;
					}
				}

				if (pFi >= pS*2+2){
					pHI = pS*2+1;
					pHD = pS*2+2;
				}else if (pFi >= pS*2+1){
					pHI = pS*2+1;
					pHD = -1;
				}else{//ESTE CASO PUED SER REDUNDATE YA QUE SEGUN
					pHI = -1;			//EL LIMTE DEL BUCLE SIMPRE TENDRA ALMENOS UN HIJO
					pHD = -1;
				}
			}
		}
	}else{
		errorMinMonticulo("El minMonticulo eS VacIO no se pued eliminar NaDa\n");
	}
}

tipoElementoMinMonticulo devolverRaiz(tipoMinMonticulo rootMO){
	if (!esVacio(rootMO))
		return rootMO.array[0];
	else{
		errorMinMonticulo("Es VacIO devROOT");
		return -999;// se tendira que hacer control de erro
					// en el main porgram
	}
}

void mostrarAnchura(tipoMinMonticulo rootMO){
	if (!esVacio(rootMO)){
		for (int i = 0; i <= rootMO.pos; ++i){
			printf("%d ",rootMO.array[i]);
		}
		printf("\n");

	}else{
		errorMinMonticulo("Es VacIO mosTraRAnChUrA\n");
	}
}

int esVacio(tipoMinMonticulo rootMO){
	return rootMO.pos == -1;
}

int estaLleno(tipoMinMonticulo rootMO){
	return rootMO.pos == rootMO.numEl-1;
}
