#include <stdio.h>

// TODO: Сделай названия файлов в одном стиле
// TODO: Сделай один header "List.h", в котором будут определяться:
//           - Структура списка
//           - Функции списка
//           - Константы
//       Функции дампа оставь в отдельном файле
#include "general.h"
#include "C_Dtor.h"
#include "PushPop.h"
#include "ListDump.h"

// TODO: В гите не должно быть бинарных файлов (list) и логов

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
    // TODO: return ??? 
}
