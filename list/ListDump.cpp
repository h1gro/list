#include <assert.h>

#include "List.h"
#include "ListDump.h"

void ListDump(struct list_t* list, int anchor, const char* func, int line, const char* str)
{
    assert(list);
    assert(list->data);
    assert(list->next);
    assert(list->prev);
    assert(list->dump);
    assert(list->dump_html);

    GraphDump(list, anchor, func, line, str);

    LinearDump(list, anchor, func);
}

