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

	testStarted("test_create_queue");
	setup();
		test_create_queue();
	tearDown();
	testEnded();
	testStarted("test_insert_integer_data_in_Start_of_queue");
	setup();
		test_insert_integer_data_in_Start_of_queue();
	tearDown();
	testEnded();
	testStarted("test_insert_integer_data_in_queue1");
	setup();
		test_insert_integer_data_in_queue1();
	tearDown();
	testEnded();
	testStarted("test_insert_float_data_in_queue1");
	setup();
		test_insert_float_data_in_queue1();
	tearDown();
	testEnded();
	testStarted("test_insert_string_data_in_queue1");
	setup();
		test_insert_string_data_in_queue1();
	tearDown();
	testEnded();
	testStarted("test_delete_integer_data_in_queue1");
	setup();
		test_delete_integer_data_in_queue1();
	tearDown();
	testEnded();
	testStarted("test_delete_float_data_in_queue1");
	setup();
		test_delete_float_data_in_queue1();
	tearDown();
	testEnded();
	testStarted("test_delete_string_data_in_queue");
	setup();
		test_delete_string_data_in_queue();
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
