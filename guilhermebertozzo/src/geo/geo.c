#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "geo.h"
#include "../formas/reta.h"
#include "../formas/circ.h"
#include "../formas/retang.h"
#include "../formas/texto.h"

void leGeo(char* BED, char* BSD, char* geo, Lista retangulos, Lista circulos, Lista textos, Lista retas){
    if( BED == NULL || BSD == NULL || geo == NULL || retangulos == NULL || circulos == NULL || textos == NULL || retas == NULL){
        return;
    }

    int tamBED = strlen(BED);
    int tamGeo = strlen(geo);

    int temBarra = BED[tamBED-1] == '/';
    
    char* geoCaminho = malloc(tamBED + tamGeo + !temBarra);

    if(geoCaminho == NULL){
        return;
    }

    if(temBarra){
        sprintf(geoCaminho, "%s%s", BED, geo);
    } else{
        sprintf(geoCaminho, "%s/%s", BED, geo);
    }

    FILE* geoFile = fopen(geoCaminho, "r");

    free(geoCaminho);

    char* geoNome = strtok(geo, ".");
    int tamBSD = strlen(BSD);
    temBarra = BSD[tamBSD-1] == '/';
    char* svgNome = malloc(tamBSD + strlen(geoNome) + 5 + !temBarra);

    if(temBarra){
        sprintf(svgNome, "%s%s.svg", BSD, geoNome);
    } else{
        sprintf(svgNome, "%s/%s.svg", BSD, geoNome);
    }

    FILE* svg = fopen(svgNome,"w");
    printf("%s", svgNome);
    fprintf(svg, "<svg>\n");

    char aux[999];    

    while(1){
        fgets(aux, 999, geoFile);
        if(feof(geoFile)){
            break;
        }

        if(aux[strlen(aux)-1] == '\n'){
            aux[strlen(aux)-1] = '\0';
        }
        
        
        char* arg = strtok(aux, " ");

        char* id;
        char* x;
        char* y;
        char* x1;
        char* y1;
        char* x2;
        char* y2;
        char* cor;
        char* corB;
        char* corP;
        char* r;
        char* texto;
        char* a;
        char* l;

        switch(arg[0]){
            case 'l':
                id = strtok(NULL, " ");
                x1 = strtok(NULL, " ");
                y1 = strtok(NULL, " ");
                x2 = strtok(NULL, " ");
                y2 = strtok(NULL, " ");
                cor = strtok(NULL, " ");
                Reta nReta = criaReta(x1, x2, y1, y2, cor, id);
                retaSvg(svg, nReta);
                insLista(retas, nReta);
                break;
            case 'r':
                id = strtok(NULL, " ");
                l = strtok(NULL, " ");
                a = strtok(NULL, " ");
                x = strtok(NULL, " ");
                y = strtok(NULL, " ");
                corB = strtok(NULL, " ");
                corP = strtok(NULL, " ");
                Retang nRetang = criaRetang(x, y, a, l, corB, corP, id);
                retangSvg(svg, nRetang);
                insLista(retangulos, nRetang);
                break;
            case 'c':
                id = strtok(NULL, " ");
                r = strtok(NULL, " ");
                x = strtok(NULL, " ");
                y = strtok(NULL, " ");
                corB = strtok(NULL, " ");
                corP = strtok(NULL, " ");
                Circ nCirc = criaCirc(x, y, r, corB, corP, id);
                circSvg(svg, nCirc);
                insLista(circulos, nCirc);
                break;
            case 't':
                id = strtok(NULL, " ");
                x = strtok(NULL, " ");
                y = strtok(NULL, " ");
                corB = strtok(NULL, " ");
                corP = strtok(NULL, " ");
                texto = corP + strlen(corP) + 1;
                Texto nTexto = criaTexto(x, y, texto, corB, corP, id);
                textoSvg(svg, nTexto);
                insLista(textos, nTexto);
                break;
            default:
                break;
        }
    }
    fprintf(svg, "</svg>\n");



}
