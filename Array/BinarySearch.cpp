/* C++ Program to perform Binary Searching of an element in an array */
/* Condition required for Binary Search --> ARRAY SHOULD BE SORTED! */

#include<iostream>

using namespace std;

int binary(int arr[],int first,int last,int k)
{
    while(first<=last)
    {
        int mid = (first+last)/2;
        if (k>arr[mid])
        {
            first=mid+1;
        }
        else if (k<arr[mid])
        {
            last=mid-1;
        }
        else if(k==arr[mid])
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    int length,k,siz;
    cout<<"Enter the size of Array: ";
    cin>>siz;
    int Arr[siz];
    cout<<"Enter no. of elements in Array: ";
    cin>>length;
    cout << "Enter the elements of the Array: ";
    for(int i=0;i<length;i++)
    {
        cin>>Arr[i];
    }
    int first = 0;
	int last = length-1;
    cout<<"Enter the element you want to search: ";
    cin>>k;
    int ans = binary(Arr,first,last,k);
    if (ans == -1){
        cout << "Element Not Found" << endl;
    }
    else {
        cout << "Element is Found at Index: " << ans << endl;
    }
}
