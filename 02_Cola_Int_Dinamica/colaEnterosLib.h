typedef int tipoElementoCola;

typedef struct celdaCola{
    tipoElementoCola elem;
    struct celdaCola *sig;
} celdaCola;

typedef struct tipoCola{
    celdaCola* ini;
    celdaCola* fin;
}tipoCola;

void errorPila(char s[]);

void nuevaCola(tipoCola *);

void encolar(tipoCola *, tipoElementoCola);

void desencolar(tipoCola *);

tipoElementoCola frente(tipoCola);

int esNulaCola(tipoCola);
