// Queue Using Linked List Implementation
// Complexity of all methods --> O(1)

#include<iostream>

using namespace std;

template <typename T>

class Node{
    public:
    T data;
    Node<T> *next;

    // Constructor
    Node(T data){
    this -> data = data;
    next = NULL;
    }
};

template <typename T>

class QueueUsingLL{

    public:

    Node<T> *head;
    Node<T> *tail;
    int Size;

    public:

    // Calling Default Constructor
    QueueUsingLL(){
    head = NULL;
    tail = NULL;
    Size = 0;
    }

    // Get Size of Queue
    int getSize(){
        return Size;
    }

    // Is empty
    bool IsEmpty(){
        return Size ==0;
    }

    // Return First Element
    T Front(){
        if (head == NULL){
            cout << "Queue is Empty! " <<endl;
        }
        else {
            return head->data;
        }
    }

    // Inserting Element(Enqueue)
    void enqueue(T element){

    Node<T> *newNode = new Node<T>(element);

        if (head == NULL){
            head = newNode;
            tail = newNode;
        }
    tail -> next = newNode;
    tail = newNode;
    Size++;
    }

    // Deleting Element(Dequeue)
    T dequeue(){
        if (IsEmpty()) {
            cout << "Queue Is Empty!"<<endl;
            return 0;
        }
        T ans = head -> data;
        Node<T> *temp = head;
        head = head -> next;
        delete temp;
        Size--;
        return ans;
    }
};

int main()
{
    QueueUsingLL<int> s;
    s.enqueue(10);
    s.enqueue(20);
    s.enqueue(30);

    // First element
    cout << "Top: " << s.Front() <<endl;
    // Size of Queue
    cout << "Size: " << s.getSize() <<endl;
    // Dequeue
    cout << "Element Deleted: " << s.dequeue() <<endl;
    cout << "Element Deleted: " << s.dequeue() <<endl;
    cout << "Element Deleted: " << s.dequeue() <<endl;

    // Checks if Queue is empty
    cout << "Is Queue Empty: " << s.IsEmpty() <<endl;

    s.enqueue(40);
    s.enqueue(50);
    s.enqueue(60);
    s.enqueue(70);
    s.enqueue(80);
    s.enqueue(90);

    // Size of Stack
    cout << s.getSize() <<endl;
}
