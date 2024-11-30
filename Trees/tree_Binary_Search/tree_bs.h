#include <stdio.h>
#include <stdlib.h>

typedef struct tree_binary Tree_Bi;

Tree_Bi * create_tree(int v);
Tree_Bi * create_empty_tree();
void tree_bi_imprime(Tree_Bi * t);
Tree_Bi * tree_bi_search(Tree_Bi * t, int k);
void tree_bi_insert(Tree_Bi * t, Tree_Bi * sub_t);
void tree_bi_remove(Tree_Bi * t, Tree_Bi * z); 
void transplant(Tree_Bi * T, Tree_Bi * subrooted_U, Tree_Bi * subrooted_V);
Tree_Bi * tree_minimum(Tree_Bi * t);
Tree_Bi * tree_maximum(Tree_Bi * t);
void tree_bi_free(Tree_Bi * t);
