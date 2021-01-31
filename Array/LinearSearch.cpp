/* C++ Program to perform Linear Searching of an element in an array */
/* Methods to improve linear search
   1. Transposition --> Swapping element found to its previous index. if index=4,element shifted to 3
   2. Move to Front/Head -->Swapping element found to the first position/index. */

#include <iostream>

using namespace std;

int linear(int arr[],int k,int size)
{

    for (int i=0;i<size;i++)
    {
        if(k==arr[i])
           return i;
    }
    return -1;
}

int main()
{
    int k,siz;
    cout<<"Enter the size of Array: ";
    cin>>siz;
    int Arr[siz];
    cout << "Enter the elements of the Array: ";
    for(int i=0;i<siz;i++)
    {
        cin>>Arr[i];
    }

    cout<<"Enter the element you want to search: ";
    cin>>k;
    int ans = linear(Arr,k,siz);
    if (ans == -1){
        cout << "Element Not Found" << endl;
    }
    else {
        cout << "Element is Found at Index: " << ans << endl;
    }
    return 0;
}
