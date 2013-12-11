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

	testStarted("test_createList_function_call_assigns_header_to_null_and_length_to_zero");
	setup();
		test_createList_function_call_assigns_header_to_null_and_length_to_zero();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_int_data_at_starting_of_linked_list");
	setup();
		test_insert_node_with_int_data_at_starting_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_int_data_at_end_of_linked_list");
	setup();
		test_insert_node_with_int_data_at_end_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_float_data_at_end_of_linked_list");
	setup();
		test_insert_node_with_float_data_at_end_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_string_data_at_end_of_linked_list");
	setup();
		test_insert_node_with_string_data_at_end_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_char_data_at_end_of_linked_list");
	setup();
		test_insert_node_with_char_data_at_end_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_at_index_which_not_exist_return_false");
	setup();
		test_insert_node_at_index_which_not_exist_return_false();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_string_data_at_starting_of_linked_list");
	setup();
		test_insert_node_with_string_data_at_starting_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_Float_data_at_starting_of_linked_list");
	setup();
		test_insert_node_with_Float_data_at_starting_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_char_data_at_starting_of_linked_list");
	setup();
		test_insert_node_with_char_data_at_starting_of_linked_list();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
