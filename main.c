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

int main(){

    //mostrarMatriz();

    Nodo arregloNodos[8];
	iniciarArreglodeNodos(arregloNodos);/*
    int i;
    for(i=0;i<8;i++)
        printf("color:%c, d:%d, etiqueta:%c, padre:%p, td:%d, tf:%d \n", arregloNodos[i].color, arregloNodos[i].distancia, arregloNodos[i].etiqueta, arregloNodos[i].padre, arregloNodos[i].tiempoD, arregloNodos[i].tiempoF);
    */

    Cola *Colita=iniciarCola();

    Encolar(Colita, arregloNodos[0]);
    Encolar(Colita, arregloNodos[1]);
    Encolar(Colita, arregloNodos[2]);
    Encolar(Colita, arregloNodos[3]);
    Encolar(Colita, arregloNodos[4]);
    Encolar(Colita, arregloNodos[5]);

    nodoCola *tmp=iniciarCola();
    tmp->nodoGrafo=Decolar(Colita);
    printf("%c \n", tmp->nodoGrafo.etiqueta);
    tmp->nodoGrafo=Decolar(Colita);
    printf("%c \n", tmp->nodoGrafo.etiqueta);
    tmp->nodoGrafo=Decolar(Colita);
    printf("%c \n", tmp->nodoGrafo.etiqueta);
    tmp->nodoGrafo=Decolar(Colita);
    printf("%c \n", tmp->nodoGrafo.etiqueta);
    tmp->nodoGrafo=Decolar(Colita);
    printf("%c \n", tmp->nodoGrafo.etiqueta);
    tmp->nodoGrafo=Decolar(Colita);
    printf("%c \n", tmp->nodoGrafo.etiqueta);
    tmp->nodoGrafo=Decolar(Colita);





    return 0;
}

