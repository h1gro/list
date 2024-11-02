#include <assert.h>
#include <stdlib.h>

#include "List.h"
#include "ListDump.h"

const char* SHIFT = "      ";

void ListDump(struct list_t* list)
{
    assert(list);
    assert(list->data);
    assert(list->next);
    assert(list->prev);
    assert(list->head > 0);
    assert(list->tail > 0);
    assert(list->dump);

    PrintListInfInFile(list);

    fprintf(list->dump, SHIFT);
    for (size_t i = 0; i < LIST_SIZE; i++)
    {
        fprintf(list->dump, "%4lu", i);
    }

    fprintf(list->dump, "\ndata: ");
    PrintArrayInFile(list->data, list);

    fprintf(list->dump, "next: ");
    PrintArrayInFile(list->next, list);

    fprintf(list->dump, "prev: ");
    PrintArrayInFile(list->prev, list);

    fprintf(list->dump, "\n<<<<<<<<<<<<<<<<<<<THE END OF DUMP>>>>>>>>>>>>\n\n");
}

void PrintArrayInFile(int* array, struct list_t* list)
{
    for (size_t i = 0; i < LIST_SIZE; i++)
    {
        fprintf(list->dump, "%4d", array[i]);
    }

    fprintf(list->dump, "\n");
}

void PrintListInfInFile(struct list_t* list)
{
    fprintf(list->dump, "func call  = %s\n", list->func_call);
    fprintf(list->dump, "anchor     = %d\n", list->anchor);
    fprintf(list->dump, "list->curr = %d\n", list->curr);
    fprintf(list->dump, "list->head = %d\n", list->head);
    fprintf(list->dump, "list->tail = %d\n", list->tail);
    fprintf(list->dump, "list size  = %lu\n\n", LIST_SIZE);
}
