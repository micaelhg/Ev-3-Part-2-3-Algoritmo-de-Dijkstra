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
}nodo;

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

void inicializaVecino(adyacentes *aux, int valorIndice, int valorPeso){
    aux->indice= valorIndice;
    aux->peso = valorPeso;
    aux->sgte  = NULL;
}

adyacentes *devuelveListaVecinos(int i){
    adyacentes *aux;
    aux=(adyacentes*)malloc(sizeof(adyacentes));

    if (i==0){ inicializaVecino(aux, 1, 0);printf("0\n");}
    if (i==1){printf("1\n");
        inicializaVecino(aux, 2, 0);
         aux->sgte=(adyacentes*)malloc(sizeof(adyacentes));
        inicializaVecino(aux->sgte, 3, 0);}
    if (i==2){printf("2\n");
        inicializaVecino(aux, 0, 0);
        aux->sgte=(adyacentes*)malloc(sizeof(adyacentes));
        inicializaVecino(aux->sgte, 4, 0);}
    if (i==3){printf("3\n"); inicializaVecino(aux, 2, 0);}
    if (i==4){printf("4\n");
        inicializaVecino(aux, 5, 0);
        aux->sgte=(adyacentes*)malloc(sizeof(adyacentes));
        inicializaVecino(aux->sgte, 6, 0);}
    if (i==5){printf("5\n");
        inicializaVecino(aux, 6, 0);
        aux->sgte=(adyacentes*)malloc(sizeof(adyacentes));
        inicializaVecino(aux->sgte, 3, 0);}
    if (i==6){printf("6\n");inicializaVecino(aux, 7, 0);}
    if (i==7){printf("7\n");inicializaVecino(aux, 5, 0);}

    return aux;
}


void  inicializaG(nodo grafo[]){
    int i=0;  //Se declara un indice para recorrer el arreglo "grafo".
    while (i<8){
        grafo[i].ID=i; //Se le asigna identificador al nodo
        grafo[i].nombreHosp=devuelveChar(i); //se asigna Nombre al nodo.
        grafo[i].primerVecino=devuelveListaVecinos(i); //Se estableces los vecinos predefinidos
        grafo[i].padre=-1; //Se establece que no hay padre
        grafo[i].visitado=0; //Se establece como nodo NO visitado
        i++;printf("i=%d \n",i);
    }

}


int main(){
    nodo grafo[7]; //Se declara el grafo como arreglo
    printf("-Se Declaro Grafo \n ");
    inicializaG( grafo );

    // Dijkstra();
     printf("ID: %i \n", grafo[4].ID);
    printf("nombre: %c \n", grafo[4].nombreHosp);
     printf("indice del primer adyacente: %i \n", grafo[4].primerVecino->indice);
         printf("::::::::::::::::::::EL PROGRAMA HA TERMINADO:::::::::::::::::::::  \n ");

    return 0;
}
