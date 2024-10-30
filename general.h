#ifndef GENERAL
#define GENEREL

const int POISON       = - 153;
const int INVALID_ADDR = - 1;

struct list_t
{
    int* data;
    int* next;
    int* prev;
    int head;
    int tail;
};

#endif
