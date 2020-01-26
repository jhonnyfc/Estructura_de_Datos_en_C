#include <stdbool.h>

typedef int tipoElementoPila;

typedef struct celdaP{
	 tipoElementoPila elem;
	 struct celdaP *sig;
} celdaPila;

typedef celdaPila* tipoPila;

void nuevaPila(tipoPila *);

void apilar(tipoPila *, tipoElementoPila);

void desapilar(tipoPila *);

void borrar(tipoPila *, tipoElementoPila);

tipoElementoPila cima(tipoPila);

int esNulaPila(tipoPila);
