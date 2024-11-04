#include "List.h"

void ListChecks(struct list_t* list)
{
    if (list->head == LIST_SIZE)
    {
        printf("user eblan, head == SIZE\n");
    }

    if (list->tail == 0)
    {
        printf("user eblan, tale == 0\n");
    }
}
