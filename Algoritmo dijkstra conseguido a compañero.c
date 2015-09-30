/*
 * dijkstra_final.h
 *
 * El .h ordenado y sin tanto comentario :D
 */

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

//#include "Heap.h"
#include "ListaAdyacencia.h"

int iniciaNodos();
int relax();

int iniciaNodos(Grafo *unGrafo, int id)
{
	 for (int i=0; i<TAM; i++)
     {
		 unGrafo->nodos[i]->peso=999; //999=numero grande ~ inf
         unGrafo->nodos[i]->idPadre=-1;  //padre
     }
     unGrafo->nodos[id]->peso=0;  //valor del peso del punto de partida
     unGrafo->nodos[id]->visitado=1;
     return 0;
}


int relax(Grafo *unGrafo, int unaID, int otraID)
{
	if (unGrafo->nodos[otraID]->peso > unGrafo->nodos[unaID]->peso + 1)
	{
		unGrafo->nodos[otraID]->peso = unGrafo->nodos[unaID]->peso + 1;  //actualiza peso de nodo adyacente
		unGrafo->nodos[otraID]->idPadre = unaID;  //actualiza padre de nodo adyacente
	}
	return 0;
}


int b_dijkstra(Grafo *unGrafo, int idInicial, int idFinal)
{
	int cant_visitados, cont=0;
	iniciaNodos(unGrafo, idInicial);
	int idMinima = idInicial;
	do
	{
		for (int i=0; i<TAM; i++)
		{
			if (unGrafo->nodos[i]->peso < unGrafo->nodos[idMinima]->peso && unGrafo->nodos[i]->visitado!=1)
			{
				idMinima=i;
			}
		}
		cant_visitados++;
		if (idMinima==idFinal)
		{
			printf("encontrado camino mas corto: %i\n", unGrafo->nodos[idMinima]->peso);
			return EXIT_SUCCESS;
		}
		else
		{
			NodoAdyacente *temp = unGrafo->nodos[idMinima]->inicio;
			while (temp->sgte!=NULL || cont<=unGrafo->nodos[idMinima]->largo)
			{
                cont++;
				relax(unGrafo, idMinima, temp->id);
				temp=temp->sgte;
			}
		}
	} while (cant_visitados<=TAM);
	return EXIT_FAILURE;
}

/* *************************** DIJKSTRA CON HEAP ******************************* */

/*
int dijkstra_final(Grafo *unGrafo, int idInicial, int idFinal)
{
	int cant_visitados;
	iniciaNodos(unGrafo, idInicial);  //inicia pesos y padres de nodos del grafo
	HeapTree unheap = crearHeap();  //crea heap vacio
	llenarHeap(&unheap, unGrafo);  //agrega nodos de unGrafo a heap
	do  //mientras queden nodos del grafo por visitar...
	{
		int auxMenor = minimo(&unheap);  //saca el minimo del heap
		cant_visitados++;  //aumenta variable con cantidad de nodos ya visitados
        if  (auxMenor == idFinal)   // si auxMenor es el nodo que buscamos
        {
			printf("encontrado! :D\n"); //encontramos el camino mas corto! :D
			printf("encontrado camino mas corto = %i\n", unGrafo->nodos[auxMenor]->peso);
            return EXIT_SUCCESS;
		}
        else	//hacer relax() con sus adyacentes
        {

			NodoAdyacente *temp = unGrafo->nodos[auxMenor]->inicio;  //puntero temporal
			int cuenta = 0;
			//para ir contando las veces que se hace relax con los adyacentes
			//que no debe ser mas que nodos[id]->largo
			while (temp->sgte != NULL)
			//while (temp->sgte != NULL && cuenta<=unGrafo->nodos[auxMenor]->largo)  //mientras haya adyacentes por visitar...
			{
				relax(unGrafo, auxMenor, temp->id);  //funcion relax
				temp=temp->sgte;  //mueve ptr temporal al sgte adyacente...
				actualizarHeap(&unheap, unGrafo, unGrafo->nodos[auxMenor]);
				cuenta++;
			}

		}
	}while (!heapVacio(&unheap));
	return EXIT_FAILURE;
}


*/

#endif
//esta version se entrego un dia despues por problemas de internet debido a las constantes replicas en Ovalle
