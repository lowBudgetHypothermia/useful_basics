#ifndef LIST_H

#define LIST_H

/* list element */
typedef struct lst_node_t {
    void *data;
    struct lst_node_t *next;
    struct lst_node_t *prev;
} lst_node_t;

/* list */
typedef struct list_t {
    int length;
    lst_node_t *head;
    lst_node_t *tail;
} list_t;

/* functions */
int lst_push(struct list_t *lst, void *node);

int lst_pop(struct list_t *lst);

#endif
