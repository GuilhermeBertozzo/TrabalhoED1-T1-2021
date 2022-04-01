#include "reta.h"

#include <stdlib.h>
#include <string.h>

struct reta{
    char* posX1;
    char* posX2;
    char* posY1;
    char* posY2;
    char* cor;
    char* retaID;
}; 

Reta criaReta(char* x1, char* x2, char* y1, char* y2, char* cor, char* ID){
    Reta nReta = malloc(sizeof(struct reta));

    if(nReta == NULL){
        return NULL;
    }

    nReta->posX1 = malloc(strlen(x1)+1);
    nReta->posX2 = malloc(strlen(x2)+1);
    nReta->posY1 = malloc(strlen(y1)+1);
    nReta->posY2 = malloc(strlen(y2)+1);
    nReta->cor = malloc(strlen(cor)+1);
    nReta->retaID = malloc(strlen(ID)+1);

    strcpy(nReta->posX1, x1);
    strcpy(nReta->posX2, x2);
    strcpy(nReta->posY1, y1);
    strcpy(nReta->posY2, y2);
    strcpy(nReta->cor, cor);
    strcpy(nReta->retaID, ID);

    if(nReta->posX1 == NULL || nReta->posX2 == NULL || nReta->posY1 == NULL || nReta->posY2 == NULL || nReta->cor == NULL || nReta->retaID == NULL){
        desfazReta(nReta);
        return NULL;
    }

    return nReta;
}

char* getX1Reta(Reta reta){
    if(reta == NULL){
        return NULL;
    }

    return reta->posX1;

}

char* getX2Reta(Reta reta){
    if(reta == NULL){
        return NULL;
    }

    return reta->posX2;
}

char* getY1Reta(Reta reta){
    if(reta == NULL){
        return NULL;
    }

    return reta->posY1;
}

char* getY2Reta(Reta reta){
    if(reta == NULL){
        return NULL;
    }

    return reta->posY2;
}

char* getCorReta(Reta reta){
    if(reta == NULL){
        return NULL;
    }

    return reta->cor;
}

void setCorReta(Reta reta, char* cor){
    if(reta == NULL || cor == NULL){
        return NULL;
    }
    reta->cor = realloc(reta->cor, strlen(cor)+1);
    strcpy(reta->cor, cor);
}

char* getIDReta(Reta reta){
    if(reta == NULL){
        return NULL;
    }

    return reta->retaID;
}

void desfazReta(Reta reta){
    if(reta == NULL){
        return;
    }

    if(reta->posX1){
        free(reta->posX1);
    }
    if(reta->posX2){
        free(reta->posX2);
    }
    if(reta->posY1){
        free(reta->posY1);
    }
    if(reta->posY2){
        free(reta->posY2);
    }
    if(reta->cor){
        free(reta->cor);
    }
    if(reta->retaID){
        free(reta->retaID);
    }

    free(reta);

}

void retaSvg(FILE* svg, Reta reta){

    char* x1 = getX1Reta(reta);
    char* y1 = getY1Reta(reta);
    char* x2 = getX2Reta(reta);
    char* y2 = getY2Reta(reta);
    char* cor = getCorReta(reta);
    char* id = getIDReta(reta);

    fprintf(svg, "<line x1 = \"%s\" y1 = \"%s\" x2 = \"%s\" y2 = \"%s\" stroke = \"%s\" stroke-width=\"1\" />\n", x1, y1, x2, y2, cor);

}
