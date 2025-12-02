#ifndef LIST_H
#define LIST_H

typedef ll_node {
    void *data;
    struct ll_node *next;
} ll_node_t;

typedef struct {
    int len;
    ll_node *head;
    ll_node *tail;
} llist_t;

#endif LIST_H
