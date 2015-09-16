#include <stdio.h>
#include <stdlib.h>

typedef struct tipo_adyacentes{
  int indice;
  struct tipo_adyacentes *sgte;
}adyacentes;

typedef struct tipo_nodo{     /* se define un nodo generico para las dos tipos de busquedas*/
  int ID;       /* etiqueta */
  adyacentes *primerVecino;
  int padre; /* indice del padre en el arreglo de nodos  */
}Nodo;

void inicializa(char *nameHospitals;){
    nameHospitals[0]="a";  nameHospitals[1]="b";  nameHospitals[2]="c";  nameHospitals[3]="d";
    nameHospitals[4]="e";  nameHospitals[5]="f";   nameHospitals[6]="g";  nameHospitals[7]="h";
    nameHospitals[8]="i";   nameHospitals[9]="j";   nameHospitals[10]="k";nameHospitals[3]="l";
}

main(){
    char nameHospitals[11];
    inicializa( nameHospitals );
}
