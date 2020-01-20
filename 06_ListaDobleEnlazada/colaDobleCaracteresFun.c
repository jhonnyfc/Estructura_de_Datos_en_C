#include <stdio.h>
#include <stdlib.h>
#include "colaDobleCaracteresLib.h"

void nuevaColaDoble(tipoColaDoble *colaDo){
    colaDo->ini = NULL;
    colaDo->fin = NULL;
}

void encolarPrimero(tipoColaDoble *colaDo, tipoElementoColaDoble elem){
    celdaColaDoble *aux;
    aux = (celdaColaDoble*)malloc(sizeof(celdaColaDoble));
    aux->elem = elem;

    if (esNulaColaDoble(*colaDo)){
        colaDo->ini = aux;
        colaDo->fin = aux;
        aux->ant = NULL;
        aux->sig = NULL;
    }else{
        colaDo->ini->ant = aux;
        aux->sig = colaDo->ini;
        colaDo->ini = aux;
        aux->ant = NULL;
    }
}

void encolarUltimo(tipoColaDoble *colaDo, tipoElementoColaDoble elem){
    celdaColaDoble *aux;
    aux = (celdaColaDoble*)malloc(sizeof(celdaColaDoble));
    aux->elem = elem;

    if (esNulaColaDoble(*colaDo) ){
        colaDo->ini = aux;
        colaDo->fin = aux;
        aux->ant = NULL;
        aux->sig = NULL;
    }else{
        colaDo->fin->sig = aux;
        aux->ant = colaDo->fin;
        colaDo->fin = aux;
        aux->sig = NULL;
    }
}

void desencolarPrimero(tipoColaDoble *colaDo){
    if (!esNulaColaDoble(*colaDo)){
        celdaColaDoble *aux;

        aux = colaDo->ini;

        if (aux->sig == NULL){
            colaDo->ini = NULL;
            colaDo->fin = NULL;
        }else{
            colaDo->ini = aux->sig;
            colaDo->ini->ant = NULL;
        }

        free(aux);
    }else{
        printf("La ColA eS VacIa\n");
    }
}

void desencolarUltimo(tipoColaDoble *colaDo){
    if (!esNulaColaDoble(*colaDo)){
        celdaColaDoble *aux;

        aux = colaDo->fin;

        if (aux->ant == NULL){
            colaDo->fin = NULL;
            colaDo->ini = NULL;
        }else{
            colaDo->fin = aux->ant;
            colaDo->fin->sig = NULL;
        }

        free(aux);
    }else{
        printf("La ColA eS VacIa\n");
    }
}

tipoElementoColaDoble elemPrimero(tipoColaDoble colaDo){
    if (!esNulaColaDoble(colaDo)){
        return colaDo.ini->elem;
    }else{
        printf("La ColA eS VacIa\n");
        return -1; //hacer control de error cuando se llama a esta funcion
    }
}

tipoElementoColaDoble elemUltimo(tipoColaDoble colaDo){
    if (!esNulaColaDoble(colaDo)){
        return colaDo.fin->elem;
    }else{
        printf("La ColA eS VacIa\n");
        return -1; //hacer control de error cuando se llama a esta funcion
    }
}

int esNulaColaDoble(tipoColaDoble colaDo){
    return colaDo.ini == NULL && colaDo.fin == NULL;
}
