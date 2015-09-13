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
            if(matrizEnlaces[indiceNodo][j]==1 && j!=iNodoYaVisto)
                return j;

        }
        return 99;

}

/*void inicializarValoresArregloNodosAdyancentes(int *NodosAdyacentes, int indiceNodo){ //necesita el indice para saber desde que fila buscar en la matriz
    getchar();
    *NodosAdyacentes=(int*)malloc(sizeof(int)*contarAdyacentes(indiceNodo)); // aqui esta el error
    getchar();
    int j=0, newi=0;
    while(j<8 && newi!=contarAdyacentes(indiceNodo)){ // quizas es la cantidad de adyacentes +1;

        if(matrizEnlaces[indiceNodo][j]==1){
            NodosAdyacentes[newi]=j;
            newi++;
        }
        j++;
    }

}*/

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

    int i;

    for(i=0;i<8;i++){
        unGrafo[i].distancia = 99;
        unGrafo[i].padre = NULL;
    }

    unNodo.color='g';
    unNodo.distancia=0;
    Cola *Coula=iniciarCola();
    Encolar(Coula, unNodo, indiceUnNodo);
    while(esVacia(Coula)!=1){

        nodoCola *u=(nodoCola*)malloc(sizeof(struct _nodo));
        u=Decolar(Coula);
        indiceUnNodo=u->i_nodoGrafo;

        int itmp, yaVisto=-1, iNodoAdy; // HAY QUE AGREGAR EL INDICE DEL ENCOLADO

        for(itmp=0;itmp<(contarAdyacentes(indiceUnNodo));itmp++){ //INDICE UN NODO NO CAMBIA!
            iNodoAdy=indiceNodoAdyacente(indiceUnNodo, yaVisto);
            printf("iNodoAdy: %d\n", iNodoAdy), getchar();

            if (unGrafo[iNodoAdy].color=='w' && indiceNodoAdyacente(indiceUnNodo, yaVisto)!=99){
                unGrafo[iNodoAdy].color='g';
                unGrafo[iNodoAdy].distancia=u->nodoGrafo.distancia + 1;
                unGrafo[iNodoAdy].padre=&u->nodoGrafo;
                Encolar(Coula, unGrafo[iNodoAdy], iNodoAdy);
            }
            //no se si funciona esto
            yaVisto=iNodoAdy;
            mostrarCola(Coula);getchar();

        }
        u->nodoGrafo.color='b';

    }

}
