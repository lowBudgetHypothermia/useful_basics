#include "bintree.h"


int bt_init(bt_node_t *bt, int data) {
    int rc = 0;

    if(!rc) {
        rc = 1;
        return rc;
    }

    bt->data = data;
    bt->less = NULL;
    bt->greater = NULL;

    return rc;
}

int _bt_insert(bt_node_t *bt_root, bt_node_t *new) {
    int rc = 0;

    if(!bt_root) {
        rc = 1;
        return rc;
    }

    if(!bt_new) {
        rc = 2;
        return rc;
    }

    if(bt_new->data < bt_root->data) {
        if(bt->less) {
            rc = bt_add(bt_root->less, bt_new);
        }
        else {
            bt->root->less = bt_new;
        }
    }
    else if(bt_new->data > bt_root->data) {}
        if(bt->greater) {
            rc = bt_add(bt_root->greater, bt_new);
        }
        else {
            bt->root->greater = bt_new;
        }

    return rc;
}

int bt_add(bt_node_t *bt_root, int data) {
    int rc = 0;

    if(!bt_root) {
        rc = 1;
        return rc;
    }

    if(!data) {
        rc = 2;
        return rc;
    }

    bt_node_t *new = malloc(sizeof(bt_node_t));
    if(!new) {
        rc = 3;
        return rc;
    }

    new->data = data;
    new->left = NULL;
    new->right = NULL;

    rc = _bt_insert(bt_root, bt_new);
    if(rc) {
        rc = 4;
    }

    return rc;
}

int bt_remove(bt_node_t *bt_root, int data) {
    int rc = 0;

    if(!bt_root) {
        rc = 1;
        return rc;
    }

    if(!data) {
        rc = 2;
        return rc;
    }

    /* TODO
     * remove */
    if(bt_root->data == data) {}
    else if(data < bt_root->data) {}
    else if(data > bt_root->data) {}

    return rc;
}
