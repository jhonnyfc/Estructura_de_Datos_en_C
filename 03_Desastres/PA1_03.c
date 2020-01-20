#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "pilaEnterosDinamica.h"

int clasficaDesastres(int dim, int col, int desatres[][col]);

int main() {
    //Variables
    int dim, col = 3;

    //Body
    printf("Introduzca el numero de desatres: ");
    scanf("%d",&dim);
    printf("\n");
    int desatres[dim][col];

    for (int i = 0; i < dim; i++){
        printf("Introduzca la fecha y el numero de victimas: ");
        scanf("%d %d",&desatres[i][0],&desatres[i][1]);
    }
    printf("\n");
    printf("CLasidicando...\n");
    clasficaDesastres(dim,col,desatres);

    printf("\n");
    printf("El resultado es:\n");
    for (int i = 0; i < dim; i++){
        printf("%d %d %d\n",desatres[i][0],desatres[i][1],desatres[i][2]);
    }

    return 0;
}

int clasficaDesastres(int dim, int col, int desatres[][col]){
    tipoPila pila;
    tipoElementoPila elem;

    nuevaPila(&pila);

    for (int i = 0; i < dim; i++) {
        if (esNulaPila(pila)){
            desatres[i][2] = 0;
            elem.a = desatres[i][0];
            elem.b = desatres[i][1];
            apilar(&pila,elem);
        }else if(desatres[i-1][1] > desatres[i][1]){
            desatres[i][2] = desatres[i-1][0];
            elem.a = desatres[i-1][0];
            elem.b = desatres[i-1][1];
            apilar(&pila,elem);
        }else{
            bool verf = true;
            while (!esNulaPila(pila) && verf){
                elem  = cima(pila);
                if (elem.b  < desatres[i][1]){
                    desapilar(&pila);
                }else{
                    verf = false;
                    desatres[i][2] = elem.a;
                }
            }
            if (esNulaPila(pila)){
                desatres[i][2] = 0;
                elem.a = desatres[i][0];
                elem.b = desatres[i][1];
                apilar(&pila,elem);
            }
        }
    }
    return 1;
}
