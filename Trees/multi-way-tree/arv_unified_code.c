#include <stdio.h>
#include <stdlib.h>

typedef struct arvvar ArvVar;

struct arvvar{
    int info;

    // ArvVar* sa1;
    // ArvVar* sa2;
    // ArvVar* sa3;

    // ArvVar* sa[N];

    ArvVar* prim;
    ArvVar* prox;

};

// Funções vistas em sala de aula
ArvVar* arvv_cria (int value);
void arvv_insere(ArvVar* a,ArvVar* sa);
int arvv_pertence(ArvVar* a,int value);
void arvv_libera (ArvVar* a);
void arvv_imprime (ArvVar* a);
int arvv_altura (ArvVar* a);
int max2(int a, int b);
int arvv_altura2(ArvVar* a);

// Funções da Atividade ==========
int pares(ArvVar* a); // OK
int folhas(ArvVar* a); // OK
int um_filho(ArvVar* a); // OK
int igual(ArvVar* a, ArvVar* b); // OK
ArvVar* copia(ArvVar* a); // TEST

// =================================================
//      MAIN 
// =================================================
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

// =================================================
//      FUNCOES 
// =================================================

ArvVar* arvv_cria(int value)
{
    ArvVar* a = (ArvVar*) malloc (sizeof(ArvVar));
    a->info = value;
    a->prim = NULL;
    a->prox = NULL;
    return a;
}

void arvv_insere(ArvVar* a, ArvVar* sa)
{
    sa->prox = a->prim;
    a->prim = sa;
}

int arvv_pertence(ArvVar* a,int value)
{
    ArvVar* p; // Variável auxiliar
    if(a == NULL){
        return 0;
    }
    else if (a->info == value || arvv_pertence(a->prim,value) || arvv_pertence(a->prox,value)){
        return 1;
    }
    // else{
    //     for(p= a->prim;p!=NULL;p=p->prox){
    //         if (arvv_pertence(p,c)){
    //             return 1;
    //         }
    //     } 
    // }
    return 0;
}

void arvv_libera(ArvVar* a) 
{
    // ArvVar* p = a->prim;
    // while (p != NULL) {
    //     ArvVar* t = p->prox;
    //     arvv_libera(p);
    //     p = t;
    // }
    // free(a);
    if (a != NULL) {
        arvv_libera(a->prox); /* libera irmã */
        arvv_libera(a->prim); /* libera filha */
        free(a);
    }
    // return 0;
}
//  LEO: "UMA BOA QUESTAO É DIZER A ORDEM DE IMPRESSAO DAS COISAS"

void arvv_imprime(ArvVar* a) 
{
    // ArvVar* p;
    // printf("%c ", a->info); /* mostra raiz */
    // for (p = a->prim; p != NULL; p = p->prox){
    //     arv_imprime(p);/* imprime cada sub-árvore filha */
    // }
    if (a != NULL) {
        printf("%d ", a->info); /* mostra raiz */
        arvv_imprime(a->prim); /* imprime filha */
        arvv_imprime(a->prox); /* imprime irmã*/
    }
}

int arvv_altura (ArvVar* a) {
    int hmax = -1;
    ArvVar* p;
    for(p = a->prim; p != NULL; p = p->prox){
        int h = arvv_altura(p);
        if (h >hmax){
            hmax = h;
        } 
    }
    return hmax + 1;
}

// Atividade =================================


int pares(ArvVar* a){
    if(a == NULL){
        return 0;
    }

    int count = 0;
    if(a->info % 2){
        count++;
    }
    count = count + pares(a->prox);
    count = count + pares(a->prim);
    return count;
}

int folhas (ArvVar* a){
    if(a == NULL){
        return 0;
    }
    int count = 0;
    if(a->prox == NULL){
        count++;
    }
    count = count + folhas(a->prox);
    count = count + folhas(a->prim);
    return count;
}

int um_filho(ArvVar* a){
    if(a == NULL){
        return 0;
    }
    int num_filhos = (a->prox != NULL)?1:0;
    ArvVar* c = a->prox;
    if(c != NULL && c->prox != NULL){
        num_filhos++;
    }
    int count = (num_filhos == 1)?1:0;
    count+=um_filho(a->prox);
    count+=um_filho(a->prim);
    return count;
}
int igual(ArvVar* a, ArvVar* b){
    int flagtest = 0;
    if(a == NULL && b == NULL){
        return 1;
    }
    if(a == NULL || b == NULL){
        return 0;
    }
    if(a->info != b->info){
        return 0;
    }
    if(!igual(a->prox, b->prox)){
        return 0;
    }
    return (igual(a->prim, b->prim));
}

ArvVar* copia(ArvVar* a){
    if(a == NULL){
        return NULL;
    }
    ArvVar * b = arvv_cria(a->info);
    b->prim = copia(a->prim);
    b->prox = copia(a->prox);

    return b;
}

