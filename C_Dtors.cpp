#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "general.h"
#include "C_Dtor.h"

void ListCtor(struct list_t* list)
{
    list->data = (int*) calloc(SIZE, sizeof(int));
    list->next = (int*) calloc(SIZE, sizeof(int));
    list->prev = (int*) calloc(SIZE, sizeof(int));

    assert(list->data);
    assert(list->next);
    assert(list->prev);

    list->head = 1;
    list->tail = 1;

    list->data[0] = POISON;

    FillingListPoison(list);
}

void ListDtor(struct list_t* list)
{
    free(list->data);
    free(list->next);
    free(list->prev);

    list->head = 1;
    list->tail = 1;
}

void FillingListPoison(struct list_t* list)
{
    for (int i = 1; i <= SIZE; i++)
    {
        list->next[i] = INVALID_ADDR;
        list->prev[i] = INVALID_ADDR;
    }
}
