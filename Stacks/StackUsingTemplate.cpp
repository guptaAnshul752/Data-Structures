// Stack Implementation using Template

#include<iostream>

using namespace std;

template <typename T>

class StackUsingArray{
    T *data;
    int capacity;
    int nextIndex;

    public:
        // Constructor
        StackUsingArray(int totalSize){
        data = new T[totalSize];
        capacity = totalSize;
        nextIndex=0;
        }
        // IsEmptyMethod
        bool IsEmpty()
        {
            return nextIndex==0;
        }
        // Get Top element
        T top()
        {
            if (nextIndex==0){
                cout<<"Stack is Empty"<<endl;
            }
            return data[nextIndex-1];
        }
        // Size of Stack
        int Size()
        {
            return nextIndex;
        }
        // Push method
        void push(T element)
        {
            if (nextIndex==capacity){
                cout<<"Stack is Full";
                return;
            }
            data[nextIndex]=element;
            nextIndex++;
        }
        // Pop method
        T pop()
        {
            if (nextIndex==0){
                cout<<"Stack is Empty";
                return 0;
            }
            nextIndex--;
            return data[nextIndex];
        }
};

int main()
{
    StackUsingArray<char> s1(5);
    // Values would be treated according to ASCII values
    s1.push(100);
    s1.push(101);
    s1.push(102);
    s1.push(103);
    s1.push(104);
    s1.push(105);
    cout<<"\n";
    cout << "Size: " << s1.Size()<<endl;
    cout << "Top : " << s1.top()<<endl;

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;

    cout << "Size: " << s1.Size()<<endl;
    cout << s1.IsEmpty()<<endl;


}

