#include "List.h"
#include "PushPop.h"
#include "ListDump.h"

int main()
{
    struct list_t list = {};

    ListCtor(&list);

    ListPush(&list, 10, 0);
    ListPush(&list, 20, 1);

    ListDtor(&list);

    //FILE* dump_html = fopen(DUMP_HTML, "w");
    //fclose(dump_html);
    return 0;
}
