#ifndef GENERAL
#define GENEREL
// TODO: Проверка 'GENERAL' и define 'GENEREL'???

static const char* DUMP = "dump.txt";

const int SIZE         = 10; // TODO: SIZE чего?  
// TODO: Убери лишние пробелы
//                        ┏━━━━━━━━┓
const int POISON       = - 153; // ┃
const int INVALID_ADDR = - 1;   // ┃
//                        ┗━━━━━━━━┛

struct list_t
{
    int* data;
    int* next;
    int* prev;
    int head; // TODO: Выравнивание???
    int tail;
    int curr;
    FILE* dump; // TODO: include stdio.h
    const char* func_call;
};

enum fun_calls // TODO: Непонятное название, вдобавок нигде не используется
{
    MAIN = 1,
    PUSH = 2,
    POP  = 3,
};

#endif
