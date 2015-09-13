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

void Encolar(Cola *unaCola, Nodo unNodo, int indiceNodoGrafo){
    nodoCola *nuevo=(nodoCola*)malloc(sizeof(struct _nodo));

    nuevo->nodoGrafo=unNodo;
    nuevo->i_nodoGrafo=indiceNodoGrafo;
    nuevo->sgte=NULL;

    if(esVacia(unaCola)==1){
        unaCola->primero=nuevo;
        unaCola->ultimo=nuevo;
    }else{
        unaCola->ultimo->sgte=nuevo;
        unaCola->ultimo=nuevo;
    }
    unaCola->tamano++;
}

nodoCola *Decolar(Cola *unaCola){
    nodoCola *tmp;
    nodoCola* nodoAtendido=(nodoCola*)malloc(sizeof(struct _nodo));
    tmp=unaCola->primero;
    unaCola->primero=unaCola->primero->sgte;
    nodoAtendido=tmp;
    free(tmp);
    unaCola->tamano--;

    return(nodoAtendido);

}

void mostrarCola(Cola *unaCola){
    nodoCola*actual;
    actual=unaCola->primero;
    int i;
    for(i=0;i<unaCola->tamano;i++){
        printf("unaCola[%d] = %c\n", i, actual->nodoGrafo.etiqueta);
        actual=actual->sgte;
    }
    if(esVacia(unaCola)==1){
        printf("La Cola esta vacia.\n");
    }else
        printf("Fin de la cola !!\n\n");


}

int contarAdyacentes(int indiceNodo){
    int contador=0,j;

    for(j=0;j<TAM;j++){
        if(matrizEnlaces[indiceNodo][j]==1)
            contador++;
    }
        return contador; //si no hubiesen enlaces no deberia ejecutarse el for
}

int indiceNodoAdyacente(int indiceNodo, int iNodoYaVisto){ // si es -1, significa que aun no devolvemos ningun indice de un nodo adyacente

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


void BFS(Nodo unGrafo[TAM], Nodo unNodo, int indiceUnNodo){ // 99 SE REFIERE A INFINITO
    nodoCola*u=(nodoCola*)malloc(sizeof(struct _nodo));
    int contador=0;
    int i;
    for(i=0;i<TAM;i++){
        unGrafo[i].color='w';
        unGrafo[i].distancia=99;
        unGrafo[i].padre=NULL;
    }
    printf("Todos los nodos han sido inicializados blancos con distancia ''infinita'' ...\n");getchar();
    unGrafo[indiceUnNodo].color='g';
    unGrafo[indiceUnNodo].distancia=0;
    unGrafo[indiceUnNodo].padre=NULL;
    printf("Punto de inicio de la Busqueda marcado Gris con distancia 0\n");
    Cola *Coula=iniciarCola();
    printf("Cola vacia creada\n");
    Encolar(Coula, unGrafo[indiceUnNodo], indiceUnNodo);
    printf("Punto de inicio del grafo Encolado...\n"); getchar();
    printf("Cola: ");
    mostrarCola(Coula);


    while(esVacia(Coula)!=1){
        *u=*Decolar(Coula);
        printf("Una variable u toma el valor de lo que retorna Decolar la Cola\n");
        printf("Mostrar etiqueta contenida en u: %c", u->nodoGrafo.etiqueta); getchar();
        int yaVisto=-1,iNodoAdy;
        printf("Cada adyacente a u sera evaluado si esta Blanco...\n");getchar();
        printf("El nodo u tiene %d nodos adyacentes\n", contarAdyacentes(u->i_nodoGrafo));
        for(i=0;i<contarAdyacentes(u->i_nodoGrafo);i++){
            iNodoAdy=indiceNodoAdyacente(u->i_nodoGrafo, yaVisto);
            if(unGrafo[iNodoAdy].color=='w'){
                printf("El nodo Adyacente %c esta Blanco\n", unGrafo[iNodoAdy].etiqueta);
                unGrafo[iNodoAdy].color='g';
                printf("El nodo Adyacente %c se marca Gris\n", unGrafo[iNodoAdy].etiqueta);
                unGrafo[iNodoAdy].distancia=(u->nodoGrafo.distancia)+1;
                printf("El nodo Adyacente %c tiene una distancia: %d\n", unGrafo[iNodoAdy].etiqueta, unGrafo[iNodoAdy].distancia);
                unGrafo[iNodoAdy].padre=&u->nodoGrafo;
                printf("El padre del nodo Adyacente %c es: %c\n", unGrafo[iNodoAdy].etiqueta, (*unGrafo[iNodoAdy].padre).etiqueta);
                Encolar(Coula, unGrafo[iNodoAdy], iNodoAdy);
                printf("El nodo %c adyacente a %c ha sido encolado\n", unGrafo[iNodoAdy].etiqueta, u->nodoGrafo.etiqueta);
            }
            yaVisto=iNodoAdy;
            printf("Se muestra el estado actual de la cola:\n");
            mostrarCola(Coula);printf(". . .\n");getchar();
        }
        unGrafo[u->i_nodoGrafo].color='b';

    }
    printf("Se muestra el estado de los nodos(Color, distancia, etiqueta)\n");
    for(i=0;i<TAM;i++){
        printf("Nodo %c: Distancia %d , Color %c\n", unGrafo[i].etiqueta, unGrafo[i].distancia, unGrafo[i].color);
    }


}
