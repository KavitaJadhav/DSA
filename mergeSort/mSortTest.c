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
int compareDouble( void* a,  void* b){
    return (*(double*)a < *(double*)b);
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
void test_sorting_float_elements(){
    float elements[] = {10.5f,1.5f,2.5f,7.5f};
    float expected[] = {1.5f,2.5f,7.5f,10.5f};
    int i;
    void *base[4] = {&elements[0],&elements[1],&elements[2],&elements[3]};
    msort(base,4,sizeof(float),compareInt);
    
    for(i=0;i<4;i++)
        ASSERT(expected[i] == *(float*)base[i]);
};

void test_sorting_double_elements(){
    double elements[] = {10.5050505050,1.5050505050,2.5050505050,7.5050505050};
    double expected[] = {1.5050505050,2.5050505050,7.5050505050,10.5050505050};
    int i;
    void *base[4] = {&elements[0],&elements[1],&elements[2],&elements[3]};
    msort(base,4,sizeof(double),compareDouble);
    
    for(i=0;i<4;i++)
        ASSERT(expected[i] == *(double*)base[i]);        
};
