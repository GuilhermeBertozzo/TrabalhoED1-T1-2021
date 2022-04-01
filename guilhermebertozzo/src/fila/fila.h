#ifndef MODULO_FILA
#define MODULO_FILA

typedef struct fila* Fila;
typedef struct filaPosic* FilaPosic;
typedef void* FilaElem;

// Cria uma fila usando as structs fila e filaPosic.
Fila criaFila();

// Retorna o tamanho da fila fila.
int tamFila(Fila fila);

// Insere o elemento elemento no final da fila fila.
FilaPosic insFila(Fila fila, FilaElem elemento);

// Remove o elemento na primeira posicao da fila fila.
void removeFila(Fila fila);

// Retorna o elemento na posicao posic da fila fila.
FilaElem getFila(Fila fila, FilaPosic posic);

// Retorna o elemento na primeira posicao da fila fila.
FilaPosic primeiraPosicFila(Fila fila);

// Retorna o elemento na posicao posterior a posic da fila fila.
FilaPosic prxPosicFila(Fila fila, FilaPosic posic);

// Retorna o elemento da ultima posicao da fila fila.
FilaPosic ultimaPosicFila(Fila fila);

// Desfaz todos os elementos da fila fila, liberando toda a memoria. 
void desfazFila(Fila fila);

#endif