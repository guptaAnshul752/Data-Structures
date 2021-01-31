/* Reversing an Array */

#include<iostream>

using namespace std;

// Swap 2 values function
// Parameters passed by address
void swap(int *a,int *b)
{
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

int reverseArr(int arr[],int size)
{
    int l,r;
    for(l=0,r=size-1;l<r;l++,r--)
    {
        swap(arr[l],arr[r]);
    }
}

void printarr(int arr[],int size)
{
    for(int i=0;i<size;i++)
        cout<< arr[i] << " ";
}

int main()
{
    int arr[6]={1,2,3,4,5,6};
    reverseArr(arr,6);
    cout << "Reversed Array is ";
    printarr(arr,6);
}
