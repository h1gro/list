#ifndef GENERAL
#define GENEREL

static const char* DUMP = "dump.txt";

const int SIZE         = 10;
const int POISON       = - 153;
const int INVALID_ADDR = - 1;

struct list_t
{
    int* data;
    int* next;
    int* prev;
    int head;
    int tail;
    int curr;
    FILE* dump;
    const char* func_call;
};

enum fun_calls
{
    MAIN = 1,
    PUSH = 2,
    POP  = 3,
};

#endif
