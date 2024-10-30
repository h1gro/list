#include <stdio.h>

#include "general.h"
#include "C_Dtor.h"
#include "PushPop.h"

int main()
{
    struct list_t list = {};

    ListCtor(&list);

    ListPush(&list, 10, 1);
    ListPush(&list, 20, 2);
    ListPush(&list, 30, 3);

    ListDtor(&list);
}
