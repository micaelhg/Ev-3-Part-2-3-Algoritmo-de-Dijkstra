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
  int peso; //Peso
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

 /* ******************CODIGO DE DIJKSTRA**************************** */
 int iniciaNodos(nodo *unGrafo, int id)
{
     int i;
	 for (i=0; i< 8; i++)
     {
		 unGrafo[i].peso =999; //999=numero grande ~ inf
		 //unGrafo[i].peso=-1;
         unGrafo[i].IDpadre =-1;  //padre
     }
     unGrafo[id].peso=0;  //valor del peso del punto de partida
     unGrafo[id].visitado=1;
     return 0;
}

int relax(nodo *unGrafo, int unaID, int otraID)
{
	if (unGrafo[otraID].peso > unGrafo[unaID].peso + 1)
	{
		unGrafo[otraID].peso = unGrafo[unaID].peso + 1;  //actualiza peso de nodo adyacente
		unGrafo[otraID].IDpadre= unaID;  //actualiza padre de nodo adyacente
	}
	return 0;
}

int dijkstra(nodo unGrafo[], int idInicial, int idFinal)
{
	int cant_visitados, cont=0;
	iniciaNodos(unGrafo, idInicial);
	int idMinima = idInicial;
	do
	{
	    int i;
        for (i=0; i< 8; i++)
		{
			if (unGrafo[i].peso < unGrafo[idMinima].peso && unGrafo[i].visitado!=1)
			{
				idMinima=i;
			}
		}
		cant_visitados++;
		if (idMinima==idFinal)
		{
			printf("encontrado camino mas corto: %i\n", unGrafo[idMinima].peso);
			return EXIT_SUCCESS;
		}
		else
		{
            adyacentes *temp = unGrafo[idMinima].primerVecino;
			while (temp->sgte!=NULL)
			{
                cont++;
				relax(unGrafo, idMinima, temp->indice);
				temp=temp->sgte;
			}
		}
	} while (cant_visitados<=8);
	return EXIT_FAILURE;
}
 /* *************************************************************** */

int main(){
    nodo grafo[8]; //Se declara el grafo como arreglo
    printf("-Se Declaro Grafo... ");
    inicializaG( grafo );
    printf("Se Inicializo Grafo \n");
    dijkstra(grafo, 0 , 7);
    printf("::::::::::::::::::::EL PROGRAMA HA TERMINADO::::::::::::::::::::  \n ");
    return 0;
}

