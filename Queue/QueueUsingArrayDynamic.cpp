// Dynamic Queue Implementation
// No Size Constraint of Array

#include<iostream>

using namespace std;

template <typename T>
class QueueUsingArray{
    // Creating Array for storing elements
    T *data;
    int nextIndex;
    int firstIndex;
    int Size;
    int capacity;

    public:
    // Creating Constructor for number of taking no. elements in array
    QueueUsingArray(){
        int n;
        cout << "Enter the Size of Queue:";
        cin >> n;
        data = new T[n];
        nextIndex = 0;
        firstIndex = -1;
        Size = 0;
        capacity = n; //Custom
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
            T *newdata = new T[2 * capacity];
            int j=0;
            for (int i = firstIndex; i < capacity; i++){
                newdata[j] = data[i];
                j++;
            }
            for (int i = 0; i < firstIndex; i++){
                newdata[j] = data[i];
                j++;
            }
            delete []data;
            data = newdata;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
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
    QueueUsingArray<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Top element
    cout << "Top: " << q.front() <<endl;
    // Size of Queue
    cout << "Size: " << q.getSize() <<endl;
    // Dequeue
    cout << q.dequeue() <<endl;
    cout << q.dequeue() <<endl;
    // Top element
    cout << "Top: " << q.front() <<endl;
    // Checks if Queue is empty
    cout << "Is Queue Empty: " << q.IsEmpty() <<endl;
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(90);
    cout << "Updated Size of Queue is :" << q.getSize() <<endl;
}
