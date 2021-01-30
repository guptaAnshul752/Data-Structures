// C++ Program to Delete any element from a particular Index in an Array 

#include <iostream>

using namespace std;

void Delete(int arr[],int idx,int size)
{

    for (int i=idx;i<size;i++)
    {
        arr[i] = arr[i+1];
    }
}

void display(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int idx,siz;
    cout<<"Enter the size of Array: ";
    cin>>siz;
    int Arr[siz];
    
    cout << "Enter the elements of the Array: ";
    for(int i=0;i<siz;i++)
    {
        cin>>Arr[i];
    }
    
    cout<<"Enter the index from which the element should be deleted: ";
    cin>>idx;
    
    Delete(Arr,idx,siz);
    cout<<"Element deleted successfully!"<<endl;
    cout<<"The elements of the Array are: ";
    display(Arr,siz);
}
