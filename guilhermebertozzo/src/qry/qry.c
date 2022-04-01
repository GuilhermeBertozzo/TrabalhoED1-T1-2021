#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "qry.h"
#include "../fila/fila.h"
#include "../pilha/pilha.h"
#include "../lista/lista.h"
#include "../formas/reta.h"
#include "../formas/circ.h"
#include "../formas/retang.h"
#include "../formas/texto.h"

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

// A fazer, T-2
void overlap(FILE* txtFile, Lista retangulos, Lista circulos, Lista retas){
 
}

void inside(FILE* txtFile, Lista retangulos, Lista circulos, Lista retas){
    char* id = strtok(NULL, " ");
    char* xAux = strtok(NULL, " ");
    char* yAux = strtok(NULL, " ");
    double x;
    double y;
    

    char* raio = "1";


    fprintf(txtFile, "i? %s %s %s\n", id, xAux, yAux);

    sscanf(xAux, "%lf", &x);
    sscanf(yAux, "%lf", &y);


    ListaPosic posic = primeiraPosicLista(retangulos);
    while(posic){
        Retang retang = getLista(retangulos, posic);
        if(strcmp(id, getIDRetang(retang)) == 0){
            char* xRetangAux = getXRetang(retang);
            char* yRetangAux = getYRetang(retang);
            char* aRetangAux = getARetang(retang);
            char* lRetangAux = getLRetang(retang);

            double xRetang; 
            double yRetang;
            double aRetang; 
            double lRetang; 

            sscanf(xRetangAux, "%lf", &xRetang);
            sscanf(yRetangAux, "%lf", &yRetang);
            sscanf(aRetangAux, "%lf", &aRetang);
            sscanf(lRetangAux, "%lf", &lRetang);

            double xMax = xRetang + lRetang;
            double yMax = yRetang + aRetang;
            char cor[10]; 
            char x2[999];
            char y2[999];

            sprintf(x2, "%lf", (xRetang + xMax)/2);
            sprintf(y2, "%lf", (yRetang + yMax)/2);

            if(x > xRetang && x < xMax && y > yRetang && y < yMax){
                fprintf(txtFile, "O ponto (%lf, %lf) esta dentro ao retangulo indicado.\n", x, y);
                strcpy(cor, "blue");
                Circ ponto = criaCirc(xAux, yAux, raio, cor, cor, "");
                Reta conexao = criaReta(xAux, x2, yAux, y2, cor, "");
                insLista(circulos, ponto);
                insLista(retas, conexao);
                return;
            } else{
                fprintf(txtFile, "O ponto (%lf, %lf) nao esta dentro ao retangulo indicado.\n", x, y);
                strcpy(cor, "magenta");
                Circ ponto = criaCirc(xAux, yAux, raio, cor, cor, "");
                Reta conexao = criaReta(xAux, x2, yAux, y2, cor, "");
                insLista(circulos, ponto);
                insLista(retas, conexao);
                return;
            }
        }
        posic = prxPosicLista(retangulos, posic);
    }

    posic = primeiraPosicLista(circulos);
    while(posic){
        Circ circ = getLista(circulos, posic);
        if(strcmp(id, getIDCirc(circ)) == 0){
            char* xCircAux = getXCirc(circ);
            char* yCircAux = getYCirc(circ);
            char* rCircAux = getRaioCirc(circ);

            double xCirc;
            double yCirc;
            double rCirc;

            sscanf(xCircAux, "%lf", &xCirc);
            sscanf(yCircAux, "%lf", &yCirc);
            sscanf(rCircAux, "%lf", &rCirc);

            char cor[10]; 

            double disPonto = sqrt((pow((xCirc - x), 2)) + pow((yCirc - y), 2));

            if(disPonto < rCirc){
                fprintf(txtFile, "O ponto (%lf, %lf) esta dentro do circulo indicado.\n", x, y);
                strcpy(cor, "blue");
                Circ ponto = criaCirc(xAux, yAux, raio, cor, cor, "");
                Reta conexao = criaReta(xAux, xCircAux, yAux, yCircAux, cor, "");
                insLista(circulos, ponto);
                insLista(retas, conexao);
                return;
            }else{
                fprintf(txtFile, "O ponto (%lf, %lf) nao esta dentro do circulo indicado.\n", x, y);
                strcpy(cor, "magenta");
                Circ ponto = criaCirc(xAux, yAux, raio, cor, cor, "");
                Reta conexao = criaReta(xAux, xCircAux, yAux, yCircAux, cor, "");
                insLista(circulos, ponto);
                insLista(retas, conexao);
                return;
            }
        }
        posic = prxPosicLista(circulos, posic);
    }

    posic = primeiraPosicLista(retas);
    while(posic){
        Reta reta = getLista(retas, posic);
        if(strcmp(id, getIDReta(reta)) == 0){
            char* x1RetaAux = getX1Reta(reta);
            char* y1RetaAux = getY2Reta(reta);
            char* x2RetaAux = getX2Reta(reta);
            char* y2RetaAux = getY2Reta(reta);

            double x1Reta; 
            double y1Reta;
            double x2Reta; 
            double y2Reta; 

            sscanf(x1RetaAux, "%lf", &x1Reta);
            sscanf(y1RetaAux, "%lf", &y1Reta);
            sscanf(x2RetaAux, "%lf", &x2Reta);
            sscanf(y2RetaAux, "%lf", &y2Reta);

            char cor[10]; 
            char x2[999];
            char y2[999];

            sprintf(x2, "%lf", (x1Reta + x2Reta)/2);
            sprintf(y2, "%lf", (y1Reta + y2Reta)/2);

            double coefAng = (y2Reta - y1Reta)/(x2Reta - x1Reta);
            double coefLin = y1Reta - coefAng * x1Reta;

            if(x*coefAng+coefLin - y < 0.001 && x*coefAng+coefLin - y > -0.001){
                if(x > MIN(x1Reta, x2Reta) && x < MAX(x1Reta, x2Reta && y > MIN(y1Reta, y2Reta) && y < MAX(y1Reta, y2Reta))){
                    fprintf(txtFile, "O ponto (%lf, %lf) esta dentro da reta indicada.\n", x, y); 
                    strcpy(cor, "magenta");
                    Circ ponto = criaCirc(xAux, yAux, raio, cor, cor, "");
                    Reta conexao = criaReta(xAux, x2, yAux, y2, cor, "");
                    insLista(circulos, ponto);
                    insLista(retas, conexao);
                    return;
                }else{
                    fprintf(txtFile, "O ponto (%lf, %lf) nao esta dentro da reta indicada.\n", x, y);
                    strcpy(cor, "magenta");
                    Circ ponto = criaCirc(xAux, yAux, raio, cor, cor, "");
                    Reta conexao = criaReta(xAux, x2, yAux, y2, cor, "");
                    insLista(circulos, ponto);
                    insLista(retas, conexao);
                    return;
                }  
            }
        }
        posic = prxPosicLista(retas, posic);
    }
}

void pnt(FILE* txtFile, Lista retangulos, Lista circulos, Lista textos, Lista retas){
    char* id = strtok(NULL, " ");
    char* corB = strtok(NULL, " ");
    char* corP = strtok(NULL, " ");

    fprintf(txtFile, "pnt %s %s %s\n", id, corB, corP);

    ListaPosic posic = primeiraPosicLista(retangulos);
    while(posic){
        Retang retang = getLista(retangulos, posic);
        if(strcmp(id, getIDRetang(retang)) == 0){
            fprintf(txtFile, "Cores originais: %s e %s\n", getCorBordaRetang(retang), getCorDentroRetang(retang));
            setCorBordaRetang(retang, corB);
            setCorDentroRetang(retang, corP);
            return;
        }
        posic = prxPosicLista(retangulos, posic);
    }

    posic = primeiraPosicLista(circulos);
    while(posic){
        Circ circ = getLista(circulos, posic);
        if(strcmp(id, getIDCirc(circ)) == 0){
            fprintf(txtFile, "Cores originais: %s e %s\n", getCorBordaCirc(circ), getCorDentroCirc(circ));
            setCorBordaCirc(circ, corB);
            setCorDentroCirc(circ, corP);
            return;
        }
        posic = prxPosicLista(circulos, posic);
    }

    posic = primeiraPosicLista(textos);
    while(posic){
        Texto texto = getLista(textos, posic);
        if(strcmp(id, getIDTexto(texto)) == 0){
            fprintf(txtFile, "Cores originais: %s e %s\n", getCorBordaTexto(texto), getCorDentroTexto(texto));
            setCorBordaTexto(texto, corB);
            setCorDentroTexto(texto, corP);
            return;
        }
        posic = prxPosicLista(textos, posic);
    }

    posic = primeiraPosicLista(retas);
    while(posic){
        Reta reta = getLista(retas, posic);
        if(strcmp(id, getIDReta(reta)) == 0){
            fprintf(txtFile, "Cor original: %s\n", getCorReta(reta));
            setCorReta(reta, corB);
            return;
        }
        posic = prxPosicLista(retas, posic);
    }
}

void delf(FILE* txtFile, Lista retangulos, Lista circulos, Lista textos, Lista retas){
    char* id = strtok(NULL, " ");

    fprintf(txtFile, "delf %s\n", id);

    ListaPosic posic = primeiraPosicLista(retangulos);
    while(posic){
        Retang retang = getLista(retangulos, posic);
        if(strcmp(id, getIDRetang(retang)) == 0){
            fprintf(txtFile, "Forma removida: Retangulo\n Coordenada x: %s\n Coordenada y: %s\n Altura: %s\n Largura: %s\n Cor Borda: %s\n Cor Dentro: %s\n Identificador: %s\n", getXRetang(retang), getYRetang(retang), getARetang(retang), getLRetang(retang), getCorBordaRetang(retang), getCorDentroRetang(retang), getIDRetang(retang));
            removeLista(retangulos, posic);
            return;
        }
        posic = prxPosicLista(retangulos, posic);
    }

    posic = primeiraPosicLista(circulos);
    while(posic){
        Circ circ = getLista(circulos, posic);
        if(strcmp(id, getIDCirc(circ)) == 0){
            fprintf(txtFile, "Forma removida: Circulo\n Coordenada x: %s\n Coordenada y: %s\n Raio: %s\n Cor Borda: %s\n Cor Dentro: %s\n Identificador: %s\n", getXCirc(circ), getYCirc(circ), getRaioCirc(circ), getCorBordaCirc(circ), getCorDentroCirc(circ), getIDCirc(circ));
            removeLista(circulos, posic);
            return;
        }
        posic = prxPosicLista(circulos, posic);
    }

    posic = primeiraPosicLista(textos);
    while(posic){
        Texto texto = getLista(textos, posic);
        if(strcmp(id, getIDTexto(texto)) == 0){
            fprintf(txtFile, "Forma removida: Texto\n Coordenada x: %s\n Coordenada y: %s\n conteudo: %s\n Cor Borda: %s\n Cor Dentro: %s\n Identificador: %s\n", getXTexto(texto), getYTexto(texto), getTextoTexto(texto), getCorBordaTexto(texto), getCorDentroTexto(texto), getIDTexto(texto));
            removeLista(textos, posic);
            return;
        }
        posic = prxPosicLista(textos, posic);
    }

    posic = primeiraPosicLista(retas);
    while(posic){
        Reta reta = getLista(retas, posic);
        if(strcmp(id, getIDReta(reta)) == 0){
            fprintf(txtFile, "Forma removida: Reta\n Coordenada x1: %s\n Coordenada y1: %s\n Coordenada x2 %s\n Coordenada y2: %s\n Cor: %s\n Identificador: %s\n",getX1Reta(reta), getY1Reta(reta), getX2Reta(reta), getY2Reta(reta), getCorReta(reta), getIDReta(reta));
            removeLista(retas, posic);
            return;
        }
        posic = prxPosicLista(retas, posic);
    }
}

void psh(FILE* txtFile, Lista retangulos, Lista circulos, Lista textos, Lista retas, Pilha* pilhas){
    char* pilhaAux = strtok(NULL, " ");
    int pilha;
    sscanf(pilhaAux, "%d", &pilha);
    char* id = strtok(NULL, " ");

    fprintf(txtFile, "psh %s %s\n", pilhaAux, id);

    ListaPosic posic = primeiraPosicLista(retangulos);
    while(posic){
        Retang retang = getLista(retangulos, posic);
        if(strcmp(id, getIDRetang(retang)) == 0){
            insPilha(pilhas[pilha], retang);
            return;
        }
        posic = prxPosicLista(retangulos, posic);
    }

    posic = primeiraPosicLista(circulos);
    while(posic){
        Circ circ = getLista(circulos, posic);
        if(strcmp(id, getIDCirc(circ)) == 0){
            insPilha(pilhas[pilha], circ);
            return;
        }
        posic = prxPosicLista(circulos, posic);
    }

    posic = primeiraPosicLista(textos);
    while(posic){
        Texto texto = getLista(textos, posic);
        if(strcmp(id, getIDTexto(texto)) == 0){
            insPilha(pilhas[pilha], texto);
            return;
        }
        posic = prxPosicLista(textos, posic);
    }

    posic = primeiraPosicLista(retas);
    while(posic){
        Reta reta = getLista(retas, posic);
        if(strcmp(id, getIDReta(reta)) == 0){
            insPilha(pilhas[pilha], retas);
            return;
        }
        posic = prxPosicLista(retas, posic);
    }
}

// A fazer, T-2
void pop(FILE* txtFile, Lista retangulos, Lista circulos, Lista textos, Lista retas, Pilha* pilhas){

}

void inf(FILE* txtFile, Lista retangulos, Lista circulos, Lista textos, Lista retas, Fila* filas){
    char* filaAux = strtok(NULL, " ");
    int fila;
    sscanf(filaAux, "%d", &fila);
    char* id = strtok(NULL, " ");

    fprintf(txtFile, "i? %s %s\n", filaAux, id);

    ListaPosic posic = primeiraPosicLista(retangulos);
    while(posic){
        Retang retang = getLista(retangulos, posic);
        if(strcmp(id, getIDRetang(retang)) == 0){
            insFila(filas[fila], retang);
            return;
        }
        posic = prxPosicLista(retangulos, posic);
    }

    posic = primeiraPosicLista(circulos);
    while(posic){
        Circ circ = getLista(circulos, posic);
        if(strcmp(id, getIDCirc(circ)) == 0){
            insFila(filas[fila], circ);
            return;
        }
        posic = prxPosicLista(circulos, posic);
    }

    posic = primeiraPosicLista(textos);
    while(posic){
        Texto texto = getLista(textos, posic);
        if(strcmp(id, getIDTexto(texto)) == 0){
            insFila(filas[fila], texto);
            return;
        }
        posic = prxPosicLista(textos, posic);
    }

    posic = primeiraPosicLista(retas);
    while(posic){
        Reta reta = getLista(retas, posic);
        if(strcmp(id, getIDReta(reta)) == 0){
            insFila(filas[fila], retas);
            return;
        }
        posic = prxPosicLista(retas, posic);
    }
}

// A fazer, T-2
void rmf(FILE* txtFile, Lista retangulos, Lista circulos, Lista textos, Lista retas, Fila* filas){

}

void ii(FILE* txtFile, Lista retangulos, Lista circulos, Lista textos, Lista retas, Lista* listas, ListaPosic* registradores){
    char* numListaAux = strtok(NULL, " ");
    int numLista;
    char* id = strtok(NULL, " ");
    char* regAux = strtok(NULL, " ");
    int reg;
    sscanf(numListaAux, "%d", &numLista);
    sscanf(regAux, "%d", &reg);

    fprintf(txtFile, "i? %s %s %s\n", numListaAux, id, regAux);

    ListaPosic posic = primeiraPosicLista(retangulos);
    while(posic){
        Retang retang = getLista(retangulos, posic);
        if(strcmp(id, getIDRetang(retang)) == 0){
            ListaPosic primeiro = primeiraPosicLista(listas[numLista]);
            registradores[reg] = insAntesLista(listas[numLista], primeiro, retang);
            return;
        }
        posic = prxPosicLista(retangulos, posic);
    }

    posic = primeiraPosicLista(circulos);
    while(posic){
        Circ circ = getLista(circulos, posic);
        if(strcmp(id, getIDCirc(circ)) == 0){
            ListaPosic primeiro = primeiraPosicLista(listas[numLista]);
            registradores[reg] = insAntesLista(listas[numLista], primeiro, circ);
            return;
        }
        posic = prxPosicLista(circulos, posic);
    }

    posic = primeiraPosicLista(textos);
    while(posic){
        Texto texto = getLista(textos, posic);
        if(strcmp(id, getIDTexto(texto)) == 0){
            ListaPosic primeiro = primeiraPosicLista(listas[numLista]);
            registradores[reg] = insAntesLista(listas[numLista], primeiro, texto);
            return;
        }
        posic = prxPosicLista(textos, posic);
    }

    posic = primeiraPosicLista(retas);
    while(posic){
        Reta reta = getLista(retas, posic);
        if(strcmp(id, getIDReta(reta)) == 0){
            ListaPosic primeiro = primeiraPosicLista(listas[numLista]);
            registradores[reg] = insAntesLista(listas[numLista], primeiro, reta);
            return;
        }
        posic = prxPosicLista(retas, posic);
    }
}

void ifl(FILE* txtFile, Lista retangulos, Lista circulos, Lista textos, Lista retas, Lista* listas, ListaPosic* registradores){
    char* numListaAux = strtok(NULL, " ");
    int numLista;
    char* id = strtok(NULL, " ");
    char* regAux = strtok(NULL, " ");
    int reg;
    sscanf(numListaAux, "%d", &numLista);
    sscanf(regAux, "%d", &reg);

    fprintf(txtFile, "i? %s %s %s\n", numListaAux, id, regAux);

    ListaPosic posic = primeiraPosicLista(retangulos);
    while(posic){
        Retang retang = getLista(retangulos, posic);
        if(strcmp(id, getIDRetang(retang)) == 0){
            registradores[reg] = insLista(listas[numLista], retang);
            return;
        }
        posic = prxPosicLista(retangulos, posic);
    }

    posic = primeiraPosicLista(circulos);
    while(posic){
        Circ circ = getLista(circulos, posic);
        if(strcmp(id, getIDCirc(circ)) == 0){
            registradores[reg] = insLista(listas[numLista], circ);
            return;
        }
        posic = prxPosicLista(circulos, posic);
    }

    posic = primeiraPosicLista(textos);
    while(posic){
        Texto texto = getLista(textos, posic);
        if(strcmp(id, getIDTexto(texto)) == 0){
            registradores[reg] = insLista(listas[numLista], texto);
            return;
        }
        posic = prxPosicLista(textos, posic);
    }

    posic = primeiraPosicLista(retas);
    while(posic){
        Reta reta = getLista(retas, posic);
        if(strcmp(id, getIDReta(reta)) == 0){
            registradores[reg] = insLista(listas[numLista], reta);
            return;
        }
        posic = prxPosicLista(retas, posic);
    }
}

void ia(FILE* txtFile, Lista retangulos, Lista circulos, Lista textos, Lista retas, Lista* listas, ListaPosic* registradores){
    char* numListaAux = strtok(NULL, " ");
    int numLista;
    char* id = strtok(NULL, " ");
    char* regAux1 = strtok(NULL, " ");
    char* regAux2 = strtok(NULL, " ");
    int reg1;
    int reg2;

    fprintf(txtFile, "i? %s %s %s %s\n", numListaAux, id, regAux1, regAux2);

    sscanf(numListaAux, "%d", &numLista);
    sscanf(regAux1, "%d", &reg1);
    sscanf(regAux2, "%d", &reg2);

    ListaPosic posic = primeiraPosicLista(retangulos);
    while(posic){
        Retang retang = getLista(retangulos, posic);
        if(strcmp(id, getIDRetang(retang)) == 0){
            registradores[reg2] = insAntesLista(listas[numLista], registradores[reg1], retang);
            return;
        }
        posic = prxPosicLista(retangulos, posic);
    }

    posic = primeiraPosicLista(circulos);
    while(posic){
        Circ circ = getLista(circulos, posic);
        if(strcmp(id, getIDCirc(circ)) == 0){
            registradores[reg2] = insAntesLista(listas[numLista],registradores[reg1], circ);
            return;
        }
        posic = prxPosicLista(circulos, posic);
    }

    posic = primeiraPosicLista(textos);
    while(posic){
        Texto texto = getLista(textos, posic);
        if(strcmp(id, getIDTexto(texto)) == 0){
            registradores[reg2] = insAntesLista(listas[numLista], registradores[reg1], texto);
            return;
        }
        posic = prxPosicLista(textos, posic);
    }

    posic = primeiraPosicLista(retas);
    while(posic){
        Reta reta = getLista(retas, posic);
        if(strcmp(id, getIDReta(reta)) == 0){
            registradores[reg2] = insAntesLista(listas[numLista], registradores[reg1], reta);
            return;
        }
        posic = prxPosicLista(retas, posic);
    }
}

void id(FILE* txtFile, Lista retangulos, Lista circulos, Lista textos, Lista retas, Lista* listas, ListaPosic* registradores){
    char* numListaAux = strtok(NULL, " ");
    int numLista;
    char* id = strtok(NULL, " ");
    char* regAux1 = strtok(NULL, " ");
    char* regAux2 = strtok(NULL, " ");
    int reg1;
    int reg2;

    sscanf(numListaAux, "%d", &numLista);
    sscanf(regAux1, "%d", &reg1);
    sscanf(regAux2, "%d", &reg2);

    fprintf(txtFile, "i? %s %s %s %s\n", numListaAux, id, regAux1, regAux2);

    ListaPosic posic = primeiraPosicLista(retangulos);
    while(posic){
        Retang retang = getLista(retangulos, posic);
        if(strcmp(id, getIDRetang(retang)) == 0){
            registradores[reg2] = insDepoisLista(listas[numLista], registradores[reg1], retang);
            return;
        }
        posic = prxPosicLista(retangulos, posic);
    }

    posic = primeiraPosicLista(circulos);
    while(posic){
        Circ circ = getLista(circulos, posic);
        if(strcmp(id, getIDCirc(circ)) == 0){
            registradores[reg2] = insDepoisLista(listas[numLista],registradores[reg1], circ);
            return;
        }
        posic = prxPosicLista(circulos, posic);
    }

    posic = primeiraPosicLista(textos);
    while(posic){
        Texto texto = getLista(textos, posic);
        if(strcmp(id, getIDTexto(texto)) == 0){
            registradores[reg2] = insDepoisLista(listas[numLista], registradores[reg1], texto);
            return;
        }
        posic = prxPosicLista(textos, posic);
    }

    posic = primeiraPosicLista(retas);
    while(posic){
        Reta reta = getLista(retas, posic);
        if(strcmp(id, getIDReta(reta)) == 0){
            registradores[reg2] = insDepoisLista(listas[numLista], registradores[reg1], reta);
            return;
        }
        posic = prxPosicLista(retas, posic);
    }
}

void da(FILE* txtFile, Lista retangulos, Lista circulos, Lista textos, Lista retas, Lista* listas, ListaPosic* registradores){
    char* numListaAux = strtok(NULL, " ");
    int numLista;
    char* regAux = strtok(NULL, " ");
    int reg;

    fprintf(txtFile, "i? %s %s\n", numListaAux, regAux);

    sscanf(numListaAux, "%d", &numLista);
    sscanf(regAux, "%d", &reg);

    ListaPosic anterior = antPosicLista(listas[numLista], registradores[reg]);
    removeLista(listas[numLista], anterior);

}

void dd(FILE* txtFile, Lista retangulos, Lista circulos, Lista textos, Lista retas, Lista* listas, ListaPosic* registradores){
    char* numListaAux = strtok(NULL, " ");
    int numLista;
    char* regAux = strtok(NULL, " ");
    int reg;

    fprintf(txtFile, "i? %s %s\n", numListaAux, regAux);

    sscanf(numListaAux, "%d", &numLista);
    sscanf(regAux, "%d", &reg);

    ListaPosic proximo = prxPosicLista(listas[numLista], registradores[reg]);
    removeLista(listas[numLista], proximo);
}

// A fazer, T-2
void dpl(FILE* txtFile, Lista retangulos, Lista circulos, Lista textos, Lista retas, Lista* listas){

}

void  leQry(char* BED, char* BSD, char* qry, char* geo, Lista retangulos, Lista circulos, Lista textos, Lista retas){
    if( BED == NULL || BSD == NULL || qry == NULL || retangulos == NULL || circulos == NULL || textos == NULL || retas == NULL){
        return;
    }

    int tamBED = strlen(BED);
    int tamQry = strlen(qry);

    int temBarra = BED[tamBED-1] == '/';

    char* qryCaminho = malloc(tamBED + tamQry + 1 + !temBarra);

    if(qryCaminho == NULL){
        return;
    }

    if(temBarra){
        sprintf(qryCaminho, "%s%s", BED, qry);
    } else{
        sprintf(qryCaminho, "%s/%s", BED, qry);
    }
    
    FILE* qryFile = (fopen(qryCaminho, "r"));

    free(qryCaminho);

    char* geoNome = strtok(geo, ".");
    char* qryNome = strtok(qry, ".");
    qryNome = strrchr(qryNome, '/')+1;
    int tamBSD = strlen(BSD);
    temBarra = BSD[tamBSD-1] == '/';

    char* svgNome = malloc(tamBSD + strlen(geoNome) + strlen(qryNome) + 6 + !temBarra);
    char* txtNome = malloc(tamBSD + strlen(geoNome) + strlen(qryNome) + 6 + !temBarra);

    if(temBarra){
        sprintf(svgNome, "%s%s-%s.svg", BSD, geoNome, qryNome);
    } else{
        sprintf(svgNome, "%s/%s-%s.svg", BSD, geoNome, qryNome);
    }

    if(temBarra){
        sprintf(txtNome, "%s%s-%s.txt", BSD, geoNome, qryNome);
    } else{
        sprintf(txtNome, "%s/%s-%s.txt", BSD, geoNome, qryNome);
    }

    FILE* svg = fopen(svgNome,"w");
    fprintf(svg, "<svg>\n");

    Fila filas[10];
    Pilha pilhas[10];
    Lista listas[10];
    ListaPosic registradores[10];

    for(int i = 0; i < 10; i++){
        filas[i] = criaFila();
        pilhas[i] = criaPilha();
        listas[i] = criaLista();
        registradores[i] = NULL;
    }

    FILE* txtFile = (fopen(txtNome, "w"));

    char aux[999];    

    while(1){
        fgets(aux, 999, qryFile);
        if(feof(qryFile)){
            break;
        }

        if(aux[strlen(aux)-1] == '\n'){
            aux[strlen(aux)-1] = '\0';
        }
        
        char* arg = strtok(aux, " ");

        if(strcmp(arg, "o?") == 0){
            overlap(txtFile, retangulos, circulos, retas);
            continue;
        }

        if(strcmp(arg, "i?") == 0){
            inside(txtFile, retangulos, circulos, retas);
            continue;
        }

        if(strcmp(arg, "pnt") == 0){
            pnt(txtFile, retangulos, circulos, textos, retas);
            continue;
        }

        if(strcmp(arg, "delf") == 0){
            delf(txtFile, retangulos, circulos, textos, retas);
            continue;
        }

        if(strcmp(arg, "psh") == 0){
            psh(txtFile, retangulos, circulos, textos, retas, pilhas);
            continue;
        }

        if(strcmp(arg, "pop") == 0){
            pop(txtFile, retangulos, circulos, textos, retas, pilhas);
            continue;
        }

        if(strcmp(arg, "inf") == 0){
            inf(txtFile, retangulos, circulos, textos, retas, filas);
            continue;
        }

        if(strcmp(arg, "rmf") == 0){
            rmf(txtFile, retangulos, circulos, textos, retas, filas);
            continue;
        }

        if(strcmp(arg, "ii") == 0){
            ii(txtFile, retangulos, circulos, textos, retas, listas, registradores);
            continue;
        }

        if(strcmp(arg, "if") == 0){
            ifl(txtFile, retangulos, circulos, textos, retas, listas, registradores);
            continue;
        }

        if(strcmp(arg, "ia") == 0){
            ia(txtFile, retangulos, circulos, textos, retas, listas, registradores);
            continue;
        }

        if(strcmp(arg, "id") == 0){
            id(txtFile, retangulos, circulos, textos, retas, listas, registradores);
            continue;
        }

        if(strcmp(arg, "da") == 0){
            da(txtFile, retangulos, circulos, textos, retas, listas, registradores);
            continue;
        }

        if(strcmp(arg, "dd") == 0){
            dd(txtFile, retangulos, circulos, textos, retas, listas, registradores);
            continue;
        }

        if(strcmp(arg, "dpl") == 0){
            dpl(txtFile, retangulos, circulos, textos, retas, listas);
            continue;
        }
    }  

    ListaPosic posic = primeiraPosicLista(retangulos);
    while(posic){
        Retang retang = getLista(retangulos, posic);
        retangSvg(svg, retang);
        posic = prxPosicLista(retangulos, posic);
    }

    posic = primeiraPosicLista(circulos);
    while(posic){
        Circ circ = getLista(circulos, posic);
        circSvg(svg, circ);
        posic = prxPosicLista(circulos, posic);
    }

    posic = primeiraPosicLista(textos);
    while(posic){
        Texto texto = getLista(textos, posic);
        textoSvg(svg, texto);
        posic = prxPosicLista(textos, posic);
    }

    posic = primeiraPosicLista(retas);
    while(posic){
        Reta reta = getLista(retas, posic);
        retaSvg(svg, reta);
        posic = prxPosicLista(retas, posic);
    }

    fprintf(svg, "</svg>");
}