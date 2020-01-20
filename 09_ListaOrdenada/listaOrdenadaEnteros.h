typedef int tipoElementoLista;

typedef struct celdaL{
    tipoElementoLista elem;
    struct celdaL *sig;
    struct celdaL *ant;
}celdaLista;

typedef struct tipoL{
    celdaLista *ini;
    celdaLista *fin;
}tipoLista;

void nuevaLista(tipoLista *);

void insertar(tipoLista *, tipoElementoLista);

void eliminarMenor(tipoLista *);

void eliminarMayor(tipoLista *);

tipoElementoLista consultarMenor(tipoLista);

tipoElementoLista consultarMayor(tipoLista);

int estaElemento(tipoLista, tipoElementoLista);

int esNulaLista(tipoLista);

void concatenar (tipoLista *, tipoLista *);

void imprimirLista (tipoLista);
