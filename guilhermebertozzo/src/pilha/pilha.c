#include "pilha.h"
#include <stdlib.h>

struct pilhaPosic{
    PilhaElem elemento;
    PilhaPosic anterior;
};

struct pilha{
    PilhaPosic ultimo;
    int tamanho;
};

Pilha criaPilha(){
    Pilha pilha = malloc(sizeof(struct pilha));

    if(pilha == NULL){
        return NULL;
    }

    pilha->ultimo = NULL;
    pilha->tamanho = 0;
}

int tamPilha(Pilha pilha){
    if(pilha == NULL){
        return -1;
    }

    return pilha->tamanho;
}

PilhaPosic insPilha(Pilha pilha, PilhaElem elemento){
    if(pilha == NULL || elemento == NULL){
        return NULL;
    }

    PilhaPosic nPosic = malloc(sizeof(struct pilhaPosic));

    if(nPosic == NULL){
        return NULL;
    }

    nPosic->elemento = elemento;
    nPosic->anterior = ultimaPosicPilha(pilha);

    pilha->ultimo = nPosic;

    pilha->tamanho++;

    return nPosic;
}

void removePilha(Pilha pilha){
    if(pilha == NULL || tamPilha(pilha) == 0){
        return;
    }

    PilhaPosic ultima = ultimaPosicPilha(pilha);
    PilhaPosic antes = antPosicPilha(pilha, ultima);

    pilha->ultimo = antes;

    free(ultima);

    pilha->tamanho--;

}

PilhaElem getPilha(Pilha pilha, PilhaPosic posic){
    if(pilha == NULL || posic == NULL){
        return NULL;
    }

    return posic->elemento;
}

PilhaPosic antPosicPilha(Pilha pilha, PilhaPosic posic){
    if(pilha == NULL || posic == NULL){
        return NULL;
    }

    return posic->anterior;
}

PilhaPosic ultimaPosicPilha(Pilha pilha){
    if(pilha == NULL){
        return NULL;
    }

    return pilha->ultimo;
}

void desfazPilha(Pilha pilha){
    if(pilha == NULL){
        return;
    }

    while(tamPilha(pilha) != 0){
        removePilha(pilha);
    }

    free(pilha);
}