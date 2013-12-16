#include "testUtils.h"
#include "isort.h"
#include <stdio.h>
#include <memory.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


typedef struct {
        int accNumber;
        int balance;
}Account;

int areAccountsEqual(Account* expected,Account* actual){
    int result = expected->accNumber == actual->accNumber && expected->balance == actual->balance;
    return result;
}
int compareAccountsByAccountNumber(void* first, void* second) {
	Account* account1 = (Account*)first;
	Account* account2 = (Account*)second;
	return account1->accNumber - account2->accNumber;
}
int compareAccountsByBalance(void* first, void* second) {
	Account* account1 = (Account*)first;
	Account* account2 = (Account*)second;
	return account1->balance - account2->balance;
}
int compareInt ( void* a,  void* b){
    return (*(int*)a - *(int*)b);
}
int compareDouble( void* a,  void* b){
    return (*(double*)a - *(double*)b);
}
int compareFloat( void* a,  void* b){
    return (*(float*)a - *(float*)b);
}
int compareChar( void* a,  void* b){
    return (*(char*)a - *(char*)b);
}
int compareString(void* key,void* element){
    return strcmp( *(String*)key, *(String*)element );
}
void test_1_sorting_an_array_of_integers(){
    int expected[] = {1,2,3,4};
    int data[] = {4,3,1,2};
    isort(data, 4, sizeof(int), compareInt);
    ASSERT(0 == memcmp(expected, data, sizeof(expected)));
}
void test_1_sorting_an_array_of_integers2(){
    int expected[] = {1,1,3,4};
    int data[] = {3,1,4,1};
    isort(data, 4, sizeof(int), compareInt);
    ASSERT(0 == memcmp(expected, data, sizeof(expected)));
}
void test_2_sorting_an_array_of_double(){
    double expected[] = {1.000000,2.000000,3.000000,4.000000};
    double data[] = {4.000000,3.000000,1.000000,2.000000};
    isort(data, 4, sizeof(double), compareDouble);
    ASSERT(0 == memcmp(expected, data, sizeof(expected)));
}
void test_3_sorting_an_array_of_float(){
    float expected[] = {1.0,2.0,3.0,4.0};
    float data[] = {4.0,3.0,1.0,2.0};
    isort(data, 4, sizeof(float), compareFloat);
    ASSERT(0 == memcmp(expected, data, sizeof(expected)));
}
void test_4_sorting_an_array_of_character(){
    char expected[] = {'a','b','c','d'};
    char data[] = {'a','d','c','b'};
    isort(data, 4, sizeof(char), compareChar);
    ASSERT(0 == memcmp(expected, data, sizeof(expected)));
}
void test_5_sorting_an_array_of_string(){
    String expected[] = {"aaa","bbb","ccc","ddd"};
    String data[] = {"ddd","ccc","aaa","bbb"};
    isort(data, 4, sizeof(String), compareString);
    ASSERT(0 == memcmp(expected, data, sizeof(expected)));
}
void test_account_by_balance(){
    Account accounts[] = {{1,500},{2,200}};
	Account expected[] = {{2,200},{1,500}};
    isort(accounts, 4, sizeof(Account), compareAccountsByBalance);
    ASSERT(0 == memcmp(expected, accounts, sizeof(expected)));
}
void test_account_by_account_number(){
    Account accounts[] = {{4,800},{1,500},{2,200}};
    Account expected[] = {{1,500},{2,200},{4,800}};
    isort(accounts, 4, sizeof(Account), compareAccountsByAccountNumber);
    ASSERT(0 == memcmp(expected, accounts, sizeof(expected)));
}