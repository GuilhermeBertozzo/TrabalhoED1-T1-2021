#ifndef MODULO_TEXTO
#define MODULO_TEXTO

#include <stdio.h>

typedef struct texto* Texto; 

// Cria uma struct do tipo Texto que armazena as coordenadas, o conteudo do texto, as cores da borda e do preenximento e o id do texto.
Texto criaTexto(char* x, char* y, char* texto, char* corBorda, char* corDentro, char* ID);

// Retorna o elemento x do texto texto.
char* getXTexto(Texto texto);

// Retorna o elemento y do texto texto.
char* getYTexto(Texto texto);

// Retorna o elemento texto do texto texto.
char* getTextoTexto(Texto texto);

// Retorna o elemento cor de borda do texto texto.
char* getCorBordaTexto(Texto texto);

// Altera a cor da borda de Texto texto para a cor cor. 
void setCorBordaTexto(Texto texto, char* cor);

// Retorna o elemento cor de preeximento do texto texto.
char* getCorDentroTexto(Texto texto);

// Altera a cor da borda de Texto texto para a cor cor. 
void setCorDentroTexto(Texto texto, char* cor);

// Retorna o elemento id do texto texto.
char* getIDTexto(Texto texto);

// Desfar a struct retang, liberando toda a memoria alocada.
void desfazTexto(Texto texto);

// Cria um texto no arquivo svg de acordo com as informacoes armazenadas em texto.
void textoSvg(FILE* svg, Texto texto);

#endif