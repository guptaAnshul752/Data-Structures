/* 1. Check whether the given array is sorted or not */
/* 2. Insert an element in a sorted array at its sorted position */
/* 3. Sort all negative values to the left of an array */

#include<iostream>

using namespace std;

void displayarr(int arr[],int n)
{
    for (int i=0;i<n+1;i++)
    {
        cout << arr[i] <<" ";
    }
}

void swap(int *a,int *b)
{
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}
int issorted(int arr[],int n)
{
    for (int i=0;i<n;i++)
    {
        if (arr[i] > arr[i+1])
        {
            return 0;
        }
    }
    return 1;
}
// No need to compare the element to be inserted with the elements in the array
// Function for inserting in a sorted array.
int insertion(int arr[],int n,int k)
{
   int i = n-1;
   while(arr[i] > k)
   {
       arr[i+1]=arr[i];
       i--;
   }
   arr[i+1]=k;
   displayarr(arr,n);
}

int shiftneg(int arr[],int n)
{
    int i = 0;   //Checks for +ve number
    int j = n-1; // Checks for -ve number

    while(i<j)
    {
      while(arr[i]<0)
     {
        i++;
     }
      while(arr[j]>=0)
     {
        j--;
     }
     if (i<j)
     {
         swap(arr[i],arr[j]);
     }
    }
    displayarr(arr,n);
}


int main()
{
    int A[5] = {1,2,5,7,9};
    int A1[10] = {-3,-5,1,2,-6,7,8,-9,10,-1};
    cout<< "Sorted(1) or Not(0): " <<issorted(A,5)<<endl;
    int k;
    cout<<"Enter the element you want to insert: ";
    cin>>k;
    cout << "Element Inserted Successfully!"<<endl;
    cout << "New Sorted Array: ";
    insertion(A,5,k);
    cout << "\n";
    cout<< "All negative placed to left successfully!"<<endl;
    cout<< "New Array: ";
    shiftneg(A1,10);
}
