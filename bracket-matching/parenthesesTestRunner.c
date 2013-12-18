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

	testStarted("test_1");
	setup();
		test_1();
	tearDown();
	testEnded();
	testStarted("test_2");
	setup();
		test_2();
	tearDown();
	testEnded();
	testStarted("test_3");
	setup();
		test_3();
	tearDown();
	testEnded();
	testStarted("test_4");
	setup();
		test_4();
	tearDown();
	testEnded();
	testStarted("test_5");
	setup();
		test_5();
	tearDown();
	testEnded();
	testStarted("test_6");
	setup();
		test_6();
	tearDown();
	testEnded();
	testStarted("test_7");
	setup();
		test_7();
	tearDown();
	testEnded();
	testStarted("test_8");
	setup();
		test_8();
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
