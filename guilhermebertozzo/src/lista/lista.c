#include "lista.h"
#include <stdlib.h>

struct listaPosic{
    ListaElem elemento;
    ListaPosic proxima;
    ListaPosic anterior;
};

struct lista{
    ListaPosic primeiro;
    ListaPosic ultimo;
    int tamanho;
};

Lista criaLista(){
    Lista lista = malloc(sizeof(struct lista));

    if(lista == NULL){
        return NULL;
    }

    lista->primeiro = NULL; 
    lista->ultimo = NULL;

    lista->tamanho = 0;

    return lista;
}

int tamLista(Lista lista){
    if(lista == NULL){
        return -1;
    }

    return lista->tamanho;
}

ListaPosic insLista(Lista lista, ListaElem elemento){
    if(lista == NULL || elemento == NULL){
        return NULL;
    }

    ListaPosic nPosic = malloc(sizeof(struct listaPosic));

    if(nPosic == NULL){
        return NULL;
    }

    nPosic->elemento = elemento;
    nPosic->anterior = ultimaPosicLista(lista);
    nPosic->proxima = NULL;

    ListaPosic primeiro = primeiraPosicLista(lista);
    ListaPosic ultimo = ultimaPosicLista(lista);

    if(primeiro == NULL){
        lista->primeiro = nPosic;
    }

    if(ultimo != NULL){
        ultimo->proxima = nPosic;
    }

    lista->ultimo = nPosic;

    lista->tamanho++;

    return nPosic;
}

void removeLista(Lista lista, ListaPosic posic){
    if(lista == NULL || posic == NULL ){
        return;
    }

    ListaPosic anterior = antPosicLista(lista, posic);
    ListaPosic proximo = prxPosicLista(lista, posic);

    if(proximo){
        proximo->anterior = anterior;
    }
    if(anterior){
        anterior->proxima = proximo;
    }

    if(posic == primeiraPosicLista(lista)){
        lista->primeiro = proximo;
    }

    if(posic == ultimaPosicLista(lista)){
        lista->ultimo = anterior;
    }

    free(posic);

    lista->tamanho--;

}

ListaElem getLista(Lista lista, ListaPosic posic){
    if(lista == NULL || posic == NULL){
        return NULL;
    }

    return posic->elemento;

}

ListaPosic insAntesLista(Lista lista, ListaPosic posic, ListaElem elemento){
    if(lista == NULL || posic == NULL || elemento == NULL){
        return NULL;
    }

    ListaPosic nPosic = malloc(sizeof(struct listaPosic));

    if(nPosic == NULL){
        return NULL;
    }

    nPosic->elemento = elemento;
    nPosic->proxima = posic;

    ListaPosic anterior = antPosicLista(lista, posic);

    if(anterior){
        anterior->proxima = nPosic;
        posic->anterior = nPosic;
        nPosic->anterior = anterior;
    } else{
        lista->primeiro = nPosic;
        posic->anterior = nPosic;
        nPosic->anterior = NULL;
    }

    lista->tamanho++;

    return nPosic;
}

ListaPosic insDepoisLista(Lista lista, ListaPosic posic, ListaElem elemento){
    if(lista == NULL || posic == NULL || elemento == NULL){
        return NULL;
    }

    ListaPosic nPosic = malloc(sizeof(struct listaPosic));

    if(nPosic == NULL){
        return NULL;
    }

    nPosic->elemento = elemento;
    nPosic->anterior = posic;

    ListaPosic proximo = prxPosicLista(lista, posic);

    if(proximo){
        proximo->anterior = nPosic;
        posic->proxima = nPosic;
        nPosic->proxima = proximo;
    } else{
        lista->ultimo = nPosic;
        posic->proxima = nPosic;
        nPosic->proxima = NULL;
    }
    
    lista->tamanho++;
    
    return nPosic;
}

ListaPosic primeiraPosicLista(Lista lista){
    if(lista == NULL){
        return NULL;
    }

    return lista->primeiro;
    
}

ListaPosic prxPosicLista(Lista lista, ListaPosic posic){
    if(lista == NULL || posic == NULL){
        return NULL;
    }

    return posic->proxima;
}

ListaPosic antPosicLista(Lista lista, ListaPosic posic){
    if(lista == NULL || posic == NULL){
        return NULL;
    }

    return posic->anterior;
}

ListaPosic ultimaPosicLista(Lista lista){
    if(lista == NULL){
        return NULL;
    }

    return lista->ultimo;
}

void desfazLista(Lista lista){
    if(lista == NULL){
        return;
    }

    ListaPosic aux = primeiraPosicLista(lista);

    while(aux){
        removeLista(lista, aux);
        aux = primeiraPosicLista(lista);
    }

    free(lista);

}
