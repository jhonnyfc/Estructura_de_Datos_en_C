#include <stdio.h>
#include <stdlib.h>
#include "colaEnterosLib.h"

void nuevaCola(tipoCola *c){
	c->ini = NULL;
	c->fin = NULL;
}

void encolar(tipoCola *c, tipoElementoCola elem){
	celdaCola *aux;
	aux = (celdaCola*)malloc(sizeof(celdaCola));
	aux->elem = elem;

	if (esNulaCola(*c)){
		c->ini = aux;
		c->fin = aux;
		aux->sig = NULL;
	}
	else{
		aux->sig = NULL;
		c->fin->sig = aux;
		c->fin  = aux;
	}
}

void desencolar(tipoCola *c){
	celdaCola *aux;

	if (!esNulaCola(*c)){
		aux = c->ini;
		c->ini = c->ini->sig;

		if (c->ini == NULL){
			c->fin = NULL;
		}
		free(aux);
	}
}

tipoElementoCola frente(tipoCola c){
	if (!esNulaCola(c)){
		return c.ini->elem;
	}
}

int esNulaCola(tipoCola c){
	return c.ini == NULL && c.fin == NULL;
}
