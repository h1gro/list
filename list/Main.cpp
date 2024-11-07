#include "List.h"
#include "PushPop.h"
#include "ListDump.h"
#include <assert.h>

int main()
{
    struct list_t list = {};

    ListCtor(&list);

    ListPush(&list, 10, 0);
    ListPush(&list, 20, 1);
    ListPop(&list, 1);
    ListPush(&list, 30, 1);
    ListPush(&list, 40, 2);
    ListPop(&list, 1);
    ListPop(&list, 2);

    ListDtor(&list);

    return 0;
}
