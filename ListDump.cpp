#include <assert.h>
#include <stdlib.h>

#include "List.h"
#include "ListDump.h"

const char* SHIFT      = "      ";
const char* DUMP_GRAPH = "Dump.dot";

void ListDump(struct list_t* list, int anchor, int line, const char* func, const char* str)
{
    assert(list);
    assert(list->data);
    assert(list->next);
    assert(list->prev);
    assert(list->dump);
    assert(list->dump_html);

    /*Графический дамп:*/

    FILE* graph = fopen(DUMP_GRAPH, "w");

    assert(graph);

    PrintGraphHead(graph);

    PrintDefaultList(graph, list, line, func, str);

    PrintListChanges(graph, list);

    fprintf(graph, "}\n");
    fclose(graph);

    static int number_dump = 0;
    MySystem("dot Dump.dot -Tpng -o Graphs/Dump%03d.png", number_dump);

    if (number_dump == 0)
    {
        fprintf(list->dump_html, "<pre>\n");
    }

    fprintf(list->dump_html, "\n<img src = \"Graphs/Dump%03d.png\"/>\n", number_dump);
    number_dump++;

    /*Линейный текстовый дамп:*/

    PrintListInfInFile(list, func, anchor);

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

void PrintListInfInFile(struct list_t* list, const char* func, int anchor)
{
    assert(list);
    assert(list->dump);

    fprintf(list->dump, "func call  = %s\n", func);
    fprintf(list->dump, "anchor     = %d\n", anchor);
    fprintf(list->dump, "list->free = %d\n", list->free);
    fprintf(list->dump, "list size  = %lu\n\n", LIST_SIZE);
}

void PrintGraphHead(FILE* graph)
{
    assert(graph);

    fprintf(graph, "digraph G\n{\n    rankdir = LR;\n    bgcolor = \"pink2\"\n");
    fprintf(graph, "    node[color = \"#b503fc\", fontsize = 14];\n");
    fprintf(graph, "    edge[color = black, fontsize = 12];\n\n");
}

void PrintDefaultList(FILE* graph, struct list_t* list, int line, const char* func, const char* str)
{
    assert(graph);
    assert(list);
    assert(list->data);
    assert(list->next);
    assert(list->prev);
    assert(list->number_elements);
    assert(line);
    assert(str);

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

    fprintf(graph, "\n    label = \"Dump was called from func %s in line %d, list_size = %lu, list_free = %d,"
                                    " list_anchor = %d, number_elements = %d, command: %s\";\n",
                                    func, line, LIST_SIZE, list->free, list->anchor, list->number_elements, str);
}

void PrintListChanges(FILE* graph, struct list_t* list)
{
    assert(list->next);
    assert(list->prev);
    assert(graph);

    fprintf(graph, "\n    /*next nods:*/ \n");
    for (size_t i = 0; i < LIST_SIZE; i++)
    {
        if (list->next[i] != INVALID_ADDR)
        {
            fprintf(graph, "    %lu -> %d [weight = 20, color = \"red1\"];\n", i, list->next[i]);
        }
    }

    fprintf(graph, "\n    /*prev nods:*/ \n");
    for (size_t i = 0; i < LIST_SIZE; i++)
    {
        if (list->prev[i] != INVALID_ADDR)
        {
            fprintf(graph, "    %lu -> %d [weight = 20, color = \"#fc6603\"];\n", i, list->prev[i]);
        }
    }
}

void MySystem(const char* str, int number_dump)
{
    char command_dot[52] = "";

    sprintf(command_dot, str, number_dump);

    system(command_dot);
}

