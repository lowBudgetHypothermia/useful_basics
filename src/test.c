#include <stdlib.h> // malloc, rand, free
#include <stdio.h> // printf
#include <time.h> // srand

#include "ufb/list.h"


struct Person {
    int age;
    char name[];
};

int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void ll_display(llist_t *ll) {
    printf("ll_display:\n");
    ll_node_t *itr;
    for(itr = ll->head; itr->next; itr = itr->next) {
        struct Person *p = (struct Person *)itr->data;
        printf("Name: %c, Age: %i\n", *p->name, p->age);
    }
    struct Person *p = (struct Person *)itr->data;
    printf("Name: %c, Age: %i\n\n", *p->name, p->age);
}

int main(int argc, char *argv[]) {
    int rc = 0;

    llist_t *ll = malloc(sizeof(llist_t));
    rc = ll_init(ll);

    /* randomly generate objects &
     * append them to linked list */
    int k;
    int min = 12, max = 80;
    srand(time(NULL));
    for(k=0; k<3; k++) {
        struct Person *tmp = malloc(sizeof(struct Person));
        tmp->age = rand_range(min, max);
        tmp->name[0] = (char)'A' + rand_range(0, 25);
        ll_pushback(ll, tmp);
    }

    ll_display(ll);

    /* check popped back data */
    while(ll->head) {
        struct Person *p_tmp;
        ll_popback(ll, (void **)&p_tmp);
        p_tmp = (struct Person *)p_tmp;
        printf("popped back:\nname: %s, age: %i\n\n", (char *)p_tmp->name, p_tmp->age);
        free(p_tmp);
    }

    /* clear check */
    printf("clear check:\nll->len: %i\n", ll->len);
    if(ll->tail) printf("ll->head: %p, name: %s\n", ll->tail, ((struct Person *)ll->tail->data)->name);

    free(ll);

    return 0;
}
