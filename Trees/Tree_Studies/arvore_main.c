#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore_aula1.h"


int main(){
    srand(time(NULL));

    // Altere AQUI o máximo do intevalo de numeros aletorios, que vai de 0 até o limite.
    int limite = 10;

    Arv* a1 = arv_cria(gerar_num_aletorio(limite),arv_criavazia(), arv_criavazia()); 
    Arv* a2 = arv_cria(gerar_num_aletorio(limite), arv_criavazia(), arv_criavazia());
    Arv* a3 = arv_cria(gerar_num_aletorio(limite),a1, a2);

    Arv* a8 = arv_cria(gerar_num_aletorio(limite),arv_criavazia(), arv_criavazia());
    Arv* a9 = arv_cria(gerar_num_aletorio(limite),arv_criavazia(), arv_criavazia());
    Arv* a10 = arv_cria(gerar_num_aletorio(limite),a8, a9);

    Arv* a4 = arv_cria(gerar_num_aletorio(limite),arv_criavazia(), arv_criavazia());
    Arv* a5 = arv_cria(gerar_num_aletorio(limite),arv_criavazia(), a10);
    Arv* a6 = arv_cria(gerar_num_aletorio(limite),a4, a5);

    Arv* a = arv_cria(gerar_num_aletorio(limite),a3, a6);

    printf("\n");
    arv_imprime(a);    
    printf("\n");
    
    Arv* b = copia(a);
    arv_imprime(b);
    printf("\n");

    // Arv* b = copia(a);
    // arv_imprime(b);
    

    printf("\nQtd de numeros pares: %d \n", pares(a));
    printf("Qtd de folhas: %d \n", folhas(a));
    printf("Qtd de nós com apenas um filho: %d \n", um_filho(a));

    printf("Iguais?  %d \n", igual(a3,copia(a3)));
    
    printf("\n");
    arv_libera(a);
    arv_libera(b);
    return 0;
}