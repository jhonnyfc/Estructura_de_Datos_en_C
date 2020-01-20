#include "secuenciaEnterosLib.h"
#include <stdio.h>
#include <stdlib.h>

void nuevaSecuencia(tipoSecuencia* sec){
	nuevaPila(&sec->pilaIzq);
	nuevaPila(&sec->pilaDcha);
}

void insertarDelantePunto(tipoSecuencia* sec, tipoElementoPila elem){
	apilar(&sec->pilaIzq,elem);
}

void insertarEnPunto(tipoSecuencia* sec , tipoElementoPila elem){
	apilar(&sec->pilaDcha,elem);
}

void eliminarEnPunto(tipoSecuencia* sec){
	desapilar(&sec->pilaDcha);
}

tipoElementoPila consultarEnPunto(tipoSecuencia sec){
	return cima(sec.pilaDcha);
}

void avanzarPunto (tipoSecuencia* sec){
	apilar(&(sec->pilaDcha),cima(sec->pilaDcha));
	desapilar(&(sec->pilaIzq));
}

void moverPuntoAlPrincipio (tipoSecuencia* sec){
	while (!esNulaPila(sec->pilaIzq) ){
		apilar(&(sec->pilaDcha),cima(sec->pilaIzq));
		desapilar(&(sec->pilaIzq));
	}
}

bool esPuntoUltimo(tipoSecuencia sec){
	tipoElementoPila aux;
	bool verf = false;
	aux = cima(sec.pilaDcha);
	desapilar(&(sec.pilaDcha));
	if ( esNulaPila(sec.pilaDcha) )
		verf = true;

	apilar(&(sec.pilaDcha),aux);
	return verf;
}

bool esVaciaSecuencia(tipoSecuencia sec){
	return esNulaPila(sec.pilaIzq) && esNulaPila(sec.pilaDcha);
}
