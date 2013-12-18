typedef struct {
    void** elements;
    int top;
    int length;
} Stack;

typedef char string[256];

Stack* create(int length);
int push(Stack* stack,void* element);
void* pop(Stack* stack);
void* top(Stack* stack);
void dispose(Stack* stack);

int isEmpty(Stack* stack);
void isFull(Stack* stack);