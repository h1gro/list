#include <stdio.h>
#include <assert.h>

#include "general.h"
#include "Checks.h"
#include "C_Dtor.h"

void ListChecks(struct list_t* list)
{
    if (list->head == SIZE)
    {
        printf("user eblan, head == SIZE\n");
    }

    if (list->tail == 0)
    {
        printf("user eblan, tale == 0\n");
    }
}
