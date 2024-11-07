#include <assert.h>

#include "List.h"
#include "PushPop.h"
#include "ListDump.h"

void ListPush(struct list_t* list, int elem, int anchor)
{
    assert(list);
    assert(list->data);
    assert(list->next);
    assert(list->prev);

    list->number_elements++;
    list->anchor = anchor;

    list->free = FindFreeCeel(list->next);

    list->data[list->free] = elem;
    ListDump(list, anchor, __LINE__, __func__, "i clady element");

    list->next[list->free] = list->next[anchor];
    ListDump(list, anchor, __LINE__, __func__, "addr next elem v next[free]");

    list->next[list->anchor] = list->free;
    ListDump(list, anchor, __LINE__, __func__, "addr current elem v next[anchor]");

    list->prev[list->next[list->free]] = list->free;
    ListDump(list, anchor, __LINE__, __func__, "addr prev elem v prev[anchor]");

    list->prev[list->free] = anchor;
    ListDump(list, anchor, __LINE__, __func__, "addr prev elem v prev[free]");
}

void ListPop(struct list_t* list, int anchor)
{
    assert(list);
    assert(list->data);
    assert(list->next);
    assert(list->prev);

    list->data[anchor] = POISON;
    ListDump(list, anchor, __LINE__, __func__, "delete elem");

    list->next[list->prev[anchor]] = list->next[anchor];
    ListDump(list, anchor, __LINE__, __func__, "prisvoil next[prev[anchor]] = next[anchor]");

    list->prev[list->next[anchor]] = list->prev[anchor];
    ListDump(list, anchor, __LINE__, __func__, "prisviol prev[next[anchor]] = prev[anchor]");

    list->next[anchor] = INVALID_ADDR;
    ListDump(list, anchor, __LINE__, __func__, "delete next[anchor]");

    list->prev[anchor] = INVALID_ADDR;
    ListDump(list, anchor, __LINE__, __func__, "delete prev[anchor]");
}

int FindFreeCeel(int* array)
{
    assert(array);

    for(int i = 1; i < LIST_SIZE; i++)
    {
        if (array[i] == INVALID_ADDR)
        {
            return i;
        }
    }

    return ERROR_FREE_SEEL;
}
