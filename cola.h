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

#define TAM 8

typedef struct _nodo{
    struct _nodo *sgte;
    Nodo nodoGrafo;
    int i_nodoGrafo;
}nodoCola;

typedef struct t_cola{
    nodoCola*primero,*ultimo;
    int tamano;
}Cola;

Cola *iniciarCola(){
    Cola *tmp=(Cola*)malloc(sizeof(struct t_cola));
    tmp->tamano=0;
    tmp->primero=tmp->ultimo=NULL;

    return tmp;
}

int esVacia(Cola *unaCola){
    if(unaCola->tamano==0)
        return 1;
    else
        return 0;
}

void Encolar(Cola *unaCola, Nodo unNodo, int indiceNodoGrafo){// meter un elemento, crear nodo aux44
    nodoCola *nuevo = (nodoCola*)malloc(sizeof(struct _nodo));

    nuevo->nodoGrafo = unNodo;
    nuevo->i_nodoGrafo = indiceNodoGrafo;
    nuevo->sgte = NULL;

    if(esVacia(unaCola)==1){
        unaCola->primero=nuevo;
        unaCola->ultimo=nuevo;
    }else{
        unaCola->ultimo->sgte = nuevo;
        unaCola->ultimo = nuevo;
    }
    unaCola->tamano++;
}

nodoCola *Decolar(Cola *unaCola){// sacar un elemento
    if(esVacia(unaCola)==1) printf("La Cola esta vacia pero hare igual la accion\n");
    nodoCola *tmp;
    nodoCola* nodoAtendido=(nodoCola*)malloc(sizeof(struct _nodo));
    tmp = unaCola->primero;
    unaCola->primero = unaCola->primero->sgte;
    nodoAtendido = tmp;
    free(tmp);
    unaCola->tamano--;
    return(nodoAtendido);

}

void mostrarCola(Cola *unaCola){
    nodoCola*actual;
    actual=unaCola->primero;
    int i;
    for(i = 0; i<unaCola->tamano; i++){
        printf("unaCola[%d] = %c\n", i, actual->nodoGrafo.etiqueta);
        actual = actual->sgte;
    }
    if(esVacia(unaCola)==1){
        printf("La Cola esta vacia.\n");
    }else
        printf("Fin de la cola !!\n");


}

int contarAdyacentes(int indiceNodo){
    int contador=0,j;

    for(j=0;j<8;j++){
        if(matrizEnlaces[indiceNodo][j]==1)
            contador++;
    }
        return contador; //si no hubiesen enlaces no deberia ejecutarse el for
}

int indiceNodoAdyacente(int indiceNodo, int iNodoYaVisto){ // si es -1, significa que aun no devolvemos ningun indice de un nodo adyacente
    //if(iNodoYaVisto==-1){// condicion al parecer innecesaria
        int j;
        for(j=0;j<TAM;j++){
            if(matrizEnlaces[indiceNodo][j]==1 && j!=iNodoYaVisto && j>iNodoYaVisto){
                return j;
            }

        }
        return 99;

}



void mostrarNodo(Nodo unNodo){
    printf("Valores del nodo:\n");
    printf("color: %c\n", unNodo.color);
    printf("distancia: %d\n", unNodo.distancia);
    printf("etiqueta: %c\n", unNodo.etiqueta);
    printf("tiempoD: %d\n", unNodo.tiempoD);
    printf("tiempoF: %d\n", unNodo.tiempoF);
    printf("Padre: %p\n", unNodo.padre);

}


void BFS(Nodo unGrafo[8], Nodo unNodo, int indiceUnNodo){
    nodoCola*u=(nodoCola*)malloc(sizeof(struct _nodo));
    int contador=0;
    int i;
    for(i=0;i<TAM;i++){
        unGrafo[i].color='w';
        unGrafo[i].distancia=99;
        unGrafo[i].padre=NULL;
    }
    unGrafo[0].color='g';
    unGrafo[0].distancia=0;
    unGrafo[0].padre=NULL;
    Cola *Coula=iniciarCola();
    Encolar(Coula, unGrafo[indiceUnNodo], indiceUnNodo);

    while(esVacia(Coula)!=1){
        *u=*Decolar(Coula);
        printf("u->i_nodo: %d\n", u->i_nodoGrafo);
        int yaVisto=-1,iNodoAdy;

        for(i=0;i<contarAdyacentes(u->i_nodoGrafo);i++){
            printf("u->i_nodo: %d\n", u->i_nodoGrafo);
            iNodoAdy=indiceNodoAdyacente(u->i_nodoGrafo, yaVisto);
        printf("u->i_nodo: %d\n", u->i_nodoGrafo);
            if(unGrafo[iNodoAdy].color=='w'){
                    printf("u->i_nodo: %d\n", u->i_nodoGrafo);
                printf("primera vez en if: iNodoady: %d\n", iNodoAdy);
                unGrafo[iNodoAdy].color='g';
                unGrafo[iNodoAdy].distancia=(u->nodoGrafo.distancia)+1;
                unGrafo[iNodoAdy].padre=&u->nodoGrafo;
            printf("u->i_nodo: %d u: %c ahora\n", u->i_nodoGrafo, u->nodoGrafo.etiqueta); //aqui error!
                Encolar(Coula, unGrafo[iNodoAdy], iNodoAdy);
                printf("u->i_nodo: %d, u: %c\n", u->i_nodoGrafo, u->nodoGrafo.etiqueta);
            }
            yaVisto=iNodoAdy;
            printf("u->i_nodoGrafo: %d, yaVisto: %d\n", u->i_nodoGrafo, yaVisto);
            // // no cambia de forma correcta
            printf("ver aqui : iNodoAdy: %d\n", iNodoAdy);
            mostrarCola(Coula);getchar();
        }
        unGrafo[u->i_nodoGrafo].color='b';

    }
    for(i=0;i<TAM;i++){
        printf(" color: %c ", unGrafo[i].color);
    }


}
