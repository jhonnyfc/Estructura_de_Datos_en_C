#include <stdio.h>
#include <string.h>

#include"pilaEnterosDinamica.h"
//#include "pilaEnterosEstatica.h"

//En este programa comprobamos si los parentesis estan balanceados
// () = 1, [] = 2, {} =3
int main(){
	int 				maxSize = 100, balanceado = 1;
	char				frase[maxSize];
	tipoPila 			pilaBal;

	nuevaPila(&pilaBal);

	printf("Introduzca la frase: ");
	fgets(frase,maxSize,stdin);

	//printf("%s %ld\n", frase, strlen(frase));

	int i = 0;
	while (balanceado && i < (strlen(frase)-1) ) {
		if (frase[i] == '('){
			apilar(&pilaBal,1);
		}else if (frase[i] == '['){
			apilar(&pilaBal,2);
		}else if (frase[i] == '{'){
			apilar(&pilaBal,3);

		}else if (frase[i] == ')'){
			if (cima(pilaBal) != 1)
				balanceado = 0;
			else
				desapilar(&pilaBal);
		}else if (frase[i] == ']'){
			if (cima(pilaBal) != 2)
				balanceado = 0;
			else
				desapilar(&pilaBal);
		}else if (frase[i] == '}'){
			if (cima(pilaBal) != 3)
				balanceado = 0;
			else
				desapilar(&pilaBal);
		}
		i++;
	}

	printf("\n");
	if (balanceado == 1 ) {
		printf("Los parentesis estan balanceados\n");
	}else
		printf("Los parentesis NO estan balanceados\n");
	return 0;
}
