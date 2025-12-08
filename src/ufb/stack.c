#include <stdlib.h>

#include "stack.h"


int s_init(stack_t *stack) {
    int rc = 0;
    if (!stack) {
        rc = 1;
        return rc;
    }

    stack->len = 0;
    stack->head = NULL;

    return rc;
}

int s_push(stack_t *stack, void *data) {
    int rc = 0;
    if (!stack) {
        rc = 1;
        return rc;
    }

    if (!data) {
        rc = 2;
        return rc;
    }

    s_item_t *item = malloc(sizeof(s_item_t));
    if (!item) {
        rc = 3;
        return rc;
    }

    item->data = data;
    item->next = NULL;

    if (!stack->head) {
        stack->head = item;
        stack->len++;

        return rc;
    }

    item->next = stack->head;
    stack->head = item;
    stack->len++;

    return rc;
}

int s_pop(stack_t *stack, void **data) {
    int rc = 0;
    if (!stack) {
        rc = 1;
        return rc;
    }

    if (!data) {
        rc = 2;
        return rc;
    }

    if (!stack->head) {
        int rc = 3;
        return rc;
    }

    *data = stack->head->data;
    s_item_t *old_head = stack->head;

    if (!stack->head->next) {
        stack->head = NULL;
    } else {
        stack->head = stack->head->next;
    }

    stack->len--;
    free(old_head);

    return rc;
}
