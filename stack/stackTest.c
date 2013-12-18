#include "stack.h"
#include <memory.h>
#include <stdlib.h>
#include "testUtils.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_pop_thee_element_of_the_empty_stack_return_false(){
    Stack* stack = create(1);
    ASSERT(! pop(stack));
};
void test_pushes_the_element_at_the_top_of_the_stack_for_integers(){
    int num = 400;
    Stack* stack = create(1);
    push(stack, &num);
    ASSERT(&num == pop(stack));
};
void test_push_string_element_at_top_of_stack(){
    string element = "AAA";
    Stack* stack = create(2);
    push(stack , &element);
    ASSERT(!strcmp("AAA" , *(string*)pop(stack)));
}
void test_push_integer_elements_at_the_top_of_the_stack(){
    int data[] = {400,500,600};
    Stack* stack = create(2);
    push(stack, &data[0]);
    push(stack, &data[1]);
    push(stack, &data[2]);
   	ASSERT(&data[2] == pop(stack));
    ASSERT(&data[1] == pop(stack));
    ASSERT(&data[0] == pop(stack));
};
void test_push_char_element_at_top_of_stack1(){
    int elements[] = {'A','B','C','D','E'};
    Stack* stack = create(5);

    push(stack , &elements[0]);
    push(stack , &elements[1]);
    push(stack , &elements[2]);

    ASSERT(&elements[2] == pop(stack));    
    ASSERT(&elements[1] == pop(stack));    
    ASSERT(&elements[0] == pop(stack));    
}
void test_push_float_element_at_top_of_stack1(){
    float elements[] = {10.5f,20.5f,30.5f,40.5f,50.5f};
    Stack* stack = create(5);

    push(stack , &elements[0]);
    push(stack , &elements[1]);
    push(stack , &elements[2]);

    ASSERT(&elements[2] == pop(stack));    
    ASSERT(&elements[1] == pop(stack));    
    ASSERT(&elements[0] == pop(stack));    
}
void test_push_double_memory_when_stack_is_full(){
    int data[] = {400,500,600};
    Stack* stack = create(2);
    push(stack, &data[0]);
    push(stack, &data[1]);
    ASSERT(&data[1] == pop(stack));
    ASSERT(&data[0] == pop(stack));
};
void test_top_ggives_top_element_of_stack1(){
    int elements[] = {10,20,30,40,50};
    Stack* stack = create(5);

    push(stack , &elements[0]);
    push(stack , &elements[1]);
    push(stack , &elements[2]);

    ASSERT(&elements[2] == top(stack));     
}