#ifndef MODULO_LISTA
#define MODULO_LISTA

typedef struct lista* Lista; 
typedef struct listaPosic* ListaPosic;
typedef void* ListaElem;

// Cria uma lista usando as structs lista e ListaPosic. 
Lista criaLista(); 

// Retorna o tamanho da lista lista.
int tamLista(Lista lista); 

// Insere um elemento elemento no final da lista lista.
ListaPosic insLista(Lista lista, ListaElem elemento); 

// Remove o elemento da posicao posic da lista lista. 
void removeLista(Lista lista, ListaPosic posic); 

// Retorna o elemento da posicao posic da lista lista. 
ListaElem getLista(Lista lista, ListaPosic posic); 

// Insere o elemento elemento antes da posicao posic da lista lista.
ListaPosic insAntesLista(Lista lista, ListaPosic posic, ListaElem elemento); 

// Insere o elemento elemento depois da posicao posic da lista lista. 
ListaPosic insDepoisLista(Lista lista, ListaPosic posic, ListaElem elemento); 

// Retorna o elemento na primeira posicao da lista lista.
ListaPosic primeiraPosicLista(Lista lista); 

// Retorna o elemento na posicao posterior a posic da lista lista.
ListaPosic prxPosicLista(Lista lista, ListaPosic posic);

// Retorna o elemento na posicao anterior a posic da lista lista.
ListaPosic antPosicLista(Lista lista, ListaPosic posic);

// Retorna o elemento na ultima posicao da lista lista.
ListaPosic ultimaPosicLista(Lista lista);

// Desfaz todos os elementos da lista lista, liberando toda a memoria alocada. 
void desfazLista(Lista lista);

#endif