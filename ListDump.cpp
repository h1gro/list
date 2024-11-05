#include <assert.h>
#include <stdlib.h>

#include "List.h"
#include "ListDump.h"

const char* SHIFT = "      ";
const char* DUMP_GRAPH = "Dump.dot";

void ListDump(struct list_t* list)
{
    assert(list);
    assert(list->data);
    assert(list->next);
    assert(list->prev);
    assert(list->head > 0);
    assert(list->tail > 0);
    assert(list->dump);

    FILE* graph = fopen(DUMP_GRAPH, "w+");

    assert(graph);

    PrintGraphHead(graph);

    PrintDefaultList(graph, list);

    PrintListChanges(graph, list);

    fprintf(graph, "}\n");
    fclose(graph);

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
    assert(list);
    assert(list->dump);
    assert((list->anchor >= 0) && (list->curr > 0) && (list->head > 0) && (list->tail > 0));

    fprintf(list->dump, "func call  = %s\n", list->func_call);
    fprintf(list->dump, "anchor     = %d\n", list->anchor);
    fprintf(list->dump, "list->curr = %d\n", list->curr);
    fprintf(list->dump, "list->head = %d\n", list->head);
    fprintf(list->dump, "list->tail = %d\n", list->tail);
    fprintf(list->dump, "list size  = %lu\n\n", LIST_SIZE);
}

void PrintGraphHead(FILE* graph)
{
    assert(graph);

    fprintf(graph, "digraph G\n{\n    rankdir = LR;\n    bgcolor = \"pink2\"\n");
    fprintf(graph, "    node[color = blue, fontsize = 14];\n");
    fprintf(graph, "    edge[color = black, fontsize = 12];\n\n");
}

void PrintDefaultList(FILE* graph, struct list_t* list)
{
    assert(graph);
    assert(list);
    assert(list->data);
    assert(list->next);
    assert(list->prev);

    for (size_t i = 0; i < LIST_SIZE; i++)
    {
        fprintf(graph, "    %lu [shape = Mrecord, label = \"index %4lu | data %4d | next %4d | prev %4d\"];\n",
                        i, i, list->data[i], list->next[i], list->prev[i]);
    }

    fprintf(graph, "\n    0");
    for (size_t i = 1; i < LIST_SIZE; i++)
    {
        fprintf(graph, " -> %lu", i);
    }
    fprintf(graph, " [weight = 100000, color = \"pink2\"];\n");

    fprintf(graph, "\n    label = \"Dump was called from %s, list_size = %lu, head = %d, tail = %d.\";\n", list->func_call, LIST_SIZE, list->head, list->tail);
}

void PrintListChanges(FILE* graph, struct list_t* list)
{
    fprintf(graph, "\n    /*next nods:*/ \n");
    for (size_t i = 0; i < LIST_SIZE; i++)
    {
        if (list->next[i] != INVALID_ADDR)
        {
            fprintf(graph, "    %lu -> %d [color = \"red1\"];\n", i, list->next[i]);
        }
    }

    fprintf(graph, "\n    /*prev nods:*/ \n");
    for (size_t i = 0; i < LIST_SIZE; i++)
    {
        if (list->prev[i] != INVALID_ADDR)
        {
            fprintf(graph, "    %d -> %lu [color = \"orange\"];\n", list->prev[i], i);
        }
    }
}
