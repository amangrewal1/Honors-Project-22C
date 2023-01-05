/*~*~*
   Stack template
*~*/

#ifndef STACK_H
#define STACK_H

using namespace std;

template <class T>
class Stack
{
private:
    // Structure for the stack nodes
    struct StackNode
    {
      T value;          // Value in the node
      StackNode *next;  // Pointer to next node
    };

    StackNode *top;     // Pointer to the stack top
    int length;

public:
    Stack(){ top = NULL; length = 0; }   // Constructor
    ~Stack();                            // Destructor

    // Stack operations:
    bool push(T);                     // push()
    T pop();                          // pop()
    int peek() {return top->value;}   // peek()
    bool isEmpty() { return length == 0;}                 // isEmpty()
    int getLength() {return length;}  // getLength()
};


/*~*~*
  Member function push inserts the argument onto
  the stack.
*~**/\
template <typename T>
bool Stack<T>::push(T item)
{
   StackNode *newNode; // Pointer to a new node

   // Allocate a new node and store num there.
   newNode = new StackNode;
   if (!newNode)
       return false;
   newNode->value = item;

   // Update links and counter
   newNode->next = top;
   top = newNode;
   length++;

   return true;
}




/*~*~*
  Member function pop deletes the value at the top
  of the stack and returns it.
  Assume stack is not empty.
*~**/
template <typename T>
T Stack<T>::pop()
{
   // Create a temporary node to store the value
   StackNode* temp = top;
   
   // Pop value and set top to next value
   top = top->next;
   
   // Decrement length
   length--;
   
   // Return value popped
   return temp->value;
}




/**~*~*
   Destructor
*~**/
template <typename T>
Stack<T>::~Stack()
{
   StackNode *currNode;
         cout << "Stack: ";

   // Position nodePtr at the top of the stack.
   currNode = top;

   // Traverse the list deleting each node.
   if (length == 0)
   {
      cout << "Empty";
   }
   else
   {
      while (currNode != NULL)
      {
         // Store current node in temporary node
         StackNode* temp = currNode;
         
         cout <<currNode->value << " ";
         
         // Traverse list
         currNode = currNode->next;
         
         // Release memory
         delete temp;
         temp = NULL;
      }
   }
   cout << endl;
}

#endif
