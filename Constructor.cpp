#include <assert.h>
#include <stdlib.h>

#include "List.h"

void ListCtor(struct list_t* list)
{
    assert(list);

    list->data = (int*) calloc(LIST_SIZE, sizeof(int));
    list->next = (int*) calloc(LIST_SIZE, sizeof(int));
    list->prev = (int*) calloc(LIST_SIZE, sizeof(int));

    assert(list->data);
    assert(list->next);
    assert(list->prev);

    list->head = 1;
    list->tail = 1;
    list->curr = 1;

    list->dump = fopen(DUMP, "w+");

    assert(list->dump);

    list->data[0] = POISON;

    FillingNextPrevPoison(list);

    list->prev[1] = 0;
}

void ListDtor(struct list_t* list)
{
    assert(list->dump);

    free(list->data);
    free(list->next);
    free(list->prev);

    int fclose_return = fclose(list->dump);

    if (fclose_return != 0)
    {
        printf("fclose_return = %d\n", fclose_return);
    }

    list->head = 1;
    list->tail = 1;
}

void FillingNextPrevPoison(struct list_t* list)
{
    for (size_t i = 1; i < LIST_SIZE; i++)
    {
        list->next[i] = INVALID_ADDR;
        list->prev[i] = INVALID_ADDR;
    }
}
