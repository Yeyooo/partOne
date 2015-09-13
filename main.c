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

#ifndef COLA_H
#include "cola.h"
#define COLA_H
#endif

#define TAM 8

int main(){ // Los Colores son w=blanco, g=gris, b=negro

    Nodo arregloNodos[TAM];
	iniciarArreglodeNodos(arregloNodos);
    int i, tiempo=0;

    BFS(arregloNodos, arregloNodos[0], 0); //DEJAR EN COMENTARIO PARA USAR EL SIGUIENTE
    // DFS(arregloNodos, 0, tiempo);



    return 0;
}

