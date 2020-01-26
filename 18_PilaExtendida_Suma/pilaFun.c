#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "pilaExtendida.h"

void nuevaPila(tipoPila *stack){
	*stack = NULL;
}

void apilar(tipoPila *stack, tipoElementoPila elem){
	celdaPila *auxSt;

	auxSt = (celdaPila*)malloc(sizeof(celdaPila));
	auxSt->elem = elem;

	if (esNulaPila(*stack)){
		auxSt->sig = NULL;
		*stack = auxSt;
	}else{
		auxSt->sig = *stack;
		*stack = auxSt;
	}
}

void desapilar(tipoPila *stack){
	if (!esNulaPila(*stack)){
		celdaPila *aux;
		aux = *stack;
		*stack = (*stack)->sig;
		free(aux);
	}
}

void borrar(tipoPila *stack, tipoElementoPila elem){
	tipoPila auxStack;
	nuevaPila(&auxStack);

	if (!esNulaPila(*stack)){
		while (!esNulaPila(*stack)){
			if (cima(*stack) != elem)
				apilar(&auxStack,cima(*stack));
			desapilar(&(*stack));
		}

		while (!esNulaPila(auxStack)){
			apilar(&(*stack),cima(auxStack));
			desapilar(&auxStack);
		}
	}
}

tipoElementoPila cima(tipoPila stack){
	if (!esNulaPila(stack))
		return stack->elem;
	else
		return -999;
}

int esNulaPila(tipoPila stack){
	return stack == NULL;
}
