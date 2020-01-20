typedef struct tipoElementoPila{
    int a,b;
} tipoElementoPila;

typedef struct celdaP{
    tipoElementoPila elem;
    struct celdaP *sig;
} celdaPila;

typedef celdaPila* tipoPila;

void nuevaPila(tipoPila *);

void apilar(tipoPila *, tipoElementoPila);

void desapilar(tipoPila *);

tipoElementoPila cima(tipoPila);

int esNulaPila(tipoPila);
