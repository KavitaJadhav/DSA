#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_must_insert_root_data");
	setup();
		test_must_insert_root_data();
	tearDown();
	testEnded();
	testStarted("test_must_insert_large_data_on_right_side_of_root");
	setup();
		test_must_insert_large_data_on_right_side_of_root();
	tearDown();
	testEnded();
	testStarted("test_must_insert_small_data_on_left_side_of_root");
	setup();
		test_must_insert_small_data_on_left_side_of_root();
	tearDown();
	testEnded();
	testStarted("test_must_not_search_element_if_not_present");
	setup();
		test_must_not_search_element_if_not_present();
	tearDown();
	testEnded();
	testStarted("test_must_insert_data_at_second_level_on_right_side");
	setup();
		test_must_insert_data_at_second_level_on_right_side();
	tearDown();
	testEnded();
	testStarted("test_must_insert_data_at_second_level_on_left_side");
	setup();
		test_must_insert_data_at_second_level_on_left_side();
	tearDown();
	testEnded();
	testStarted("test_must_delete_root_data");
	setup();
		test_must_delete_root_data();
	tearDown();
	testEnded();
	testStarted("test_shod_not_delete_data_that_not_exist");
	setup();
		test_shod_not_delete_data_that_not_exist();
	tearDown();
	testEnded();
	testStarted("test_deletion_of_left_leaf_node");
	setup();
		test_deletion_of_left_leaf_node();
	tearDown();
	testEnded();
	testStarted("test_deletion_of_right_leaf_node");
	setup();
		test_deletion_of_right_leaf_node();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
