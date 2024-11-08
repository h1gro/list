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

    list->dump = fopen(DUMP, "w+");

    assert(list->dump);

    list->data[0] = POISON;
    list->prev[0] = 0;
    list->next[0] = 0;
    list->free    = 1;

    FillingArraysStart(list);

    list->next[LIST_SIZE - 1] = 0;

    list->dump_html = fopen(DUMP_HTML, "w");

    assert(list->dump_html);
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
        printf("fclose_return from list->dump = %d\n", fclose_return);
    }

    fclose_return = fclose(list->dump_html);

    if (fclose_return != 0)
    {
        printf("fclose_return from list->dump_html = %d\n", fclose_return);
    }
}

void FillingArraysStart(struct list_t* list)
{
    for (size_t i = 1; i < LIST_SIZE; i++)
    {
        list->next[i] = i + 1;
        list->prev[i] = INVALID_ADDR;
        //printf("next[%lu] = %d\n prev[%lu] = %d\n", i, list->next[i], i, list->prev[i]);
    }
}
