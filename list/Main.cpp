#include "List.h"
#include "ListDump.h"
#include <assert.h>

int main()
{
    struct list_t list = {};

    ListCtor(&list);

    ListPush(&list, 10, 0);
    ListPush(&list, 20, 1);
    ListPush(&list, 30, 1);
    ListPush(&list, 40, 2);
    
    ListPop(&list, 2);
    ListPop(&list, 3);

    ListDtor(&list);

    return 0;
}
