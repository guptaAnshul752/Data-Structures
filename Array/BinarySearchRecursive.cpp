/* C++ Program to perform Binary Searching of an element in an array RECURSIVELY*/
/* Condition required for Binary Search --> ARRAY SHOULD BE SORTED! */

#include<iostream>

using namespace std;

int binaryRecursive(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = (r + l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binaryRecursive(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binaryRecursive(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
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
    
    int ans = binaryRecursive(Arr,first,last,k);
    
    if (ans == -1){
        cout << "Element Not Found" << endl;
    }
    else {
        cout << "Element is Found at Index: " << ans << endl;
    }
}
