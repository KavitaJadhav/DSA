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

	testStarted("test_insert_data_at_index_which_not_exist_return_false");
	setup();
		test_insert_data_at_index_which_not_exist_return_false();
	tearDown();
	testEnded();
	testStarted("test_insert_int_data_at_starting_of_linked_list");
	setup();
		test_insert_int_data_at_starting_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_getElement_give_element_at_index");
	setup();
		test_getElement_give_element_at_index();
	tearDown();
	testEnded();
	testStarted("test_insert_char_data_at_starting_of_linked_list");
	setup();
		test_insert_char_data_at_starting_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_string_data_at_starting_of_linked_list");
	setup();
		test_insert_string_data_at_starting_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_float_data_at_starting_of_linked_list");
	setup();
		test_insert_float_data_at_starting_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_int_data_in_linked_list");
	setup();
		test_insert_node_with_int_data_in_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_float_data_in_linked_list");
	setup();
		test_insert_node_with_float_data_in_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_string_data_in_linked_list");
	setup();
		test_insert_node_with_string_data_in_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_string_data_in_middle_of_linked_list");
	setup();
		test_insert_node_with_string_data_in_middle_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_node_with_integer_data_in_middle_of_linked_list");
	setup();
		test_insert_node_with_integer_data_in_middle_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_delete_data_at_index_that_not_exist");
	setup();
		test_delete_data_at_index_that_not_exist();
	tearDown();
	testEnded();
	testStarted("test_delete_data_at_given_index");
	setup();
		test_delete_data_at_given_index();
	tearDown();
	testEnded();
	testStarted("test_search_data_in_given_list_return_index");
	setup();
		test_search_data_in_given_list_return_index();
	tearDown();
	testEnded();
	testStarted("test_search_data_in_empty_list_return_minus_one");
	setup();
		test_search_data_in_empty_list_return_minus_one();
	tearDown();
	testEnded();
	testStarted("test_search_gives_minus_one_if_data_not_found");
	setup();
		test_search_gives_minus_one_if_data_not_found();
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
