/* C++ Program to Insert element at a particular Index in an Array. */

#include <iostream>

using namespace std;

void Insert(int arr[],int idx,int k,int size)
{

    for (int i=size;i>idx;i--)
    {
        arr[i] = arr[i-1];
    }
    arr[idx]=k;
}

void display(int arr[],int size)
{
    for(int i=0;i<size+1;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int idx,k,siz;
    cout<<"Enter the size of Array: ";
    cin>>siz;
    int Arr[siz];
    
    cout << "Enter the elements of the Array: ";
    for(int i=0;i<siz;i++)
    {
        cin>>Arr[i];
    }

    cout<<"Enter the element you want to insert: ";
    cin>>k;
    cout<<"Enter the Index at which element should be Inserted: ";
    cin>>idx;
    
    Insert(Arr,idx,k,siz);
    
    cout<<"Element appended successfully!"<<endl;
    cout<<"The elements of the Array are: ";
    display(Arr,siz);
}
