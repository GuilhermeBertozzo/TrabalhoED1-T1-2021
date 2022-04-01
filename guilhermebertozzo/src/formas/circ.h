#ifndef MODULO_CIRC
#define MODULO_CIRC

#include <stdio.h>

typedef struct circ* Circ; 

// Cria uma struct do tipo Circ que armazena as coordenadas, o raio, as cores da borda e do preenximento e o id do circulo.
Circ criaCirc(char* x, char* y, char* raio, char* corBorda, char* corDentro, char* ID);

// Retorna o elemento x do criculo circ.
char* getXCirc(Circ circ);

// Retorna o elemento y do circulo circ.
char* getYCirc(Circ circ);

// Retorna o elemento raio do circulo circ.
char* getRaioCirc(Circ circ);

// Retorna o elemento cor da borda do circulo circ.
char* getCorBordaCirc(Circ circ);

// Altera a cor da borda de Circ circ para a cor cor. 
void setCorBordaCirc(Circ circ, char* cor);

// Retorna o elemento cor do preenximento do circulo circ.
char* getCorDentroCirc(Circ circ);

// Altera a cor de preenchimento de Circ circ para a cor cor. 
void setCorDentroCirc(Circ circ, char* cor);

// Retorna o elemento id do circulo circ.
char* getIDCirc(Circ circ);

// Desfar a struct circ, liberando toda a memoria alocada.
void desfazCirc(Circ circ);

// Cria um circulo no arquivo svg de acordo com as informacoes armazenadas em circ.
void circSvg(FILE* svg, Circ circ);

#endif