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

	testStarted("test_search_element_from_the_character_array");
	setup();
		test_search_element_from_the_character_array();
	tearDown();
	testEnded();
	testStarted("test_search_element_from_the_character_array_which_is_not_found");
	setup();
		test_search_element_from_the_character_array_which_is_not_found();
	tearDown();
	testEnded();
	testStarted("test_search_first_element_from_thecharacter_array_if_elements_are_same");
	setup();
		test_search_first_element_from_thecharacter_array_if_elements_are_same();
	tearDown();
	testEnded();
	testStarted("test_search_last_element_from_the_character_array_if_elements_are_same_with_diff_characters");
	setup();
		test_search_last_element_from_the_character_array_if_elements_are_same_with_diff_characters();
	tearDown();
	testEnded();
	testStarted("test_search_element_from_the_integer_array");
	setup();
		test_search_element_from_the_integer_array();
	tearDown();
	testEnded();
	testStarted("test_search_element_from_the_integer_array_which_not_found");
	setup();
		test_search_element_from_the_integer_array_which_not_found();
	tearDown();
	testEnded();
	testStarted("test_search_1st_element_from_the_integer_array");
	setup();
		test_search_1st_element_from_the_integer_array();
	tearDown();
	testEnded();
	testStarted("test_search_middle_element_from_the_integer_array");
	setup();
		test_search_middle_element_from_the_integer_array();
	tearDown();
	testEnded();
	testStarted("test_search_last_element_from_the_integer_array");
	setup();
		test_search_last_element_from_the_integer_array();
	tearDown();
	testEnded();
	testStarted("test_search_element_from_the_float_array");
	setup();
		test_search_element_from_the_float_array();
	tearDown();
	testEnded();
	testStarted("test_search_element_from_the_float_array_which_is_not_found");
	setup();
		test_search_element_from_the_float_array_which_is_not_found();
	tearDown();
	testEnded();
	testStarted("test_search_element_from_the_double_array");
	setup();
		test_search_element_from_the_double_array();
	tearDown();
	testEnded();
	testStarted("test_search_element_from_the_String_array");
	setup();
		test_search_element_from_the_String_array();
	tearDown();
	testEnded();
	testStarted("test_search_element_from_the_String_array_which_is_not_found");
	setup();
		test_search_element_from_the_String_array_which_is_not_found();
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
