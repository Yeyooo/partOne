#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif


typedef struct t_nodo{
    char color;// W white, B black, G grey;
    struct t_nodo *padre;
    int distancia, tiempoD, tiempoF;
    char etiqueta;//simbolo o contenido?
}Nodo;

const int matrizEnlaces[8][8]={{0,1,0,1,0,0,0,0}, // las posiciones 0, 1, 2, 3... 7 en el grafo son a, b, c, d... h respectivamente
                        {0,0,1,0,0,1,0,0},
                        {0,0,0,1,0,1,1,1},
                        {0,0,0,0,0,0,0,1},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,1,0,1,0},
                        {0,0,0,0,0,0,0,1},
                        {0,0,0,0,0,0,0,0}};

Nodo iniciarNodo(char etiqueta){
    Nodo tmp;
    tmp.color='w';
    tmp.padre=NULL;
    tmp.distancia=tmp.tiempoD=tmp.tiempoF=0;
    tmp.etiqueta=etiqueta;

    return tmp;
}

void iniciarArreglodeNodos(Nodo unArreglo[8]){
    int i;
    for(i=0;i<8;i++){
        unArreglo[i]=iniciarNodo('a'+i);
    }

}


void mostrarMatriz(){
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++)
            printf(" %d ", matrizEnlaces[i][j]);
        printf("\n\n");
    }
}

void visitaDFS(Nodo unGrafo[8], Nodo unNodo, int tiempo){
    tiempo++;
    unNodo.tiempoD=tiempo;
    unNodo.color='g';
    int i;//esta wea es pa dejar el for funcional nomas, BORRAR!
    for(i=0;i<8;i++){ // esto tambien, necesito moverme por los adyacentes a un nodo, mirar pseudo
            if(unGrafo[i].color=='w'){
                unGrafo[i].padre=&unNodo;
                visitaDFS(unGrafo, unGrafo[i], tiempo);
            }
    }
    unNodo.color='b';
    tiempo++;
    unNodo.tiempoF=tiempo;

}

void DFS(Nodo unGrafo[8]){
    int i;
    for(i=0;i<8;i++){
        unGrafo[i].color='w';
        unGrafo[i].padre=NULL;
    }
    int tiempo=0;
    for(i=0;i<8;i++){
        if(unGrafo[i].color=='w')
            visitaDFS(unGrafo, unGrafo[i], tiempo);
    }


}


