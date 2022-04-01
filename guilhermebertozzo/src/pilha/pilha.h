#ifndef MODULO_PILHA
#define MODULO_PILHA

typedef struct pilha* Pilha;
typedef struct pilhaPosic* PilhaPosic;
typedef void* PilhaElem;

// Cria uma pilha usando as structs pilha e pilhaPosic.
Pilha criaPilha();

// Retorna o tamanho da pilha pilha.
int tamPilha(Pilha pilha);

// Insere o elemento elemento no fim da pilha pilha.
PilhaPosic insPilha(Pilha pilha, PilhaElem elemento);

// Remove o elemento da ultima posicao da pilha pilha. 
void removePilha(Pilha pilha);

// Retorna o elemento na posicao posic da pilha pilha.
PilhaElem getPilha(Pilha pilha, PilhaPosic posic);

// Retorna o elemento na posicao anterior a posic da pilha pilha.
PilhaPosic antPosicPilha(Pilha pilha, PilhaPosic posic);

// Retorna o elemento na ultima posicao da pilha pilha.
PilhaPosic ultimaPosicPilha(Pilha pilha);

// Desfaz todos os elementos da pilha pilha, liberando toda a memoria.
void desfazPilha(Pilha pilha);

#endif