// Dynamic Stack Implementation
// Getting Rid of Size Constraint

#include<iostream>

using namespace std;

class StackUsingArray{
    int *data;
    int capacity;
    int nextIndex;

    public:
        // Constructor
        StackUsingArray(){
        data = new int[5];
        capacity = 5; // Custom
        nextIndex=0;
        }

        // IsEmptyMethod
        bool IsEmpty()
        {
            return nextIndex==0;
        }

        // Get Top element
        int top()
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
        void push(int element)
        {
            if (nextIndex==capacity){
                int *newData = new int[2*capacity];
                    for(int i=0; i < capacity; i++)
                    {
                    newData[i] = data[i];
                    }
                delete []data;
                data = newData;
            }
            data[nextIndex]=element;
            nextIndex++;
        }
        // Pop method
        int pop()
        {
            if (nextIndex==0){
                cout<<"Stack is Empty";
                return INT_MIN;
            }
            nextIndex--;
            return data[nextIndex];
        }
};

int main()
{
    StackUsingArray s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    cout << "Size: " << s1.Size()<<endl;
    cout << "Top Element: " << s1.top()<<endl;

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;

    cout << "Size: " << s1.Size()<<endl;
    cout << "Is Stack Empty: " << s1.IsEmpty()<<endl;


}

