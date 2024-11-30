#include <stdio.h>

typedef struct arv Arv;

// FUNÇÕES VISTAS EM SALA
Arv* arv_criavazia();
int arv_vazia(Arv* a);
Arv* arv_cria(int value, Arv* e, Arv* d);
int arv_pertence(Arv* a, int c);
void arv_libera(Arv* a);
void arv_imprime(Arv* a);

// FUNÇÕES AUXILIARES
int gerar_num_aletorio(int limite);

// FUNÇÕES REFERENTES A QUESTOES
int pares(Arv* a);
int folhas(Arv* a);
int um_filho (Arv* a);
int igual (Arv* a, Arv* b);
Arv* copia(Arv* a);