#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arv_numvar.h"

int main(){
    ArvVar* a = arvv_cria(1);
    ArvVar* b = arvv_cria(2);
    ArvVar* c = arvv_cria(3);
    ArvVar* e = arvv_cria(4);
    ArvVar* f = arvv_cria(5);
    ArvVar* g = arvv_cria(6);
    arvv_insere(b,e);
    arvv_insere(b,c);
    arvv_insere(a,g);
    arvv_insere(a,f);
    arvv_insere(a,b);

    printf("\nTeste 1\n\n");

    ArvVar * r = copia(a);    

    printf("\n\n-----\n");

    arvv_imprime(a);
    printf("\n");
    arvv_imprime(r);

    printf("\n");
    // printf(" %d", um_filho(a));
    printf("Teste 2");
    printf("\n");
    printf("igual: %d", igual(a,r));
    printf("\n");

    arvv_libera(a);
    arvv_libera(b);
    return 0;
}