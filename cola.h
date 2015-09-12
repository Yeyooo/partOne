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

int contarAdyacentes(int indiceNodo){
    int contador=0,j;

    for(j=0;j<8;j++){
        if(matrizEnlaces[indiceNodo][j]==1)
            contador++;
    }
    return contador;
}

int indiceNodoAdyacente(int indiceNodo, int iNodoYaVisto){ // si es -1, significa que aun no devolvemos ningun indice de un nodo adyacente
    //if(iNodoYaVisto==-1){// condicion al parecer innecesaria
        int j;
        for(j=0;j<TAM;j++){
            if(matrizEnlaces[indiceNodo][j]==1 && j!=iNodoYaVisto)
                return j;

        }

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
        //mostrarNodo(unGrafo[i]);
    }

    unNodo.color='g';
    unNodo.distancia=0;
    //mostrarNodo(unNodo);
    Cola *Coula=iniciarCola();
    Encolar(Coula, unNodo);

    while(Coula->primero!=NULL){

        Nodo u;
        u=Decolar(Coula); // sino necesito cambiar y que decolar devuelva solo el nodoGrafo y no todo el nodo cola
        //printf("valor u:\n\n");mostrarNodo(u);
        int itmp, yaVisto=-1, iNodoAdy;
        printf("contar ady: %d\n", contarAdyacentes(indiceUnNodo));getchar();
        for(itmp=0;itmp<(contarAdyacentes(indiceUnNodo));itmp++){ //falta obtener indices
            iNodoAdy=indiceNodoAdyacente(indiceUnNodo, yaVisto);
            printf("iNodoady: %d\n", iNodoAdy);getchar();

            //printf("color nodo ady: %c y inodo: %d\n", unGrafo[iNodoAdy].color, iNodoAdy);
            if (unGrafo[iNodoAdy].color=='w'){//printf("entre");
                unGrafo[iNodoAdy].color='g';
                unGrafo[iNodoAdy].distancia=u.distancia + 1;
                unGrafo[iNodoAdy].padre=&u;
                Encolar(Coula, unGrafo[iNodoAdy]); //printf("dentro if: \n\n");
                //mostrarNodo(unGrafo[iNodoAdy]);
            }
            mostrarNodo(u); // NO PASA LOS CAMBIOS AL GRAFO REAL.
            u.color='b';//no se si funciona esto
            yaVisto=iNodoAdy;

        }
        //printf("while\n");
    }


}
