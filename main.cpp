#include <stdio.h>

#include "general.h"
#include "C_Dtor.h"
#include "PushPop.h"
#include "ListDump.h"

int main()
{
    struct list_t list = {};

    ListCtor(&list);

    ListPush(&list, 10, 1);
    ListPush(&list, 20, 2);
    ListPush(&list, 30, 3);
    ListPush(&list, 40, 2);
    ListPush(&list, 50, 1);

    fprintf(list.dump, "\n                 last dump from main\n");
    list.func_call = __func__;
    ListDump(&list);

    ListDtor(&list);
}
