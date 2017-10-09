#include"list.h"

static void INIT_LIST_HEAD(struct list_head* head)
{
    head->next=head;
    head->prev=head;
} 



static void _list_add(struct list_head* lst,
                    struct list_head* prev,
                    struct list_head* next)
{

}


static void list_add(struct list_head* new_node,
    struct list_head* head)
{

}


static void list_add_tail(struct list_head* new_node,
    struct list_head* head)
{

}
