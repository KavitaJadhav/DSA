#include "testUtils.h"
#include "parentheses.h"

void test_fail(){
	char* data="On {John McPhee's( Oranges):This[must be the {most [entertaining] }industrial ]report {in English.}}";
	ASSERT(0);
}
