#include "stack.h"
#include <memory.h>
#include <stdlib.h>
#include "testUtils.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areEqual(Stack a, Stack b){
    int result = a.length == b.length && a.top == b.top;
    if(!result) return result;
    return 0 == memcmp(a.elements,b.elements,a.length*sizeof(void*));
}
void test_creates_a_stack_for_with_given_length (){
    Stack* stack = create(3);
    void* array[3] = {NULL,NULL,NULL};
    Stack expected = {array,-1,3};
    ASSERT(areEqual(expected, *stack));
    dispose(stack);
}
void test_pushes_the_element_at_the_top_of_the_stack_for_integers(){
    int num = 400;
    Stack* stack = create(1);
    push(stack, &num);
    ASSERT(400 == **(int**)stack->elements);
    ASSERT(0 == stack->top && 1 == stack->length);
    dispose(stack);
};

void test_push_integer_elements_at_the_top_of_the_stack(){
    int num1 = 400 , num2 = 500 , num3 = 600;
    Stack* stack = create(2);
    push(stack, &num1);
    push(stack, &num2);
    push(stack, &num3);
   	ASSERT(&num3==pop(stack));
   	ASSERT(&num2==pop(stack));
   	ASSERT(&num1==pop(stack));
    dispose(stack);
};
