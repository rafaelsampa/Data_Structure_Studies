#include <stdio.h>

typedef struct arvvar ArvVar;

ArvVar* arvv_cria (int value);
void arvv_insere(ArvVar* a,ArvVar* sa);
int arvv_pertence(ArvVar* a,int value);
void arvv_libera (ArvVar* a);
void arvv_imprime (ArvVar* a);
int arvv_altura (ArvVar* a);
int max2(int a, int b);
int arvv_altura2(ArvVar* a);

// Atividade
int pares(ArvVar* a); // OK
int folhas(ArvVar* a); // OK
int um_filho(ArvVar* a); // OK
int igual(ArvVar* a, ArvVar* b); // OK
ArvVar* copia(ArvVar* a); // TEST



