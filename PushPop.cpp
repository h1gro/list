#include <assert.h>

#include "List.h"
#include "PushPop.h"
#include "ListDump.h"

void ListPush(struct list_t* list, int elem, int anchor)
{
    assert(list);
    assert(list->head > 0);
    assert(list->tail > 0);

    list->anchor    = anchor;
    list->func_call = __func__;

    if (anchor <= 0)
    {
        printf("anchor position is invalid\n");
    }

    if (list->head > anchor)
    {
        list->head = list->curr;
    }

    if (list->curr < anchor)
    {
        list->tail = anchor;
    }

    list->data[list->curr] = elem;

    fprintf(list->dump, "\n               1 dump\n");

    ListDump(list);

    IndexSwap(list, anchor);

    list->curr++;

    ListChecks(list);

    fprintf(list->dump, "\n                 2 dump\n");
    ListDump(list);
}

void ListPop(struct list_t* list)
{
    assert(list);
    assert(list->tail > 0);

    ListChecks(list);
}

int FindFreeСeel(int* array)
{
    for(int i = 1; i < LIST_SIZE; i++)
    {
        if (array[i] == INVALID_ADDR)
        {
            return i;
        }
    }

    return ERROR_FREE_SEEL;
}

void IndexSwap(struct list_t* list, int anchor)
{
    assert(list);
    assert(list->next);
    assert(list->prev);
    assert(list->curr > 0);

    int free_seel_next = 0, free_seel_prev = 0;

    if (anchor != list->curr)
    {
        free_seel_next = FindFreeСeel(list->next);

        list->next[free_seel_next]  = list->next[anchor + 1];
        list->next[anchor + 1] = free_seel_next;
    }

    else
    {
        free_seel_next = FindFreeСeel(list->next);

        list->next[anchor] = 0;

        if (list->curr != 1)
        {
            list->next[list->curr - 1] = anchor;
        }

        /* вопросы:
        1. curr? мы идём по head или нет? // функция поиска свободной ячейки определеяет в какую ячейку класть новый элемент (LIST_CURR НЕ НУЖЕН?)

        2. push якорной позиции осуществляет либо до нее либо после, а как добавлять в 1? // ЯКОРЬ = 0!!!!

        3. что если якорная позиция > адреса последнего элемента, двигать якорь
        к последнему элементу или оставлять его без связи с другими элементами
        */   //якорь элемента может быть > адреса последнего элемента
        list->tail = free_seel_next;
    }

    if (free_seel_next == ERROR_FREE_SEEL ||free_seel_prev == ERROR_FREE_SEEL)
    {
        printf("FREE SEEL DID NOT FIND\n");
    }

    free_seel_prev = FindFreeСeel(list->prev);

    if (free_seel_prev == list->curr)
    {
        list->prev[free_seel_prev] = anchor;
    }

    else
    {
        list->prev[anchor + 1] = list->curr;
    }
}


