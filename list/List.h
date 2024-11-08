#ifndef LIST
#define LIST

#include <stdio.h>

#define DEBUG

static const char* DUMP       = "dump.txt";
static const char* DUMP_HTML  = "Dump.html";

const size_t LIST_SIZE    = 10;

const int INVALID_ADDR    = -1;
const int POISON          = -153;
const int ERROR_FREE_SEEL = 666;

struct list_t
{
    int   free;
    int   number_elements;
    int*  data;
    int*  next;
    int*  prev;

    #ifdef DEBUG
    FILE* dump;
    FILE* dump_html;
    #endif
};

void ListCtor           (struct list_t* list);
void ListDtor           (struct list_t* list);
void FillingArraysStart (struct list_t* list);
void ListPop            (struct list_t* list, int anchor);
void ListPush           (struct list_t* list, int elem, int anchor);

#endif
