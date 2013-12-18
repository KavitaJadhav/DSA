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

	testStarted("test_enqueue_char_element_at_rear_of_queue");
	setup();
		test_enqueue_char_element_at_rear_of_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_int_element_at_rear_of_queue");
	setup();
		test_enqueue_int_element_at_rear_of_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_float_element_at_rear_of_queue");
	setup();
		test_enqueue_float_element_at_rear_of_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_string_element_at_rear_of_queue");
	setup();
		test_enqueue_string_element_at_rear_of_queue();
	tearDown();
	testEnded();
	testStarted("test_dequeue_char_element_at_front_of_queue");
	setup();
		test_dequeue_char_element_at_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_33_dequeue_int_element_at_rear_of_queue");
	setup();
		test_33_dequeue_int_element_at_rear_of_queue();
	tearDown();
	testEnded();
	testStarted("test_3_dequeue_float_element_at_rear_of_queue");
	setup();
		test_3_dequeue_float_element_at_rear_of_queue();
	tearDown();
	testEnded();
	testStarted("test_3_dequeue_string_element_at_start_of_queue");
	setup();
		test_3_dequeue_string_element_at_start_of_queue();
	tearDown();
	testEnded();
	testStarted("test_isFull_return_true_if_queue_is_full");
	setup();
		test_isFull_return_true_if_queue_is_full();
	tearDown();
	testEnded();
	testStarted("test_isFull_return_false_if_queue_is_not_full");
	setup();
		test_isFull_return_false_if_queue_is_not_full();
	tearDown();
	testEnded();
	testStarted("test_isEmpty_return_true_if_queue_is_empty");
	setup();
		test_isEmpty_return_true_if_queue_is_empty();
	tearDown();
	testEnded();
	testStarted("test_isEmpty_return_false_if_queue_is_not_empty");
	setup();
		test_isEmpty_return_false_if_queue_is_not_empty();
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
