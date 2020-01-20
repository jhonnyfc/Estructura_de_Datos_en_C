#include <stdlib.h>
#include <stdio.h>
#include "arbolBin.h"

void nuevoArbolBin(tipoArbolBin *raizR){
    raizR = NULL;/*
    raizR->izda = NULL;
    raizR->dcha = NULL*/
}

void errorArbolBin(char s[]){
    printf("XD %s\n",s);
}

tipoArbolBin construir(tipoElementoArbolBin eleM, tipoArbolBin raizR1, tipoArbolBin raizR2 ){
    tipoArbolBin  root;
    root = malloc(sizeof(celdaArbolBin));

    root->elem = eleM;
    root->izda = raizR1;
    root->dcha = raizR2;

    return root;
}

tipoElementoArbolBin devolverRaiz(tipoArbolBin raizR){
    return  raizR->elem;
}

void preorden(tipoArbolBin raizR){//Editar los printeos
    if (!esVacio(raizR)){
        printf("%d ",raizR->elem);
        if (raizR->izda != NULL){
            preorden(raizR->izda);
        }
        if (raizR->dcha != NULL){
            preorden(raizR->dcha);
        }
    }else{
        errorArbolBin("El aRboL EsVaCio XD\n");
    }
}

void inorden(tipoArbolBin raizR){
    if (!esVacio(raizR)){
        if (raizR->izda != NULL){
            printf("(");
            inorden(raizR->izda);
        }
        printf("%c",raizR->elem);
        if (raizR->dcha != NULL){
            inorden(raizR->dcha);
            printf(")");
        }
    }else{
        errorArbolBin("El aRboL EsVaCio XD\n");
    }
}

void postorden(tipoArbolBin raizR){
    if (!esVacio(raizR)){
        if (raizR->izda != NULL){
            postorden(raizR->izda);
        }
        if (raizR->dcha != NULL){
            postorden(raizR->dcha);
        }
        printf("%d ",raizR->elem);
    }else{
        errorArbolBin("El aRboL EsVaCio XD\n");
    }
}

int esVacio(tipoArbolBin raizR){
    return raizR == NULL;
}
