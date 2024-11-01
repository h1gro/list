#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "general.h"
#include "C_Dtor.h"

void ListCtor(struct list_t* list)
{
    // TODO: assert(list)?
    list->data = (int*) calloc(SIZE, sizeof(int)); 
    list->next = (int*) calloc(SIZE, sizeof(int)); 
    list->prev = (int*) calloc(SIZE, sizeof(int)); 

    assert(list->data); 
    assert(list->next); 
    assert(list->prev); 

    list->head = 1;
    list->tail = 1;
    list->curr = 1;

    list->dump = fopen(DUMP, "w+"); // TODO: Почему w+ вместо w?

    assert(list->dump); 

    list->data[0] = POISON;

    FillingListPoison(list);

    list->prev[1] = 0;
}

void ListDtor(struct list_t* list)
{
    assert(list->dump);

    free(list->data);
    free(list->next);
    free(list->prev);

    fclose(list->dump); // TODO: Проверь возвращаемое значение fclose

    list->head = 1;
    list->tail = 1;
}

void FillingListPoison(struct list_t* list)
{
    for (int i = 1; i < SIZE; i++)
    {
        list->next[i] = INVALID_ADDR;
        list->prev[i] = INVALID_ADDR; // TODO: Добавь POISON для data
    }
}
