#ifndef UFB_LIST_H
#define UFB_LIST_H


typedef struct ll_node {
    void *data;
    struct ll_node *next;
} ll_node_t;

typedef struct {
    unsigned int len;
    ll_node_t *head;
    ll_node_t *tail;
} llist_t;

int ll_init(llist_t *ll);

int ll_pushback(llist_t *ll, void *data);

int ll_popback(llist_t *ll, void **back);

#endif  // UFB_LIST_H
