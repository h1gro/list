#include <stdio.h>
#include <assert.h>

#include "List.h"
#include "ListDump.h"

const char* SHIFT = "      ";

void LinearDump(struct list_t* list, int anchor, const char* func)
{
    PrintListInfInFile(list, anchor, func);

    fprintf(list->dump, SHIFT);
    for (size_t i = 0; i < LIST_SIZE; i++)
    {
        fprintf(list->dump, "%4lu", i);
    }

    fprintf(list->dump, "\ndata: ");
    PrintArrayInFile(list, list->data);

    fprintf(list->dump, "next: ");
    PrintArrayInFile(list, list->next);

    fprintf(list->dump, "prev: ");
    PrintArrayInFile(list, list->prev);

    fprintf(list->dump, "\n<<<<<<<<<<<<<<<<<<<THE END OF DUMP>>>>>>>>>>>>\n\n");
}

void PrintArrayInFile(struct list_t* list, int* array)
{
    for (size_t i = 0; i < LIST_SIZE; i++)
    {
        fprintf(list->dump, "%4d", array[i]);
    }

    fprintf(list->dump, "\n");
}

void PrintListInfInFile(struct list_t* list, int anchor, const char* func)
{
    assert(list);
    assert(list->dump);

    fprintf(list->dump, "func call  = %s\n, anchor     = %d\n, list->free = %d\n,"
                        "list size  = %lu\n\n", func, anchor, list->free, LIST_SIZE);
}
