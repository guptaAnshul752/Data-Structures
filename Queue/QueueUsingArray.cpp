// Implementing Queue Using Array
// Perform Basic Queue Operations
// 1. Enqueue --> Inserting Element
// 2. Dequeue --> Removing Element
// 3. Front --> Top(First) Element in Queue

#include <iostream>

using namespace std;

template <typename T>

class QueueUsingArray{

    // Creating Array for storing elements
    T *data;

    // Maintains Index at which next operation should take place
    int nextIndex;
    // Maintains first Index
    int firstIndex;
    // Total Size of Queue
    int Size;
    // Total Elements in a Queue
    int capacity;

    public:

    // Creating Constructor for number of taking no. elements in array
    QueueUsingArray(int n){
        data = new T[n];
        nextIndex = 0;
        firstIndex = -1;
        Size = 0;
        capacity = n;
    }

    // Returning Size of Queue
    int getSize(){
    return Size;
    }

    // Checking if Queue is Empty
    bool IsEmpty(){
    return Size==0;
    }

    // Inserting
    void enqueue(T element){
        if (Size == capacity){
            cout << "Queue Full" <<endl;
            return;
        }
    data[nextIndex] = element;
    nextIndex = (nextIndex + 1) % capacity;
    if (firstIndex = -1){
        firstIndex = 0;
    }
    Size++;
    }

    // Returning the First element
    T front(){
        if(IsEmpty()){
            cout << "Stack is Empty!" <<endl;
            return 0;
        }
        return data[firstIndex];
    }

    // Deleting Elements
    T dequeue(){
        if(IsEmpty()){
            cout << "Stack is Empty!" <<endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        Size--;
        if (Size ==0){
            // Resetting values
            nextIndex = 0;
            firstIndex = -1;
        }
        return ans;
    }
};

int main()
{
    QueueUsingArray<int> s(5);
    s.enqueue(10);
    s.enqueue(20);
    s.enqueue(30);
    s.enqueue(40);
    s.enqueue(50);

    // Top element
    cout << "Top: " << s.front() <<endl;
    // Size of Queue
    cout << "Size: "<< s.getSize() <<endl;
    // Dequeue
    cout << "Element Deleted: " << s.dequeue() <<endl;
    cout << "Element Deleted: " << s.dequeue() <<endl;
    // Top element
    cout << "Top: " << s.front() <<endl;
    // Checks if queue is empty
    cout << "Is Queue Empty: " << s.IsEmpty() <<endl;
}
