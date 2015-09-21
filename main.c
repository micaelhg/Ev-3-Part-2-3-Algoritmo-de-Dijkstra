#include <stdio.h>
#include <stdlib.h>

typedef struct tipo_adyacentes{
  int indice;
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

adyacentes devuelvePrimerVecino(int i){
        switch ( i )
		{
            case  0: return (a);
            case  1: return 'b';
            case  2: return 'c';
            case  3: return 'd';
            case  4: return 'e';
            case  5: return 'f';
            case  6: return 'g';
            case  7: return 'h';


		}
}


int inicializaG(Nodo grafo[] ){
    int i=0;
    while (i<8){
        grafo[i].ID=i;
        grafo[i].nombreHosp=devuelveChar(i);
       // grafo[i]->primerVecino=devuelvePrimerVecino(i);
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
