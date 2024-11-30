#include <stdio.h>
#include <stdlib.h>
#include "arv_red_black.h"

// Main Code para testar o codigo =========================================
int main() {
    Arv_RB* root = NULL; // Início da árvore como NULL

    insert(root, 10); // Inserir nó na árvore
    insert(root, 20);
    insert(root, 15);
    insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    print_tree(root, 0);

    printf("Árvore Red-Black construída com sucesso!\n");

    return 0;
}



