#include <stdio.h>
#include <stdlib.h>

typedef struct arv_redb Arv_RB;

Arv_RB* create_node(int value);
void rotate_left(Arv_RB** root, Arv_RB* node);
void rotate_right(Arv_RB** root, Arv_RB* node);
void organize_colour_and_configuration_insert(Arv_RB** root, Arv_RB* node);
void insert(Arv_RB** root, int value);