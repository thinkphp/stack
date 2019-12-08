/**
 *  Stack Class Implemented as a Linked List.
 *  Each element in the list is a struct consisting of an element el, and a pointer to the next struct node in the list,
 *  The constructor Stack initialises top of the Stack to point to NULL.
 *  The operations of the Stack include:
 *      - Push(int X) which adds a new element to the top of the stack.
 *      - Pop() which removes the top element.
 *      - Top() which returns the top element.
 *      - isEmpty() tests to see if the stack is empty or not.
 *      - MakeEmpty)() deletes pops all the elements from the stack.
 *      - ~Stack() destructor calls MakeEmpty() to empty the Stack and free up memory;
 *   
 */
#include <iostream>
#define FIN "scarface.in"
#include <fstream>

using namespace std;

class Stack {

      public:

           //constructor
      	   //initialises top of the stack to point to NULL
      	   Stack() {

      	   	   top = NULL;
      	   }

      	   //destructor
      	   ~Stack() {

      	   	    MakeEmpty();
     	   }

     	   void Push(int x) {

                //pointer tmp points to the new SNode
                struct SNode *tmp = new struct SNode; 

                       tmp->el = x;//place x element in the el field of SNode

                       tmp->next = top; //make the next pointer of the new SNode point to where the Top points

                       top = tmp;  //top points to the new SNode                 
     	   }

     	   void Pop() {

     	   	           SNode *tmp = top;
     	   	                  top = top->next;
     	   	                  delete tmp;  
     	   }

     	   int Top() {

                 if(!isEmpty()) {

                   return top->el;

                 } else {

                 	cout<<"Empty Stack!";
                 }
     	   }

     	   int isEmpty() {

     	        return top == NULL;
     	   }

     	   void MakeEmpty() {

     	   	    while(!isEmpty()) 
     	   	    {
     	   	    	Pop();
     	   	    }
     	   }

      private:

      	  struct SNode {

                 int el;

                 struct SNode *next;
      	  };

      	  SNode *top;
};

void reverse_array(int *p, int count) {

	 Stack S;

	 for (int i = 0; i < count; ++i)
	 {
	 	S.Push(p[i]);
	 }

     for (int i = 0; i < count; ++i)
	 {
	 	*(p + i) = S.Top(); 

	 	S.Pop();
	 }
}

unsigned strlen(char *ptr) {

         char *tmp = ptr;

         while(*tmp != '\0') 

         tmp++;

         return tmp - ptr;
}

void reverse_string(char ptr[]) {

     unsigned len = strlen(ptr);

	 Stack S;

	 for(int i = 0; i < len; ++i) S.Push(ptr[i]);

	 for(int i = 0; i < len; ++i) *(ptr + i) = S.Top(), S.Pop();
}

int main() {

    int n, *p, i;

    char str[100] = "JavaScript";

    freopen(FIN, "r", stdin);

    cin>>n; 

    for(i = 0; i < n; ++i) cin>>p[i];
    	
  	for(i = 0; i < n; ++i) cout<<p[i]<<" ";  		

    cout<<endl;

    reverse_array(p, n); 

    for(i = 0; i < n; ++i) cout<<p[i]<<" ";

    cout<<endl;

    cout<<str<<endl;

    reverse_string(str); 

    cout<<str<<endl;

	return(0);
}
