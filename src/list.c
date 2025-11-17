#include <stdlib.h>

#include "list.h"

int lst_push(struct list_t *lst, void *node) {
    int rc = 0;
    lst_node_t *new = malloc(sizeof(lst_node_t));
    if (!new) {
        rc = -1;
        return rc;
    }

    new->data = node;

    // TODO
    // check if tail
    new->prev = lst->tail;
    lst->tail = new;

    return rc;
};

int lst_pop(struct list_t *lst) {
    int rc = 0;

    // TODO
    // check if tail
    lst_node_t *tail = lst->tail;

    // TODO
    // check if prev
    lst->tail = tail->prev;

    // TODO
    // check if free successful
    free(tail);

    return rc;
};
