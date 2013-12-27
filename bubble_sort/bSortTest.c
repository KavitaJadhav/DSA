#include "testUtils.h"
#include "bSort.h"
#include <string.h>
#include <stdlib.h>

typedef char String[50];

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareChar( void* a,  void* b){
    return (*(char*)a - *(char*)b);
}
int compareIntegers ( void* a,  void* b){
    return (*(int*)a - *(int*)b);
}
int compareFloat( void* a,  void* b){
    return (*(float*)a - *(float*)b);
}
int compareDouble( void* a,  void* b){
    return (*(double*)a - *(double*)b);
}
int compareString(void* a,void* b){
    return (strcmp(*(String*)a,*(String*)b));
}

void test_sort_Int_array(){
    int data[] = {40,30,10,20,50};
    int expected[] = {10,20,30,40,50};
    bSort(data, 4, sizeof(int), compareIntegers);
    ASSERT(0 == memcmp(expected, data, sizeof(expected)));
}

void test_sort_float_array(){
    float data[] = {10.5f,50.5f,30.5f,60.5f};
    float expected[] = {10.5f,30.5f,50.5f,60.5f};
    bSort(data, 4, sizeof(float), compareFloat);
    ASSERT(0 == memcmp(expected, data, sizeof(expected)));
}
void test_sort_char_array(){
    char data[] = {'D','B','A','C'};
    char expected[] = {'A','B','C','D'};
    bSort(data, 4, sizeof(char), compareChar);
    ASSERT(0 == memcmp(expected, data, sizeof(expected)));
}
void test_sort_string_array(){
    String data[] = {"DDDD","BBBB","AAAA","CCCC"};
    String expected[] = {"AAAA","BBBB","CCCC","DDDD"};
    bSort(data, 4, sizeof(String), compareString);
    ASSERT(0 == memcmp(expected, data, sizeof(expected)));
}
void test_sort_double_array(){
    double data[] = {10.55555555,50.55555555,30.55555555,60.55555555};
    double expected[] = {10.55555555,30.55555555,50.55555555,60.55555555};
    bSort(data, 4, sizeof(double), compareDouble);
    ASSERT(0 == memcmp(expected, data, sizeof(expected)));
}