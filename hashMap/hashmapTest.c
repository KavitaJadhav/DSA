#include "testUtils.h"
#include "hashmap.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areKeyEqual(void* key1 , void* key2 ){
	return *(int*)key1 - *(int*)key2;
}
int areKeyEqual1(void* key1 , void* key2 ){
	return *(string*)key1 - *(string*)key2;
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
void test_add_an_element_to_hashmap1(){
	string key="intern" , value ="kavita";
	HashMap* map = create(hashFun, areKeyEqual1);
	ASSERT(put(map, &key , &value));
	ASSERT(searchData(map,&key));
}
void test_add_an_element_to_hashmap2(){
	int key1 = 10,key = 20;
	char* value ="poonam";
	HashMap* map = create(hashFun, areKeyEqual);
	ASSERT(put(map, &key1 , &value));
	ASSERT(put(map, &key , &value));
	ASSERT(searchData(map,&key1));
	ASSERT(searchData(map,&key));
}
void test_get_an_element_to_hashmap(){
	Data* data;
	string key="intern" , value ="kavita";
	HashMap* map = create(hashFun, areKeyEqual1);
	ASSERT(put(map, &key , &value));
	data = get(map, &key);
	ASSERT(&key == data->key);
	ASSERT(&value == data->value);
}
void test_remove_an_element_from_hashmap(){
	string key="intern" , value ="kavita";
	HashMap* map = create(hashFun, areKeyEqual1);
	ASSERT(put(map, &key , &value));
	ASSERT(remove(map, &key));
	ASSERT(-1 == searchData(map,&key));
	ASSERT(NULL == get(map , & key));
}