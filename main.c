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
  int padre; /* indice del padre en el arreglo de nodos  */
  int visitado; //variable considerada como boolena
  adyacentes *primerVecino;
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
adyacentes inicializaNodo(adyacentes aux, int valorIndice, int valorPeso){
    aux->indice= valorIndice;
    aux->peso = valorPeso;
    aux->sgte  = NULL;
    return auxiliar;
}

adyacentes devuelveListaVecinos(int i){
    adyacentes aux;
    aux=malloc(sizeof(adyacentes));
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
    int i=0;  //Se declara un indice para recorrer el arreglo "grafo".
    while (i<8){
        grafo[i].ID=i; //Se le asigna identificador al nodo
        grafo[i].nombreHosp=devuelveChar(i); //se asigna Nombre al nodo.
        grafo[i].primerVecino=devuelveListaVecinos(i); //Se estableces los vecinos predefinidos
        grafo[i].padre=-1; //Se establece que no hay padre
        grafo[i].visitado=0; //Se establece como nodo NO visitado
        i++;
    }
}

int main(){
    Nodo grafo[7]; //Se declara el grafo como arreglo
    printf("-Se Declaro Grafo \n ");
    if (inicializaG( grafo )) { //Se inicializa el grafo predefinido
        printf("-Se inicializo el grafo \n");
    }
    return 1;
}
