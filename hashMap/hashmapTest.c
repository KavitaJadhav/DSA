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
int hashFun(void *key , int capacity){
        return *(int*)key % capacity;
};

void test_add_an_element_to_hashmap(){
	int key = 16;
	char* value ="kavita";
	HashMap* map = create(hashFun, areKeyEqual);
	ASSERT(put(map, &key , &value));
	ASSERT(searchByKey(map,&key));
}
void test_add_an_element_to_hashmap1(){
	string key="intern" , value ="kavita";
	HashMap* map = create(hashFun, areKeyEqual1);
	ASSERT(put(map, &key , &value));
	ASSERT(searchByKey(map,&key));
}
void test_add_an_element_to_hashmap2(){
	int key1 = 13,key = 23;
	char* value ="poonam";
	HashMap* map = create(hashFun, areKeyEqual);
	ASSERT(put(map, &key1 , &value));
	ASSERT(put(map, &key , &value));
	ASSERT(searchByKey(map,&key1));
	ASSERT(searchByKey(map,&key));
} 
void test_get_an_element_to_hashmap(){
	HashElement* hashElement;
	string key="intern" , value ="kavita";
	HashMap* map = create(hashFun, areKeyEqual1);
	ASSERT(put(map, &key , &value));
	hashElement = get(map, &key);
	ASSERT(&key == hashElement->key);
	ASSERT(&value == hashElement->value);
}
void test_remove_an_element_from_hashmap(){
	string key="intern" , value ="kavita";
	HashMap* map = create(hashFun, areKeyEqual1);
	ASSERT(put(map, &key , &value));
	ASSERT(remove(map, &key));
	ASSERT(-1 == searchByKey(map,&key));
	ASSERT(NULL == get(map , & key));
}
void test_get_keys_in_hashmap(){
	Iterator it;
	int i = 0 ,key[] = {10 ,11,12,13,14,15,16, 17, 18, 19};
	char* values[] ={"AAA","BBB","CCC","DDD","EEE","FFF","HHH" , "III", "JJJ", "KKK"};
	HashMap* map = create(hashFun, areKeyEqual);

	for(i = 0 ; i < 10 ;i++ )
		ASSERT(put(map, &key[i] , &values[i]));

	it = keys(map);
	i = 0;
	while(it.hasNext(&it)){
		ASSERT(& key[i] == it.next(&it));
		i++;
	}
}
void test_rehash_keys_in_hashmap_in_insert(){
	Iterator it;
	int i = 0 ,key[] = {10 ,20,30,40};
	char* values[] ={"AAA","BBB","CCC","DDD"};
	int afterRehashing[] ={20,10,30,40};
	HashMap* map = create(hashFun, areKeyEqual);

	for(i = 0 ; i < 4 ;i++ )
		ASSERT(put(map, &key[i] , &values[i]));

	it = keys(map);
	i = 0;
	while(it.hasNext(&it)){
		ASSERT(afterRehashing[i] == *(int*)it.next(&it)); // assering for value not for address
		i++;
	}
}