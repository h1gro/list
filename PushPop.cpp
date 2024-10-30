#include <stdio.h>
#include <assert.h>

#include "general.h"
#include "PushPop.h"
#include "Checks.h"
#include "C_Dtor.h"

void ListPush(struct list_t* list, int elem, int anchor)
{
    assert(list);
    assert(list->head > 0);

    list->data[list->head] = elem;
    list->next[list->head] = 0;
    list->head++;

    NextIndexSwap(list, anchor);

    ListChecks(list);
}

void ListPop(struct list_t* list)
{
    assert(list);
    assert(list->tail > 0);

    ListChecks(list);
}

int FindFreeSeel(struct list_t* list)
{
    for(int i = 1; i < SIZE; i++)
    {
        if (list->next[i] == INVALID_ADDR)
        {
            return i;
        }
    }

    return ERROR_FREE_SEEL;
}

void NextIndexSwap(struct list_t* list, int anchor)
{
    int free_seel = FindFreeSeel(list);

    if (free_seel == ERROR_FREE_SEEL)
    {
        printf("FREE SEEL DID NOT FIND\n");
    }

    list->next[free_seel] = list->next[anchor];
    list->next[anchor]    = free_seel;
}
