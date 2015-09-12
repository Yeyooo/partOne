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

int main(){ ///////// FALTA SOLUCIONAR LA WEA DEL PUNTERO DE MIERDAAAAAAAAAAAAAAAAAAAAAA
    //mostrarMatriz();

    Nodo arregloNodos[8];
	iniciarArreglodeNodos(arregloNodos);
    int i;

    BFS(arregloNodos, arregloNodos[0], 0);

    //DFS(arregloNodos);







    return 0;
}

