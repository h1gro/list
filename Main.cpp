#include "List.h"
#include "PushPop.h"
#include "ListDump.h"

int main()
{
    struct list_t list = {};

    ListCtor(&list);

    ListPush(&list, 10, 1);

    list.func_call = __func__;
    ListDump(&list);

    ListDtor(&list);
    return 0;
}
