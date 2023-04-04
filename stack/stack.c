#include <stdio.h>
#define MAX 10

typedef struct Stack {

      int size;
      int data[MAX];

} Stack;

void init_stack(Stack *S) {

     S->size = 0;
}

void push( Stack *S,int data) {

     if(S->size < MAX) {
        S->data[S->size++] = data;
     } else {
       fprintf(stderr, "Stack overflow");
     }
}

int top(Stack *S) {
    if(S->size != 0) {
       return S->data[S->size-1];
    } else {
       fprintf(stderr, "Empty Stack");
       return -1;
    }
}

int pop( Stack *S ) {
     if(S->size) {
       S->size--;
     } else {
       fprintf(stderr, "%s\n", "Stack Underflow");
       return -1;
     }
}

int main(int argc, char const *argv[]) {
  Stack S;

  init_stack(&S);
  push(&S, 7);//stack[0] = 7 & size = 1
  push(&S, 8);//stack[1] = 8 & size = 2
  push(&S, 9);//stack[2] = 9 & size = 3
  push(&S, 19);//stack[3] = 19 & size = 4
  push(&S, 29);//stack[4] = 29 & size = 5
  printf("%d\n", top(&S));
  pop(&S);
  pop(&S);
  pop(&S);
  pop(&S);
  printf("%d\n", top(&S));
  printf("%d\n", top(&S));
  pop(&S);
   printf("%d\n", top(&S));
  return 0;
  
}
