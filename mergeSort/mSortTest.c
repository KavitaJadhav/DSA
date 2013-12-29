#include "testUtils.h"
#include "mSort.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef char String[256];
int compareInt (void* a,  void* b){
    return (*(int*)a < *(int*)b);
}


void test_sorting_integers_elements(){
    int i,length = 5;
    int elements[] = {40,50,30,20,10};
    int expected[] = {10,20,30,40,50};
    void* base[5] = {&elements[0],&elements[1],&elements[2],&elements[3],&elements[4]};
    msort(base,5,sizeof(int),compareInt);

    for(i=0;i<length;i++)
        ASSERT(expected[i] == *(char*)base[i]);
};
