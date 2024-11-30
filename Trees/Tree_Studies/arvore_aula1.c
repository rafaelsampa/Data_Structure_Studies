#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore_aula1.h"

struct arv
{
    // char info;
    int info;
    Arv* esq; // Sub-arvore a esquerda
    Arv* dir; // Sub-arvore a direita
};

Arv* arv_criavazia(){
    return NULL;
}

int arv_vazia(Arv* a){
    return a == NULL;
}

Arv* arv_cria(int value, Arv* sae, Arv* sad){
    Arv* a = (Arv*) malloc (sizeof(Arv));
    a->info = value;
    a->esq = sae;
    a->dir = sad;
    return a;

}

int arv_pertence(Arv* a, int c)
{
    if(arv_vazia(a)){
        return 0; // arvore vazia
    }else{
        return (a->info == c || arv_pertence(a->esq, c) || arv_pertence(a->dir, c));
    }
}
void arv_libera(Arv* a){
    if (!arv_vazia(a)){
        arv_libera(a->esq); // Libera a arvore a ESQ da arvore "a" (Recusividade)
        arv_libera(a->dir); // Libera a arvore a DIR da arvore "a" (Recusividade)
        free(a);
    }
}

void arv_imprime(Arv* a){
    if (!arv_vazia(a)) {
        printf("%d ", a->info);
        arv_imprime(a->esq);
        arv_imprime(a->dir);
    }
}

int max2 (int a, int b){
    return (a>b)? a:b;
}

int arv_altura ( Arv* a){
    if (arv_vazia(a)){
        return -1;
    }else{
        return 1 + max2 ( arv_altura(a->esq), arv_altura(a->dir));
    }
}

int gerar_num_aletorio(int limite){
    int numero_aletorio = rand() % limite;
    return numero_aletorio;
}

int pares (Arv* a){
    if (arv_vazia(a)){
        return 0;
    }
    int contador_de_num_pares = 0;
    if(a->info % 2 == 0){
        contador_de_num_pares++;
    }
    contador_de_num_pares = contador_de_num_pares + pares(a->esq);
    contador_de_num_pares = contador_de_num_pares + pares(a->dir);
    return contador_de_num_pares;
    
}

int folhas(Arv* a){
    if (arv_vazia(a)){
        return 0;
    }
    int contador_de_folhas = 0;
    if(a->esq ==  NULL && a->dir == NULL){
        contador_de_folhas++;
    }
    contador_de_folhas = contador_de_folhas + folhas(a->esq);
    contador_de_folhas = contador_de_folhas + folhas(a->dir);
    return contador_de_folhas;
}

int um_filho (Arv* a){
    if (arv_vazia(a)){
        return 0;
    }
    int contador_de_um_filho = 0;

    // PRIMEIRA TENTATIVA DE CONDICIONAL = (arv_vazia(a->esq)&&!arv_vazia(a->esq))||(!arv_vazia(a->esq)&&arv_vazia(a->esq))
    // SEGUNDA TENTATIVA DE CONDICIOANL = (arv_vazia(a->esq) && arv_vazia(a->dir)) == 0
    // TERCEIRA TENTATIVA DE CONDICIONAL = (arv_vazia(a->esq)==1 && arv_vazia(a->dir)==0) || (arv_vazia(a->esq)==0 && arv_vazia(a->dir)==1)
    // Terceiro deu bom
    if((arv_vazia(a->esq)==1 && arv_vazia(a->dir)==0) || (arv_vazia(a->esq)==0 && arv_vazia(a->dir)==1)) {
        contador_de_um_filho++;
    }
    contador_de_um_filho = contador_de_um_filho + um_filho(a->esq);
    contador_de_um_filho = contador_de_um_filho + um_filho(a->dir);
    return contador_de_um_filho;
}

int igual (Arv* a, Arv* b){

    if(arv_vazia(a) && arv_vazia(b)){
        return 1;
    }else{
        int confirmar_igualidade = 0;
        if(a->info == b->info){
            // OK
            confirmar_igualidade = 1;
            confirmar_igualidade = igual(a->esq, b->esq);
            confirmar_igualidade = igual(a->dir, b->dir);
            return confirmar_igualidade;
        }else{
            return 0;
        }
    }
    return 0;
}

Arv* copia(Arv* a){
    if(arv_vazia(a)){
        return NULL;
    }else{
        return arv_cria(a->info, copia(a->esq), copia(a->dir));
    }
}