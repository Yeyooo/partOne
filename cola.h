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

typedef struct _nodo{
    struct _nodo *sgte, *primero, *ultimo;
    Nodo nodoGrafo;
}nodoCola;

typedef nodoCola Cola;

Cola *iniciarCola(){
    Cola *tmp=(nodoCola*)malloc(sizeof(struct _nodo));

    tmp->nodoGrafo=iniciarNodo('\0');
    tmp->primero=tmp->sgte=tmp->ultimo=NULL;
    return tmp;
}

void Encolar(Cola *unaCola, Nodo unNodo){// meter un elemento, crear nodo aux44
    nodoCola *aux=(nodoCola*)malloc(sizeof(struct _nodo));
    aux->nodoGrafo=unNodo;
    aux->sgte=NULL;

    if(unaCola->primero==NULL){
        unaCola->primero=unaCola->ultimo=aux;
        unaCola->sgte=NULL;
        printf("Agregado al principio exitosamente\n");
    }else{
        nodoCola *ventana=unaCola->ultimo;
        ventana=aux;
        unaCola->ultimo->sgte=ventana;
        unaCola->ultimo=ventana;
        printf("Agregado exitosamente!\n");
    }

}

Nodo Decolar(Cola *unaCola){// sacar un elemento
    if(unaCola->primero!=NULL){
        nodoCola *aux=(nodoCola*)malloc(sizeof(struct _nodo));
        aux=unaCola->primero;
        unaCola->primero=unaCola->primero->sgte;

        printf("Sacado exitosamente\n");

        return aux->nodoGrafo;
    }else{
        printf("No hay mas elementos en la cola\n");
    }

}

void mostrarCola(Cola *unaCola){
    nodoCola *aux=(nodoCola*)malloc(sizeof(struct _nodo));
    aux=unaCola->primero;
    while(aux!=unaCola->ultimo){
        int i;
    }


}

void BFS(Nodo unGrafo[8], Nodo unNodo){

    int i=0;

    for(i=0;i<8;i++){
        unGrafo[i].distancia = 99;
        unGrafo[i].padre = NULL;
    }

    Cola *Coula=iniciarCola();

    unNodo.distancia=0;
    Encolar(Coula, unNodo);
    while(Coula->primero!=NULL){
        Nodo u;
        u=Decolar(Coula); // sino necesito cambiar y que decolar devuelva solo el nodoGrafo y no todo el nodo cola

        while('a'==4){ // obtener el indice para poder darselo a la condicion de abajo
            if (unGrafo[i].distancia==99){
                unGrafo[i].distancia=u.distancia + 1;
                unGrafo[i].padre=&u;
                Encolar(Coula, unGrafo[i]);
            }
        }
    }

}
