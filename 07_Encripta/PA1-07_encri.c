#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "colaDobleCaracteresLib.h"

int esVol(char c);
char* codificador(char frase[]);
int nuevaColaEncri(tipoColaDoble *colaF, char frase[]);

int main(){
    int op,maxSize = 100;
    char frase[maxSize];
    char *sol;
    printf("Quiere codificar 1, o decodificar un mensaje 2\n");
    scanf("%d", &op);
    getchar();

    if (op == 1){
        printf("Introduzca la frase a codificar\n");
        fgets(frase,maxSize,stdin);
        sol = codificador(frase);
        printf("%s\n", sol);
    }else if (op == 2){
        printf("Introduzca la frase a decodificar\n");
        fgets(frase,maxSize,stdin);
    }
}

char* codificador(char frase[]){

	tipoColaDoble colaFra,colaAux;
    nuevaColaEncri(&colaFra,frase);

    nuevaColaDoble(&colaAux);

    while (!esNulaColaDoble(colaFra)) {
        tipoElementoColaDoble el1,el2;

        el1 = elemPrimero(colaFra);
        desencolarPrimero(&colaFra);

        if  (!esNulaColaDoble(colaFra) ){
            el2 = elemPrimero(colaFra);

            if (!esVol(el1) && !esVol(el2)){
                encolarUltimo(&colaAux,el2);
                encolarUltimo(&colaAux,el1);
                desencolarPrimero(&colaFra);
            }else{
                encolarUltimo(&colaAux,el1);
            }
        }else{
            encolarUltimo(&colaAux,el1);
        }
    }
    while (!esNulaColaDoble(colaAux)) {
        tipoElementoColaDoble el1,el2;

        el1 = elemPrimero(colaAux);
        desencolarPrimero(&colaAux);

        if  (!esNulaColaDoble(colaAux)){
            el2 = elemUltimo(colaAux);
            desencolarUltimo(&colaAux);

            encolarUltimo(&colaFra,el1);
            encolarUltimo(&colaFra,el2);
        }else{
            encolarUltimo(&colaFra,el1);
        }
    }

    char *aux;
    int dim = strlen(frase);
    aux = (char*)malloc(dim*sizeof(char));

    int x = 0;
    while (!esNulaColaDoble(colaFra)){
        tipoElementoColaDoble el1;
        el1 = elemPrimero(colaFra);
        aux[x] = el1;
        desencolarPrimero(&colaFra);
        x++;
    }

    aux[x] = '\0';

    return aux;
}

int nuevaColaEncri(tipoColaDoble *colaF, char frase[]){
    tipoColaDoble *auxCol;
    auxCol = (tipoColaDoble*)malloc(sizeof(tipoColaDoble));
    nuevaColaDoble(auxCol);
    for (int i = 0; i < strlen(frase)-1; i++ ){
        encolarUltimo(auxCol,frase[i]);
    }

    *colaF = *auxCol;
    return 1;
}

int esVol(char c){
    char vocals[] = "aeiouáéíóúAEIOUÁÉÍÓÚ";

    int x = 0;

    for (int i = 0; i < strlen(vocals); i++ ){
        if (vocals[i] == c ){
            x = 1;
        }
    }
    return x;
}
