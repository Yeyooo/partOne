#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

#define TAM 8


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

/*void visitaDFS(Nodo *unGrafo[TAM], int tiempo, int indiceUnNodo){
    (*unGrafo[indiceUnNodo]).color='g';

    tiempo++;
    (*unGrafo[indiceUnNodo]).tiempoD=tiempo;

    int itmp, yaVisto=-1, iNodoAdy;
    for(itmp=0;itmp<(contarAdyacentes(indiceUnNodo));itmp++){ // esto tambien, necesito moverme por los adyacentes a un nodo, mirar pseudo
        printf("hola\n"); getchar();
        printf("unGrafo[%d]: %c\n", iNodoAdy , (*unGrafo[indiceUnNodo]).color);
        iNodoAdy=indiceNodoAdyacente(indiceUnNodo);
        if((*unGrafo[iNodoAdy]).color=='w'){
            (*unGrafo[iNodoAdy]).padre=(unGrafo[indiceUnNodo]);
            visitaDFS(unGrafo, tiempo, iNodoAdy);// si no es indiceUnNodo es iNodoAdy
        }
        yaVisto=iNodoAdy;
    }
    (*unGrafo[indiceUnNodo]).color='b';
    tiempo++;
    (*unGrafo[indiceUnNodo]).tiempoF=tiempo;
}

void DFS(Nodo unGrafo[TAM]){
    int i;
    for(i=0;i<8;i++){
        (unGrafo[i]).color='w';
        (unGrafo[i]).padre=NULL;
    }
    int tiempo=0;
    for(i=0;i<8;i++){
        if((unGrafo[i]).color=='w')
            visitaDFS(&unGrafo, tiempo, i);
    }


}*/
void DFS(Nodo unGrafo[TAM], int indiceOrigen, int tiempo){
    tiempo++;
    (unGrafo[indiceOrigen]).color='g';
    (unGrafo[indiceOrigen]).tiempoD=tiempo;
    int itmp, yaVisto=-1, iNodoAdy;
    for(itmp=0;itmp<(contarAdyacentes(indiceOrigen));itmp++){ // esto tambien, necesito moverme por los adyacentes a un nodo, mirar pseudo
        iNodoAdy=indiceNodoAdyacente(indiceOrigen, yaVisto);
        if((unGrafo[iNodoAdy]).color=='w'){
            (unGrafo[iNodoAdy]).color='b';
            DFS(unGrafo, iNodoAdy, tiempo);
        }
        yaVisto=iNodoAdy;
    }
    (unGrafo[indiceOrigen]).color='b';

    (unGrafo[indiceOrigen]).tiempoF=tiempo+1;
    int i;
    for(i=0;i<TAM;i++){
        printf("unGrafo[%d]: tiempoD: %d, tiempoF: %d\n", i , unGrafo[i].tiempoD, unGrafo[i].tiempoF);
        getchar();
    }

}




