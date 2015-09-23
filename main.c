#include <stdio.h>
#include <stdlib.h>

typedef struct tipo_adyacentes{
  int indice;
  int peso;
  struct tipo_adyacentes *sgte;
}adyacentes;

typedef struct tipo_nodo{     /* se define un nodo generico para las dos tipos de busquedas*/
  int ID;       /* etiqueta */
  char nombreHosp;
  adyacentes *primerVecino;
  int padre; /* indice del padre en el arreglo de nodos  */
}Nodo;

char devuelveChar(int i){
    switch ( i )
		{
            case  0: return 'a';
            case  1: return 'b';
            case  2: return 'c';
            case  3: return 'd';
            case  4: return 'e';
            case  5: return 'f';
            case  6: return 'g';
            case  7: return 'h';

		}
}
adyacentes inicializaNodo(adyacentes auxiliar, int valorIndice, int valorPeso){
    auxiliar=malloc(sizeof(adyacentes));
    auxiliar->indice=valorIndice;
    auxiliar->peso=valorPeso;
    auxiliar->sgte=NULL;
    return auxiliar;
}

adyacentes devuelveListaVecinos(int i){
    adyacentes aux;
        switch ( i )
		{
            case  0:
                aux=inicializaNodo(aux, 1, 0);
            case  1:
                aux=inicializaNodo(aux, 2, 0);
                aux->sgte=inicializaNodo(aux->ste, 3, 0);
            case  2:
                aux=inicializaNodo(aux, 0, 0);
                aux->sgte=inicializaNodo(aux->sgte, 4, 0);
            case  3:
                aux=inicializaNodo(aux, 2, 0);
            case  4:
                aux=inicializaNodo(aux, 5, 0);
                aux->sgte=inicializaNodo(aux->sgte, 6, 0);
            case  5:
                aux=inicializaNodo(aux, 6, 0);
                aux-sgte=inicializaNodo(aux->sgte, 3, 0);
            case  6:
                aux=inicializaNodo(aux, 7, 0);
            case  7:
                aux=inicializaNodo(aux, 5, 0);
		}
		return aux;
}


int inicializaG(Nodo grafo[]){
    int i=0;
    while (i<8){
        grafo[i].ID=i;
        grafo[i].nombreHosp=devuelveChar(i);
        grafo[i].primerVecino=devuelveListaVecinos(i);
        grafo[i].padre=-1; //no hay padre
        i++;
    }
}


int main(){
    Nodo grafo[7];
    printf("-Se Declaro Grafo \n ");
    if (inicializaG( grafo )) {
        printf("-Se inicializo el grafo \n");
    }
    return 1;
}
