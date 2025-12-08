#ifndef UFB_STACK_H
#define UFB_STACK_H


typedef struct s_item {
    void *data;
    struct s_item *next;
} s_item_t;

typedef struct {
    unsigned int len;
    s_item_t *head;
} stack_t;

int s_init(stack_t *stack);

int s_push(stack_t *stack, void *data);

int s_pop(stack_t *stack, void **data);

#endif  // UFB_STACK_H
