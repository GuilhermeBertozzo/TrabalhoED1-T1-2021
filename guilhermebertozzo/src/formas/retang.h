#ifndef MODULO_RETANG
#define MODULO_RETANG

#include <stdio.h>

typedef struct retang* Retang; 

// Cria uma struct do tipo Retang que armazena as coordenadas, a altura, a largura, as cores da borda e do preenximento e o id do retangulo.
Retang criaRetang(char* x, char* y, char* a, char* l, char* corBorda, char* corDentro, char* ID);

// Retorna o elemento x do retangulo retang.
char* getXRetang(Retang retang);

// Retorna o elemento y do retangulo retang.
char* getYRetang(Retang retang);

// Retorna o elemento altura do retangulo retang.
char* getARetang(Retang retang);

// Retorna o elemento largura do retangulo retang.
char* getLRetang(Retang retang);

// Retorna o elemento cor de borda do retangulo retang.
char* getCorBordaRetang(Retang retang);

// Altera a cor da borda de Retang retang para a cor cor. 
void setCorBordaRetang(Retang retang, char* cor);

// Retorna o elemento cor de preeximento do retangulo retang.
char* getCorDentroRetang(Retang retang);

// Altera a cor da borda de Retang retang para a cor cor. 
void setCorDentroRetang(Retang retang, char* cor);

// Retorna o elemento id do retangulo retang.
char* getIDRetang(Retang retang);

// Desfar a struct retang, liberando toda a memoria alocada.
void desfazRetang(Retang retang);

// Cria um retangulo no arquivo svg de acordo com as informacoes armazenadas em retang.
void retangSvg(FILE* svg, Retang retang);

#endif