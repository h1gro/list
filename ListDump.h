#ifndef LIST_DUMP
#define LIST_DUMP

void PrintGraphHead(FILE* graph);
void ListDump(struct list_t* list);
void PrintArrayInFile(int* array, struct list_t* list);
void PrintListInfInFile(struct list_t* list);
void PrintDefaultList(FILE* graph, struct list_t* list);
void PrintListChanges(FILE* graph, struct list_t* list);
#endif
