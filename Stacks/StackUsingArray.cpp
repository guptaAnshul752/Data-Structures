// Implementing Stack Using Arrays
// LIFO --> LastInFirstOut
// Perform Basic stack operations
// 1. Push --> Addition of element
// 2. Pop --> Deletion of element
// 3. Size of Stack
// 4. Check whether Stack is Empty
// 5. Top Element of Stack

#include <iostream>
#include <climits>

using namespace std;

class StackUsingArray {

    // Array and other datamembers are declared private so to avoid its direct usage beyond the class.
    int *data;
    int capacity;
    int nextIndex;

    public:

        // Constructor initializing the stack size
        StackUsingArray(int TotalSize){
        data = new int[TotalSize];
        nextIndex = 0;
        capacity = TotalSize;
        }

        // Method to return Size of the Stack
        int Size(){
        return nextIndex;
        }

        // Method to check whether stack is empty or not
        bool isEmpty(){
        /*
        if (nextIndex==0)
            return true;
        else{
            return false;
        }
        */
        return nextIndex==0;
        }

        // Push function (Addition of element)
        void push(int element)
        {
            if(nextIndex==capacity){
                cout << "Stack is Full" << endl;
                return;
            }
            data[nextIndex] = element;
            nextIndex++;
        }
        // Pop function (Deletion of element)
        int pop(){
        if (isEmpty()){
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
        }

        // Top function(Returns top element of the stack)
        int top()
        {
            if (isEmpty()){
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
        }

    };

int main()
{
    StackUsingArray s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    // Overflow
    s.push(60);

    // Top element
    cout << s.top() <<endl;

    // Size of Stack
    cout << s.Size() <<endl;

    // Pop
    cout << s.pop() <<endl;
    cout << s.pop() <<endl;

    // Checks if stack is empty
    cout << s.isEmpty() <<endl;
}
