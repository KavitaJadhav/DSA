#include <stdbool.h>
typedef char String[50];
typedef int compareFunction(void* element1 , void* element2);
void* search_generic(void* array,void* key,int length,int elementSize,compareFunction* compare);