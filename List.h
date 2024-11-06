#ifndef LIST
#define LIST

#include <stdio.h>

static const char* DUMP       = "dump.txt";
static const char* DUMP_HTML  = "Dump.html";

const size_t LIST_SIZE    = 10;
const int INVALID_ADDR    = -1;
const int POISON          = -153;

struct list_t
{
    FILE*       dump;
    FILE*       dump_html;
    int*        data;
    int*        next;
    int*        prev;
    int         free;
    int         anchor;
    const char* func_call;
};

void ListCtor(struct list_t* list);
void ListDtor(struct list_t* list);
void FillingNextPrevPoison(struct list_t* list);
void ListChecks(struct list_t* list);

#endif
