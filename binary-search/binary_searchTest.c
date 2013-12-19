#include "testUtils.h"
#include "binary_search.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int compareInt (void* a, void* b){
    return (*(int*)a - *(int*)b);
}
int compareDouble (void* a, void* b){
    return (*(double*)a - *(double*)b);
}
int compareString(void *a, void *b){ 
         return (strcmp((char *)a,(char *)b));
}
int compareChar(void* a, void* b){
        return (*(char*)a - *(char*)b);
}
void test_search_element_from_the_character_array(){
    char elements[3] = {'a','b','c'};
    char key = 'b';
    char* result = search_generic(elements,&key, 3, sizeof(char), compareChar);
    ASSERT(&elements[1] == result);
};
void test_search_element_from_the_character_array_which_is_not_found(){
    char elements[3] = {'a','b','c'};
    char key = 'k';
    char* result = search_generic(elements,&key, 3, sizeof(char), compareChar);
    ASSERT(NULL == (char*)result);
};

void test_search_first_element_from_thecharacter_array_if_elements_are_same(){
    char elements[2] = {'a','a'};
    char key = 'a';
    char* result = search_generic(elements,&key, 2, sizeof(char), compareChar);
    ASSERT(&elements[0] == result);
};
void test_search_last_element_from_the_character_array_if_elements_are_same_with_diff_characters(){
    char elements[3] = {'a','a','b'};
    char key = 'a';
    char* result = search_generic(elements,&key, 3, sizeof(char), compareChar);
    ASSERT(&elements[1] == result);
};
void test_search_element_from_the_integer_array(){
    int elements[5] = {3,6,0,8,1};
    int key = 8;
    int* result = search_generic(elements,&key, 5, sizeof(int), compareInt);
    ASSERT(&elements[3] == result);
};
void test_search_element_from_the_integer_array_which_not_found(){
    int elements[5] = {1,2,3,4,5};
    int key = 9;
    int* result = search_generic(elements,&key, 5, sizeof(int), compareInt);
    ASSERT((int*)result == NULL);
};
void test_search_1st_element_from_the_integer_array(){
    int elements[5] = {4,9,3};
    int key = 4;
    int* result = search_generic(elements,&key, 2, sizeof(int), compareInt);
    ASSERT(&elements[0] == result);
};
void test_search_middle_element_from_the_integer_array(){
    int elements[5] = {5,5,7,8,2};
    int key = 7;
    int* result = search_generic(elements,&key, 5, sizeof(int), compareInt);
    ASSERT(&elements[2] == result);
};
void test_search_last_element_from_the_integer_array(){
    int elements[] = {1,2,3,4,5};
    int key = 5;
    int* result = search_generic(elements,&key, 5, sizeof(int), compareInt);
    ASSERT(&elements[4] == result);
};
void test_search_element_from_the_float_array(){
    float elements[5] = {1.5f,2.5f,3.5f,4.5f,5.5f};
    float key = 2.5f;
    float* result = search_generic(elements,&key, 5, sizeof(float), compareInt);
    ASSERT(&elements[1] == result);
};
void test_search_element_from_the_float_array_which_is_not_found(){
    float elements[5] = {4.7f,6.4f,7.3f,8.5f,2.2f};
    float key = 4.6f;
    float* result = search_generic(elements,&key, 5, sizeof(float), compareInt);
    ASSERT(NULL == (float*)result);
};
void test_search_element_from_the_double_array(){
    double elements[5] = {1.0,2.0,3.0,4.0,5.0};
    double key = 3.0;
    double* result = search_generic(elements,&key, 5, sizeof(double), compareDouble);
    ASSERT(&elements[2] == result);
};
void test_search_element_from_the_String_array(){
    String elements[3] = {"aaa","bbb","ccc"};
    String key = "aaa";
    String* result = search_generic(elements,&key, 3, sizeof(String), compareString);
    ASSERT(&elements[0] == result);
};
void test_search_element_from_the_String_array_which_is_not_found(){
    String elements[3] = {"aaa","bbb","ccc"};
    String key = "kkk";
    String* result = search_generic(elements,&key, 3, sizeof(String), compareString);
    ASSERT(NULL == (String*)result);
};
