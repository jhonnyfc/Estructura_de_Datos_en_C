typedef int tipoElementoMinMonticulo;

typedef struct tMM{
	tipoElementoMinMonticulo *array;
	int pos;
	int numEl;
}tipoMinMonticulo;

void nuevoMinMonticulo(tipoMinMonticulo*, int);

void errorMinMonticulo(char s[]);

void insertarMinMonticulo(tipoMinMonticulo *, tipoElementoMinMonticulo);

void eliminarElemento(tipoMinMonticulo *, tipoElementoMinMonticulo);

tipoElementoMinMonticulo devolverRaiz(tipoMinMonticulo);

void mostrarAnchura(tipoMinMonticulo);

int esVacio(tipoMinMonticulo);

int estaLleno(tipoMinMonticulo);

int estaElem(tipoMinMonticulo rootMO, tipoElementoMinMonticulo elem);
