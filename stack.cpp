/*
 *  Stack Class Implemented as an Array.
 */
#include <iostream>
#include <fstream>
#define STACK_MAX 100
#define FIN "scarface.in"

using namespace std;

class Stack {

	  private:
	  	      int size;
	  	      
	  	      int data[STACK_MAX];

	  public:
	  	     Stack() { //constructor
                  
                  size = 0;
	  	     } 

	  	     ~Stack() { //destructor

	  	     }

	  	     void Push(int v) {

                  if(size < STACK_MAX) {

                     data[size++] = v;             

                  } else {

                  	fprintf(stderr, "%s\n", "Error: Stack Overflow!");
                  }
	  	     }

	  	     void Pop() {

                  if(size == 0) {

                  	 fprintf(stderr, "%s\n", "Error: Stack Underflow!");

                  } else size--;
	  	     }

	  	     int Top() {

                   if(size == 0) {

                          fprintf(stderr, "%s\n", "Error: Stack is Empty!");

                   } else return data[size - 1];

	  	     }

};

void reverse(int *p, int n) {

	Stack S;

    for (int i = 0; i < n; ++i)
	{
		 S.Push(p[i]);
	}
	
	for (int i = 0; i < n; ++i)
	{
		 p[i] = S.Top();

		 S.Pop();
	}
}

int main(int argc, char const *argv[])
{

    int n, *p, i;    

	freopen(FIN, "r", stdin);

	cin>>n;

	for (int i = 0; i < n; ++i)
	{
		cin>>p[i];
	}
	
    for (int i = 0; i < n; ++i) printf("%d ", p[i]);

    reverse(p, n); 

    printf("\n");
	
	for (int i = 0; i < n; ++i) printf("%d ", p[i]);
	
	return 0;
}
