#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

#ifndef GRAFO_H
#include "grafo.h"
#define GRAFO_H
#endif

int main(){

    mostrarMatriz();

    Nodo arregloNodos[8];
	iniciarArreglodeNodos(arregloNodos);
    int i;
    for(i=0;i<8;i++)
        printf("color:%c, d:%d, etiqueta:%c, padre:%p, td:%d, tf:%d \n", arregloNodos[i].color, arregloNodos[i].distancia, arregloNodos[i].etiqueta, arregloNodos[i].padre, arregloNodos[i].tiempoD, arregloNodos[i].tiempoF);

    return 0;
}

