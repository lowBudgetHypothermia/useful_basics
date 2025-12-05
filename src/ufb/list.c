#include <stdlib.h>

#include "list.h"

int ll_init(llist_t *ll) {
    int rc = 0;
    if (!ll) {
        rc = 1;
        return rc;
    }

    ll->len = 0;
    ll->head = NULL;
    ll->tail = NULL;
}

int ll_pushback(llist_t *ll, void *data) {
    int rc = 0;
    if (!ll) {
        rc = 1;
        return rc;
    }

    ll_node_t *node = malloc(sizeof(ll_node_t));
    if (!node) {
        rc = 2;
        return rc;
    }

    node->data = data;

    if (!ll->head) {
        ll->head = node;
        ll->tail = node;
        node->next = NULL;
        ll->len++;

        return rc;
    }
    ll->tail->next = node;
    ll->tail = node;
    ll->tail->next = NULL;
    ll->len++;

    return rc;
}

int ll_popback(llist_t *ll, void **back) {
    int rc = 0;

    if (!ll) {
        rc = 1;
        return rc;
    }

    if (!ll->head) {
        rc = 2;
        return rc;
    }

    if (!ll->tail) {
        rc = 3;
        return rc;
    }

    /* return data */
    *back = ll->tail->data;

    ll_node_t *to_remove = ll->tail;

    /* check if last element in list */
    if (ll->head == ll->tail) {
        ll->head = NULL;
        ll->tail = NULL;
    } else {  /* find new tail */
        ll_node_t *new_tail = ll->head;
        while (new_tail->next != to_remove) {
            new_tail = new_tail->next;
        }
        ll->tail = new_tail;
        new_tail->next = NULL;
    }

    ll->len--;
    free(to_remove);

    return rc;
}
