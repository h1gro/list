#include <assert.h>

#include "List.h"
#include "ListDump.h"

void ListPush(struct list_t* list, int elem, int anchor)
{
    assert(list);
    assert(list->data);
    assert(list->next);
    assert(list->prev);

    if (anchor > list->number_elements)
    {
        printf("anchor > number_elements\n");
        return;
    }

    list->number_elements++;

    //ListDump(list, anchor, __func__, __LINE__, "i smotry goluy list");

    list->data[list->free] = elem;
    //ListDump(list, anchor, __func__, __LINE__, "i clady element");

    int index = list->next[list->free];

    list->next[list->free] = list->next[anchor];
    //ListDump(list, anchor, __func__, __LINE__, "addr next elem v next[free]");

    list->next[anchor] = list->free;
    //ListDump(list, anchor, __func__, __LINE__, "addr current elem v next[anchor]");

    list->prev[list->next[list->free]] = list->free;
    //ListDump(list, anchor, __func__, __LINE__, "addr prev elem v prev[anchor]");

    list->prev[list->free] = anchor;
    //ListDump(list, anchor, __func__, __LINE__, "addr prev elem v prev[free]");

    list->free = index;

    #ifdef DEBUG
    ListDump(list, anchor,  __func__, __LINE__, "i have pushed element");
    #endif
}

void ListPop(struct list_t* list, int anchor)
{
    assert(list);
    assert(list->data);
    assert(list->next);
    assert(list->prev);

    list->data[anchor] = POISON;
    //ListDump(list, anchor, __func__, __LINE__, "delete elem");

    list->next[list->prev[anchor]] = list->next[anchor];
    //ListDump(list, anchor, __func__,  __LINE__, "prisvoil next[prev[anchor]] = next[anchor]");

    list->prev[list->next[anchor]] = list->prev[anchor];
    //ListDump(list, anchor, __func__,  __LINE__, "prisviol prev[next[anchor]] = prev[anchor]");

    list->next[anchor] = INVALID_ADDR;
    //ListDump(list, anchor, __func__, __LINE__, "delete next[anchor]");

    list->prev[anchor] = INVALID_ADDR;
    //ListDump(list, anchor, __func__,  __LINE__, "delete prev[anchor]");

    #ifdef DEBUG
    ListDump(list, anchor, __func__, __LINE__, "i have deleted elem at anchor");
    #endif
}
