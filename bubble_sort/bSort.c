#include "bSort.h"
#include <stdlib.h>
#include <string.h>

void swapElement(void* element1 ,void* element2 ,int elementSize ,Compare compare){
    void* temp = calloc(1, elementSize);
	if(0 < compare(element1,element2)){
		memcpy(temp , element2 , elementSize);
		memcpy(element2, element1, elementSize);
		memcpy(element1, temp, elementSize);
	}
}
void bSort(void* base, int noOfElements, int elementSize, Compare compare){
    int i, j;
    void *element1 , *element2;
    for (i = 0; i < noOfElements; i++) {
		element1 = base + i * elementSize;
		for (j = i+1; j < noOfElements; j++) {
			element2= base + j * elementSize;
			swapElement(element1 , element2 ,elementSize,compare);
		}
	}
};