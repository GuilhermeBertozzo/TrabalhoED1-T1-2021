#include "texto.h"
#include <stdlib.h>
#include <string.h>

struct texto{
    char* posX;
    char* posY;
    char* texto;
    char* corDentro;
    char* corBorda;
    char* textoID;
}; 

Texto criaTexto(char* x, char* y, char* texto, char* corBorda, char* corDentro, char* ID){
    Texto nTexto = malloc(sizeof(struct texto));

    if(nTexto == NULL){
        return NULL;
    }

    nTexto->posX = malloc(strlen(x)+1);
    nTexto->posY = malloc(strlen(y)+1);
    nTexto->texto = malloc(strlen(texto)+1);
    nTexto->corBorda = malloc(strlen(corBorda)+1);
    nTexto->corDentro = malloc(strlen(corDentro)+1);
    nTexto->textoID = malloc(strlen(ID)+1);

    strcpy(nTexto->posX, x);
    strcpy(nTexto->posY, y);
    strcpy(nTexto->texto, texto);
    strcpy(nTexto->corBorda, corBorda);
    strcpy(nTexto->corDentro, corDentro);
    strcpy(nTexto->textoID, ID);

    if(nTexto->posX == NULL || nTexto->posY == NULL || nTexto->texto == NULL || nTexto->corBorda == NULL || nTexto->corDentro == NULL || nTexto->textoID == NULL){
        desfazTexto(nTexto);
        return NULL;
    }

    return nTexto;
}

char* getXTexto(Texto texto){
    if(texto == NULL){
        return NULL;
    }

    return texto->posX;

}

char* getYTexto(Texto texto){
    if(texto == NULL){
        return NULL;
    }

    return texto->posY;
}

char* getTextoTexto(Texto texto){
    if(texto == NULL){
        return NULL;
    }

    return texto->texto;
}

char* getCorBordaTexto(Texto texto){
    if(texto == NULL){
        return NULL;
    }

    return texto->corBorda;
}

void setCorBordaTexto(Texto texto, char* cor){
    if(texto == NULL || cor == NULL){
        return NULL;
    }
    texto->corBorda = realloc(texto->corBorda, strlen(cor)+1);
    strcpy(texto->corBorda, cor);
}

char* getCorDentroTexto(Texto texto){
    if(texto == NULL){
        return NULL;
    }

    return texto->corDentro;
}

void setCorDentroTexto(Texto texto, char* cor){
    if(texto == NULL || cor == NULL){
        return NULL;
    }
    texto->corDentro = realloc(texto->corDentro, strlen(cor)+1);
    strcpy(texto->corDentro, cor);
}

char* getIDTexto(Texto texto){
    if(texto == NULL){
        return NULL;
    }

    return texto->textoID;
}

void desfazTexto(Texto texto){
    if(texto == NULL){
        return;
    }

    if(texto->posX){
        free(texto->posX);
    }
    if(texto->posY){
        free(texto->posY);
    }
    if(texto->texto){
        free(texto->texto);
    }
    if(texto->corBorda){
        free(texto->corBorda);
    }
    if(texto->corDentro){
        free(texto->corDentro);
    }
    if(texto->textoID){
        free(texto->textoID);
    }

    free(texto);

}

void textoSvg(FILE* svg, Texto texto){

    char* x = getXTexto(texto);
    char* y = getYTexto(texto);
    char* textoP = getTextoTexto(texto);
    char* corB = getCorBordaTexto(texto);
    char* corP = getCorDentroTexto(texto);
    char* id = getIDTexto(texto);

    fprintf(svg, "<text x=\"%s\" y=\"%s\" stroke=\"%s\" fill=\"%s\" stroke-weight=\"0.6\" font-size=\"18\">%s</text>\n", x, y, corB, corP, textoP);

}