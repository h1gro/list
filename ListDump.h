#ifndef LIST_DUMP
#define LIST_DUMP

void MySystem(const char* str, int number_dump);
void PrintGraphHead(FILE* graph);
void ListDump(struct list_t* list, int anchor, int line, const char* str);
void PrintArrayInFile(int* array, struct list_t* list);
void PrintListInfInFile(struct list_t* list, int anchor);
void PrintDefaultList(FILE* graph, struct list_t* list, int line, const char* str);
void PrintListChanges(FILE* graph, struct list_t* list);

#endif
