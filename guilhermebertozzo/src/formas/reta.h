#ifndef MODULO_RETA
#define MODULO_RETA

#include <stdio.h>

typedef struct reta* Reta; 

// Cria uma struct do tipo Reta que armazena as coordenadas, a cor e o id da reta.
Reta criaReta(char* x1, char* x2, char* y1, char* y2, char* cor, char* ID);

// Retorna o elemento x1 da Reta reta.
char* getX1Reta(Reta reta);

// Retorna o elemento x2 da Reta reta.
char* getX2Reta(Reta reta);

// Retorna o elemento y1 da Reta reta.
char* getY1Reta(Reta reta);

// Retorna o elemento y2 da Reta reta.
char* getY2Reta(Reta reta);

// Retorna o elemento cor da Reta reta.
char* getCorReta(Reta reta);

// Altera a cor da Reta reta para a cor cor. 
void setCorReta(Reta reta, char* cor);

// Retorna o elemento id da Reta reta.
char* getIDReta(Reta reta);

// Desfar a struct reta, liberando toda a memoria alocada.
void desfazReta(Reta reta);

// Cria uma reta no arquivo svg de acordo com as informacoes armazenadas em reta.
void retaSvg(FILE* svg, Reta reta);

#endif