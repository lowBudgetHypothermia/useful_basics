#ifndef UFB_BINTREE_H
#define UFB_BINTREE_H

typedef struct _bt_node {
    int data;
    struct _bt_node *less;
    struct _bt_node *greater;
} bt_node_t;

int bt_init(bt_node_t *bt);

int _bt_insert(bt_node_t *bt_root, bt_node_t *new);

int bt_add(bt_node_t *bt_root, int data);

int bt_remove(bt_node_t *bt_root, int data);

#endif  // UFB_BINTREE_H
