#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int key; 
    int height;
    struct AVLNode* left;  
    struct AVLNode* right;
    struct AVLNode* parent;  
} AVLNode;

AVLNode* create_node(int key, AVLNode* parent){
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->height = 1; 
    node->left = NULL;
    node->right = NULL;
    node->parent = parent;
    return node;
}

int get_height(AVLNode* node){
    return (node == NULL) ? 0 : node->height;
}

AVLNode* create_tree(){
    return NULL; 
}

int get_balance(AVLNode* node){
    return (node == NULL) ? 0 : get_height(node->left) - get_height(node->right);
}

void update_height(AVLNode* node){
    if(node != NULL){
        int left_height = get_height(node->left);
        int right_height = get_height(node->right);
        node->height = 1 + (left_height > right_height ? left_height : right_height);
    }
}

// Rotação direita
AVLNode* rotate_right(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    if (T2 != NULL) T2->parent = y;
    x->parent = y->parent;
    y->parent = x;

    update_height(y);
    update_height(x);

    return x;
}

// Rotação esquerda
AVLNode* rotate_left(AVLNode* x){
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    if (T2 != NULL) T2->parent = x;
    y->parent = x->parent;
    x->parent = y;

    update_height(x);
    update_height(y);

    return y;
}

AVLNode* balance(AVLNode* node) {
    if(node == NULL){
        return NULL;
    }
    update_height(node);

    int balance_factor = get_balance(node);

    // Caso 1: Desbalanceado à esquerda (Left-Left)
    if(balance_factor > 1 && get_balance(node->left) >= 0){
        return rotate_right(node);
    }

    // Caso 2: Desbalanceado à direita (Right-Right)
    if(balance_factor < -1 && get_balance(node->right) <= 0){
        return rotate_left(node);
    }

    // Caso 3: Desbalanceado à esquerda-direita (Left-Right)
    if(balance_factor > 1 && get_balance(node->left) < 0){
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    // Caso 4: Desbalanceado à direita-esquerda (Right-Left)
    if(balance_factor < -1 && get_balance(node->right) > 0){
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node; // Balançåda
}

AVLNode* avl_insert(AVLNode* root, AVLNode* z){
    if(root == NULL){
        return z; 
    }

    if(z->key < root->key){
        root->left = avl_insert(root->left, z);
        root->left->parent = root;
    }else
    if(z->key > root->key){
        root->right = avl_insert(root->right, z);
        root->right->parent = root; 
    }else{
        return root;
    }

    // Balan a subarvore depois do insert
    return balance(root);
}

int main(){
    AVLNode* tree = create_tree();

    AVLNode* node1 = create_node(10, NULL);
    tree = avl_insert(tree, node1);
    AVLNode* node2 = create_node(20, NULL);
    tree = avl_insert(tree, node2);
    AVLNode* node3 = create_node(30, NULL);
    tree = avl_insert(tree, node3);
    AVLNode* node4 = create_node(40, NULL);
    tree = avl_insert(tree, node4);
    AVLNode* node5 = create_node(50, NULL);
    tree = avl_insert(tree, node5);

    printf("Raiz após inserções: %d\n", tree->key);
    printf("Altura da árvore: %d\n", tree->height);

    return 0;
}

