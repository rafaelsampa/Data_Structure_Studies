#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree_bs.h"

typedef struct tree_binary Tree_Bi;

struct tree_binary{
    int key;
    Tree_Bi *parent;
    Tree_Bi *next_child_left;
    Tree_Bi *next_child_right;
};

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


int main (){
    // Teste: Criar uma arvore com 5 elementos
    /***
     * 
     * 
     * 
     *            a
     *         /     \
     *        b        c
     *     /     \     ...null
     *    d        e
     *  /   \     /   \
     * null null  null null
     * 
     * 
    * ***/

    // Tree_Bi *treeA = create_tree(6);
    // Tree_Bi *treeB = create_tree(4);
    // Tree_Bi *treeC = create_tree(8);
    // Tree_Bi *treeD = create_tree(3);
    // Tree_Bi *treeE = create_tree(5);
    
    // tree_bi_insert(treeA, treeB);
    // tree_bi_insert(treeA, treeC);``
    // tree_bi_insert(treeB, treeD);
    // tree_bi_insert(treeB, treeE);

    // tree_bi_imprime(treeA);




    
    return 0;
}

// Funções presentes no Slide ===================================================

Tree_Bi * create_tree(int k){
    Tree_Bi *tree = (Tree_Bi*) malloc(sizeof(Tree_Bi));
    tree->key = k;
    tree->parent = NULL;
    tree->next_child_left = NULL;
    tree->next_child_right = NULL;
    return tree;
}

Tree_Bi * create_empty_tree(){
    return NULL;
}

void tree_bi_imprime(Tree_Bi *t){
    if(t != NULL){
        tree_bi_imprime(t->next_child_left);
        printf("\n %d", t->key);
        tree_bi_imprime(t->next_child_right);
    }
}

Tree_Bi * tree_bi_search(Tree_Bi *t, int k){
    if(t == NULL || k == t->key){
        return t;
    }
    if(k < t->key){
        return tree_bi_search(t->next_child_left, k);
    }else{
        return tree_bi_search(t->next_child_right, k);
    }
}

Tree_Bi * tree_minimum(Tree_Bi *t) {
    while(t->next_child_left != NULL){
        t = t->next_child_left;
    }
    return t;
}

Tree_Bi * tree_maximum(Tree_Bi *t){
    while(t->next_child_right != NULL){
        t = t->next_child_right;
    }
    return t;
}

Tree_Bi* tree_successor(Tree_Bi* t){
    if(t->next_child_right != NULL){
        return tree_minimum(t->next_child_right);
    }else{
        Tree_Bi* aux = t->parent;
        while(aux != NULL && t == aux->next_child_right){
            t = aux;
            aux = aux->parent;
        }
        return aux;
    }
}
Tree_Bi* tree_predecessor(Tree_Bi* t){
    if(t->next_child_left != NULL){
        return tree_maximum(t->next_child_left);
    }else{
        Tree_Bi* aux = t->parent;
        while(aux != NULL && t == aux->next_child_left){
            t = aux;
            aux = aux->parent;
        }
        return aux;
    }
}
void transplant(Tree_Bi *root, Tree_Bi *u, Tree_Bi *v){
    if(u->parent == NULL){
        root = v;
    }else
    if(u == u->parent->next_child_left){
        u->parent->next_child_left = v;
    }else{
        u->parent->next_child_right = v;
    }

    if(v != NULL){
        v->parent = u->parent;
    }
}

void tree_bi_insert(Tree_Bi *t, Tree_Bi *subt){

    Tree_Bi *current = t;
    Tree_Bi *parent = NULL;

    if(t == NULL){
        t = subt;
        return;
    }
    while(current != NULL){
        parent = current;
        if(subt->key < current->key){
            current = current->next_child_left;
        }else{
            current = current->next_child_right;
        }
    }
    if(parent == NULL){
        t = subt;
    }else 
    if(subt->key < parent->key){
        parent->next_child_left = subt;
    }else{
        parent->next_child_right = subt;
    }
}

void tree_bi_remove(Tree_Bi *root, Tree_Bi *z){
    Tree_Bi *aux;

    if(z->next_child_left == NULL){
        transplant(root, z, z->next_child_right);
    }else
    if(z->next_child_right == NULL){
        transplant(root, z, z->next_child_left);
    }else{
        aux = tree_minimum(z->next_child_right);
        
        if(aux != z->next_child_right){
            transplant(root, aux, aux->next_child_right);
            aux->next_child_right = z->next_child_right;
            aux->next_child_right->parent = aux;
        }
        transplant(root, z, aux);

        aux->next_child_left = z->next_child_left;
        aux->next_child_left->parent = aux;
    }
}

void tree_bi_free(Tree_Bi *t){
    if(t != NULL){
        tree_bi_free(t->next_child_left);
        tree_bi_free(t->next_child_right);
        free(t);
    }
}
