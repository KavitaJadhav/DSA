#include "testUtils.h"
#include "hashmap.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areKeyEqual(void* key1 , void* key2 ){
        return *(int*)key1 - *(int*)key2;
}
int hashFun(void *key){
        return *(int*)key;
};

void test_add_an_element_to_hashmap(){
	int key = 10;
	char* value ="kavita";
	HashMap* map = create(hashFun, areKeyEqual);
	ASSERT(put(map, &key , &value));
	ASSERT(searchData(map,&key));
}
void test_add1_an_element_to_hashmap(){
	int key1 = 10,key = 20;
	char* value ="poonam";
	HashMap* map = create(hashFun, areKeyEqual);
	ASSERT(put(map, &key1 , &value));
	ASSERT(put(map, &key , &value));
	ASSERT(searchData(map,&key1));
	ASSERT(searchData(map,&key));
}