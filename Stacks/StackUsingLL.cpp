// Implementing Stack using Linked List and Templates

#include<iostream>

using namespace std;

template <typename T>

// Node Class
class Node {
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

class StackUsingLL{

    public:

    Node<T> *head;
    int Size; // No. of elements in Stack

    public :
        // Constructor
        StackUsingLL(){
        head = NULL;
        Size = 0;
        }

        // getSize of Stack
        int getSize(){
        return Size;
        }

        // IsEmpty method
        bool IsEmpty(){
        return Size == 0;
        }

        // Push
        void push(T element){
        Node<T> *newNode = new Node<T>(element);
        newNode -> next = head;
        head = newNode;
        Size++;
        }

        // Pop
        T pop(){
        if (IsEmpty()) {
            return 0;
        }
        T ans = head -> data;
        Node<T> *temp = head;
        head = head -> next;
        delete temp;
        Size--;
        return ans;
        }

        // Top element
        T top(){
        if (IsEmpty()) {
            return 0;
        }
        return head->data;
        }
};

int main()
{
    StackUsingLL<char> s1;
    // Char are taken in accordance to their ASCII values
    s1.push(100);
    s1.push(101);
    s1.push(102);
    s1.push(103);
    s1.push(104);
    s1.push(105);
    cout << "Size: " << s1.getSize()<<endl;
    cout << "Top Element: " << s1.top()<<endl;

    cout << "Popped Element : "<< s1.pop() << endl;
    cout << "Popped Element : "<< s1.pop() << endl;
    cout << "Popped Element : "<< s1.pop() << endl;

    cout << "Size: " << s1.getSize()<<endl;
    cout << "Is Stack Empty: " << s1.IsEmpty() << endl;
}
