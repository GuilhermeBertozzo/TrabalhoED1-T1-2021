#include "fila.h"
#include <stdlib.h>

struct filaPosic{
    FilaElem elemento;
    FilaPosic proxima;
};

struct fila{
    FilaPosic primeiro;
    FilaPosic ultimo;
    int tamanho;
};


Fila criaFila(){
    Fila fila = malloc(sizeof(struct fila));

    if(fila == NULL){
        return NULL;
    }

    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
}

int tamFila(Fila fila){
    if(fila == NULL){
        return -1;
    }

    return fila->tamanho;

}

FilaPosic insFila(Fila fila, FilaElem elemento){
    if(fila == NULL || elemento == NULL){
        return NULL;
    }

    FilaPosic nPosic = malloc(sizeof(struct filaPosic));

    if(nPosic == NULL){
        return NULL;
    }

    nPosic->elemento = elemento;
    nPosic->proxima = NULL;

    FilaPosic ultimo = ultimaPosicFila(fila);
    
    if(ultimo == NULL){
        fila->primeiro = nPosic;
    } else{
        ultimo->proxima = nPosic;
    }

    fila->ultimo = nPosic;

    fila->tamanho++;

    return nPosic;

}

void removeFila(Fila fila){
    if(fila == NULL || tamFila(fila) == 0){
        return;
    }

    FilaPosic primeiro = primeiraPosicFila(fila);
    FilaPosic proximo = prxPosicFila(fila, primeiro);

    fila->primeiro = proximo;
    
    if(proximo == NULL){
        fila->ultimo = NULL;
    }

    free(primeiro);

    fila->tamanho--;
}

FilaElem getFila(Fila fila, FilaPosic posic){
    if(fila == NULL || posic == NULL){
        return NULL;
    }

    return posic->elemento;
    
}

FilaPosic primeiraPosicFila(Fila fila){
    if(fila == NULL){
        return NULL;
    }

    return fila->primeiro;

}

FilaPosic prxPosicFila(Fila fila, FilaPosic posic){

    if(fila == NULL){
        return NULL;
    }

    return posic->proxima;

}

FilaPosic ultimaPosicFila(Fila fila){
    if(fila == NULL){
        return NULL;
    }

    return fila->ultimo;
}

void desfazFila(Fila fila){
    if(fila == NULL){
        return;
    }

    while(tamFila(fila) != 0){
        removeFila(fila);
    }

    free(fila);

}