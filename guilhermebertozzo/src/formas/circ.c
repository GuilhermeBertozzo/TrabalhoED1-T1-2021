#include "circ.h"
#include <stdlib.h>
#include <string.h>

struct circ{
    char* posX;
    char* posY;
    char* raio;
    char* corDentro;
    char* corBorda;
    char* circID;
}; 

Circ criaCirc(char* x, char* y, char* r, char* corBorda, char* corDentro, char* ID){
    Circ nCirc = malloc(sizeof(struct circ));

    if(nCirc == NULL){
        return NULL;
    }

    nCirc->posX = malloc(strlen(x)+1);
    nCirc->posY = malloc(strlen(y)+1);
    nCirc->raio = malloc(strlen(r)+1);
    nCirc->corBorda = malloc(strlen(corBorda)+1);
    nCirc->corDentro = malloc(strlen(corDentro)+1);
    nCirc->circID = malloc(strlen(ID)+1);

    strcpy(nCirc->posX, x);
    strcpy(nCirc->posY, y);
    strcpy(nCirc->raio, r);
    strcpy(nCirc->corBorda, corBorda);
    strcpy(nCirc->corDentro, corDentro);
    strcpy(nCirc->circID, ID);

    if(nCirc->posX == NULL || nCirc->posY == NULL || nCirc->raio == NULL || nCirc->corBorda == NULL || nCirc->corDentro == NULL || nCirc->circID == NULL){
        desfazCirc(nCirc);
        return NULL;
    }

    return nCirc;
}

char* getXCirc(Circ circ){
    if(circ == NULL){
        return NULL;
    }

    return circ->posX;

}

char* getYCirc(Circ circ){
    if(circ == NULL){
        return NULL;
    }

    return circ->posY;
}

char* getRaioCirc(Circ circ){
    if(circ == NULL){
        return NULL;
    }

    return circ->raio;
}

char* getCorBordaCirc(Circ circ){
    if(circ == NULL){
        return NULL;
    }

    return circ->corBorda;
}

void setCorBordaCirc(Circ circ, char* cor){
    if(circ == NULL || cor == NULL){
        return NULL;
    }
    circ->corBorda = realloc(circ->corBorda, strlen(cor)+1);
    strcpy(circ->corBorda, cor);
}

char* getCorDentroCirc(Circ circ){
    if(circ == NULL){
        return NULL;
    }

    return circ->corDentro;
}

void setCorDentroCirc(Circ circ, char* cor){
    if(circ == NULL || cor == NULL){
        return NULL;
    }
    circ->corDentro = realloc(circ->corDentro, strlen(cor)+1);
    strcpy(circ->corDentro, cor);
}

char* getIDCirc(Circ circ){
    if(circ == NULL){
        return NULL;
    }

    return circ->circID;
}

void desfazCirc(Circ circ){
    if(circ == NULL){
        return;
    }

    if(circ->posX){
        free(circ->posX);
    }
    if(circ->posY){
        free(circ->posY);
    }
    if(circ->raio){
        free(circ->raio);
    }
    if(circ->corBorda){
        free(circ->corBorda);
    }
    if(circ->corDentro){
        free(circ->corDentro);
    }
    if(circ->circID){
        free(circ->circID);
    }

    free(circ);
}

void circSvg(FILE* svg, Circ circ){

    char* x = getXCirc(circ);
    char* y = getYCirc(circ);
    char* r = getRaioCirc(circ);
    char* corB = getCorBordaCirc(circ);
    char* corP = getCorDentroCirc(circ);

    fprintf(svg, "<circle cx=\"%s\" cy=\"%s\" r=\"%s\" stroke=\"%s\" fill=\"%s\" stroke-width=\"1\" />\n", x, y, r, corB, corP);

}
