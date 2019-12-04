#include <stdio.h>
#define STACK_MAX 100
#define FIN "scarface.in"

struct Stack {

	int size;
	char data[ STACK_MAX ];
};

typedef struct Stack Stack;

void Stack_Init(Stack *S) {

     S->size = 0; 
}

void Stack_Push(Stack *S, int val) {

     if( S->size < STACK_MAX ) {

         S->data[S->size++] = val; 
        
     } else fprintf(stderr, "Err: Stack Full!\n");

}

void Stack_Pop(Stack *S) {

     if( S->size == 0 ) fprintf(stderr, "Error: Stack Empty!");

         else S->size--;        
}

int Stack_Top(Stack *S) {

	if(S->size == 0) {
 
       fprintf(stderr, "Error: Stack Empty!");
       return -1;
	}

    return S->data[ S->size - 1]; 
}

int main(int argc, char const *argv[])
{
    int i;

	char *arr = "Likelihood";

	int n = sizeof(arr)/sizeof(arr[0]);

    for(i = 0; i < n; ++i) printf("%c", arr[i]);

    printf("\n");

    Stack S;
    
    Stack_Init(&S);

    for(i = 0; i < n; ++i) Stack_Push(&S, arr[i]);

    for(i = 0; i < n; ++i) printf("%c", Stack_Top(&S)), Stack_Pop(&S);    
	
	return 0;
}

