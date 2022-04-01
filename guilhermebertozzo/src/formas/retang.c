#include "retang.h"
#include <stdlib.h>
#include <string.h>

struct retang{
    char* posX;
    char* posY;
    char* altura;
    char* largura;
    char* corDentro;
    char* corBorda;
    char* retangID;
}; 

Retang criaRetang(char* x, char* y, char* a, char* l, char* corBorda, char* corDentro, char* ID){
    Retang nRetang = malloc(sizeof(struct retang));

    if(nRetang == NULL){
        return NULL;
    }

    nRetang->posX = malloc(strlen(x)+1);
    nRetang->posY = malloc(strlen(y)+1);
    nRetang->altura = malloc(strlen(a)+1);
    nRetang->largura = malloc(strlen(l)+1);
    nRetang->corBorda = malloc(strlen(corBorda)+1);
    nRetang->corDentro = malloc(strlen(corDentro)+1);
    nRetang->retangID = malloc(strlen(ID)+1);

    strcpy(nRetang->posX, x);
    strcpy(nRetang->posY, y);
    strcpy(nRetang->altura, a);
    strcpy(nRetang->largura, l);
    strcpy(nRetang->corBorda, corBorda);
    strcpy(nRetang->corDentro, corDentro);
    strcpy(nRetang->retangID, ID);

    if(nRetang->posX == NULL || nRetang->posY == NULL || nRetang->altura == NULL || nRetang->largura == NULL || nRetang->corBorda == NULL || nRetang->corDentro == NULL || nRetang->retangID == NULL){
        desfazRetang(nRetang);
        return NULL;
    }

    return nRetang;
}

char* getXRetang(Retang retang){
    if(retang == NULL){
        return NULL;
    }

    return retang->posX;

}

char* getYRetang(Retang retang){
    if(retang == NULL){
        return NULL;
    }

    return retang->posY;
}

char* getARetang(Retang retang){
    if(retang == NULL){
        return NULL;
    }

    return retang->altura;
}

char* getLRetang(Retang retang){
    if(retang == NULL){
        return NULL;
    }

    return retang->largura;
}

char* getCorBordaRetang(Retang retang){
    if(retang == NULL){
        return NULL;
    }

    return retang->corBorda;
}

void setCorBordaRetang(Retang retang, char* cor){
    if(retang == NULL || cor == NULL){
        return NULL;
    }
    retang->corBorda = realloc(retang->corBorda, strlen(cor)+1);
    strcpy(retang->corBorda, cor);
}

char* getCorDentroRetang(Retang retang){
    if(retang == NULL){
        return NULL;
    }

    return retang->corDentro;
}

void setCorDentroRetang(Retang retang, char* cor){
    if(retang == NULL || cor == NULL){
        return NULL;
    }
    retang->corDentro = realloc(retang->corDentro, strlen(cor)+1);
    strcpy(retang->corDentro, cor);
}

char* getIDRetang(Retang retang){
    if(retang == NULL){
        return NULL;
    }

    return retang->retangID;
}

void desfazRetang(Retang retang){
    if(retang == NULL){
        return;
    }

    if(retang->posX){
        free(retang->posX);
    }
    if(retang->posY){
        free(retang->posY);
    }
    if(retang->altura){
        free(retang->altura);
    }
    if(retang->largura){
        free(retang->largura);
    }
    if(retang->corBorda){
        free(retang->corBorda);
    }
    if(retang->corDentro){
        free(retang->corDentro);
    }
    if(retang->retangID){
        free(retang->retangID);
    }

    free(retang);

}

void retangSvg(FILE* svg, Retang retang){

    char* x = getXRetang(retang);
    char* y = getYRetang(retang);
    char* a = getARetang(retang);
    char* l = getLRetang(retang);
    char* corB = getCorBordaRetang(retang);
    char* corP = getCorDentroRetang(retang);
    char* id = getIDRetang(retang);

    fprintf(svg, "<rect x = \"%s\" y = \"%s\" width = \"%s\" height = \"%s\" fill=\"%s\" stroke = \"%s\" />\n", x, y, l, a, corP, corB);

}