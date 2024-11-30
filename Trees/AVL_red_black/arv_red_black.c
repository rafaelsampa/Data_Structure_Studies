#include <stdio.h>
#include <stdlib.h>
#include "arv_red_black.h"

/** RULES ==========================
 *  
 * Red-black properties:
 * 1. Every node is either red or black.
 * 2. The root and leaves (NIL’s) are black.
 * 3. If a node is red, then its parent is black.
 * 4. All simple paths from any node x to a
 *    descendant leaf have the same number
 *    of black nodes = black-height(x). 
 * 
**/

struct arv_redb {
    int value;
    char colour;
    Arv_RB * next_left;
    Arv_RB * next_right;
    Arv_RB * parent;
};

Arv_RB * create_tree(int v){
    Arv_RB * node = (Arv_RB*) malloc(sizeof(Arv_RB));

    node->value = v;
    node->colour = 'B';
    node->parent = NULL;
    node->next_left = NULL;
    node->next_right = NULL;

    return node;
}

void calculate_height(){
    // Obedecer a formula de h<= 2lg(n+1)

}

Arv_RB* create_node(int value) {
    Arv_RB* node = (Arv_RB*) malloc(sizeof(Arv_RB));
    node->value = value;
    node->colour = 'R'; // Nó recém-criado é vermelho
    node->next_left = NULL;
    node->next_right = NULL;
    node->parent = NULL;
    return node;
}

// Rotação para a esquerda
void rotate_left(Arv_RB* root, Arv_RB* node) {
    Arv_RB* right_child = node->next_right;
    node->next_right = right_child->next_left;

    if (right_child->next_left != NULL) {
        right_child->next_left->parent = node;
    }

    right_child->parent = node->parent;

    if (node->parent == NULL) {
        root = right_child;
    } else if (node == node->parent->next_left) {
        node->parent->next_left = right_child;
    } else {
        node->parent->next_right = right_child;
    }

    right_child->next_left = node;
    node->parent = right_child;
}

// Rotação para a direita
void rotate_right(Arv_RB* root, Arv_RB* node) {
    Arv_RB* left_child = node->next_left;
    node->next_left = left_child->next_right;

    if (left_child->next_right != NULL) {
        left_child->next_right->parent = node;
    }

    left_child->parent = node->parent;

    if (node->parent == NULL) {
        root = left_child;
    } else if (node == node->parent->next_right) {
        node->parent->next_right = left_child;
    } else {
        node->parent->next_left = left_child;
    }

    left_child->next_right = node;
    node->parent = left_child;
}

// Ajusta a árvore após a inserção
void organize_colour_and_configuration_insert(Arv_RB* root, Arv_RB* node) {
    while (node->parent != NULL && node->parent->colour == 'R') {
        Arv_RB* grandparent = node->parent->parent;

        if (node->parent == grandparent->next_left) {
            Arv_RB* uncle = grandparent->next_right;
            if (uncle != NULL && uncle->colour == 'R') { // Caso 1: tio vermelho
                node->parent->colour = 'B';
                uncle->colour = 'B';
                grandparent->colour = 'R';
                node = grandparent;
            } else {
                if (node == node->parent->next_right) { // Caso 2: zigue-zague
                    node = node->parent;
                    rotate_left(root, node);
                }
                node->parent->colour = 'B';
                grandparent->colour = 'R';
                rotate_right(root, grandparent);
            }
        } else { // Situação espelhada para o lado direito
            Arv_RB* uncle = grandparent->next_left;
            if (uncle != NULL && uncle->colour == 'R') {
                node->parent->colour = 'B';
                uncle->colour = 'B';
                grandparent->colour = 'R';
                node = grandparent;
            } else {
                if (node == node->parent->next_left) {
                    node = node->parent;
                    rotate_right(root, node);
                }
                node->parent->colour = 'B';
                grandparent->colour = 'R';
                rotate_left(root, grandparent);
            }
        }
    }
    root->colour = 'B'; // A raiz é sempre preta
}

// Inserção na árvore
void insert(Arv_RB* root, int value) {
    Arv_RB* new_node = create_node(value);
    Arv_RB* parent = NULL;
    Arv_RB* current = root;

    while (current != NULL) {
        parent = current;
        if (value < current->value) {
            current = current->next_left;
        } else {
            current = current->next_right;
        }
    }

    new_node->parent = parent;

    if (parent == NULL) {
        root = new_node; // Criação da raiz
    } else if (value < parent->value) {
        parent->next_left = new_node;
    } else {
        parent->next_right = new_node;
    }

    organize_colour_and_configuration_insert(root, new_node);
}

void print_tree(Arv_RB* root, int space) {
    if (root == NULL)
        return;

    // Aumenta a distância entre os níveis
    space += 10;

    // Primeiro imprime a subárvore direita
    print_tree(root->next_right, space);

    // Imprime o nó atual após o espaçamento
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }

    // Cor do nó (vermelho ou preto)
    printf("%d(%c)\n", root->value, root->colour);

    // Depois imprime a subárvore esquerda
    print_tree(root->next_left, space);
}