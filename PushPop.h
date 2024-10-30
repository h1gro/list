#ifndef PUSH_POP
#define PUSH_POP

const int ERROR_FREE_SEEL = 666;

int FindFreeSeel(struct list_t* list);
void ListPush(struct list_t* list, int elem, int anchor);
void ListPop(struct list_t* list);
void NextIndexSwap(struct list_t* list, int anchor);

#endif
