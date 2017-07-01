#include <stdio.h>

typedef struct list_item list_item_t;
typedef struct list_item list_t;

struct list_item
{
    list_item_t *next_p;
    list_item_t *prev_p;
};

#define LIST_DECLARE(name) \
    LIST_T name = {&(name), &(name)}

#define LIST_INIT(head_p) \
    do { \
        (head_p)->next_p = (head_p); \
        (head_p)->prev_p = (head_p); \
    } while (0)

#define LIST_ITEM_INIT(item_p) \
    LIST_INIT(item_p)

#define LIST_ADD(item_p, head_p) \
    do {\
        (item_p)->next_p = (head_p)->next_p; \
        (item_p)->prev_p = (head_p); \
        (head_p)->next_p = (item_p); \
        (item_p)->next_p->prev_p = (item_p); \
    } while(0)

#define LIST_ADD_TAIL(item_p, head_p) \
    do { \
        (item_p)->prev_p = (head_p)->prev_p; \
        (item_p)->next_p = (head_p); \
        (head_p)->prev_p = (item_p); \
        (item_p)->prev_p->next_p = (item_p);  \
    } while(0)


