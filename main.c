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
  int IDpadre; /* indice del padre en el arreglo de nodos  */
  int visitado; //variable considerada como boolena
  int mejorCamino; //Peso
  adyacentes *primerVecino;
}nodo;


//Funcion que devuelve el nombre del Hospital segun el caso
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


//Esta funcion devuelve el primer puntero a PimerVecino ya que es un grafo prediseñado
adyacentes *devuelveListaVecinos(int i){
    adyacentes *aux;
    aux=(adyacentes*)malloc(sizeof(adyacentes));

    if (i==0){
            inicializaVecino(aux, 1, 0);}
    if (i==1){
        inicializaVecino(aux, 2, 0);
         aux->sgte=(adyacentes*)malloc(sizeof(adyacentes));
        inicializaVecino(aux->sgte, 3, 0);}
    if (i==2){
        inicializaVecino(aux, 0, 0);
        aux->sgte=(adyacentes*)malloc(sizeof(adyacentes));
        inicializaVecino(aux->sgte, 4, 0);}
    if (i==3){
         inicializaVecino(aux, 2, 0);}
    if (i==4){
        inicializaVecino(aux, 5, 0);
        aux->sgte=(adyacentes*)malloc(sizeof(adyacentes));
        inicializaVecino(aux->sgte, 6, 0);}
    if (i==5){
        inicializaVecino(aux, 6, 0);
        aux->sgte=(adyacentes*)malloc(sizeof(adyacentes));
        inicializaVecino(aux->sgte, 3, 0);}
    if (i==6){
        inicializaVecino(aux, 7, 0);}
    if (i==7){
        inicializaVecino(aux, 5, 0);}
    return aux;
}


void  inicializaG(nodo grafo[]){
    int i=0;  //Se declara un indice para recorrer el arreglo "grafo".
    while (i<8){
        grafo[i].ID=i; //Se le asigna identificador al nodo
        grafo[i].nombreHosp=devuelveChar(i); //se asigna Nombre al nodo.
        grafo[i].primerVecino=devuelveListaVecinos(i); //Se estableces los vecinos predefinidos
        i++;
    }
}


int main(){
    nodo grafo[8]; //Se declara el grafo como arreglo
    printf("-Se Declaro Grafo \n");
    inicializaG( grafo );
    printf("-Se Inicializo Grafo \n");


    // Dijkstra();

     printf("::::::::::::::::::::EL PROGRAMA HA TERMINADO::::::::::::::::::::  \n ");

    return 0;
}

