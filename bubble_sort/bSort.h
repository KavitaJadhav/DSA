
typedef int (*Compare)(void* first, void* second);

void bSort(void* base, int noOfElements, int elementSize, Compare compare); 