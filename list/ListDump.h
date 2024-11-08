#ifndef LIST_DUMP
#define LIST_DUMP

void MySystem           (const char* str, int number_dump);

void PrintArrayInFile   (struct list_t* list, int* array);
void PrintListInfInFile (struct list_t* list, int anchor, const char* func);
void LinearDump         (struct list_t* list, int anchor, const char* func);
void ListDump           (struct list_t* list, int anchor, const char* func, int line, const char* str);
void GraphDump          (struct list_t* list, int anchor, const char* func, int line, const char* str);

void PrintGraphHead     (FILE* graph);
void PrintListChanges   (FILE* graph, struct list_t* list);
void PrintDefaultList   (FILE* graph, struct list_t* list, int anchor, int line, const char* func, const char* str);

#endif
