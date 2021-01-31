/* Arrays ADT
1. Get() -- Return element at a particular index
2. Set() -- Replace value at a particular index
3. Max() -- Maximum value in an Array
4. Min() -- Minimum value in an Array
5. Sum() -- Sum of elements in an Array
6. Avg() -- Average of elements in an Array
*/

#include<iostream>

using namespace std;

int getelement(int a[],int size,int i)
{
    if(i>=0 && i<size)
        return a[i];
    return -1;
}

int setelement(int a[],int size,int i,int k)
{
    if(i>=0 && i<size)
        a[i]=k;
        return k;
    return -1;
}

int maxArr(int a[],int size)
{
    int maximum=a[0];
    int i=1;
    if (size==0)
        return -1;
    while(i<size)
    {
      if(a[i]>maximum)
       maximum = a[i];
      i++;
    }
    return maximum;
}

int minArr(int a[],int size)
{
    int minimum=a[0];
    int i=1;
    if (size==0)
        return -1;
    while(i<size)
    {
      if(a[i]< minimum)
       minimum = a[i];
      i++;
    }
    return minimum;
}

int sumArr(int a[],int size)
{
    int total=0;
    int i=0;
    if (size==0)
        return -1;
    while(i<size)
    {
      total += a[i];
      i++;
    }
    return total;
}

int averageArr(int a[],int size)
{
    int total=0;
    int i=0;
    if (size==0)
        return -1;
    while(i<size)
    {
      total += a[i];
      i++;
    }
    return total/size;
}

int main()
{
    int n,k,r;
    cout<<"Enter the Size of the Array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the Array: ";
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the index whose value is to be returned: ";
    cin>>k;
    cout<<"Element at Index"<<" "<<k<<" is "<<" "<<getelement(arr,n,k)<<endl; //get element
    cout<<"Enter the new value: ";
    cin>>r;
    cout<<"Element at Index"<<" "<<k<<" is now:"<<" "<<setelement(arr,n,k,r)<<endl; //set element
    cout<<"Maximum element in the given array is: "<<maxArr(arr,n)<<endl; //Max element
    cout<<"Minimum element in the given array is: "<<minArr(arr,n)<<endl; //Min element
    cout<<"Sum of elements in the given array is: "<<sumArr(arr,n)<<endl; //Sum of elements
    cout<<"Average of elements in the given array is: "<<averageArr(arr,n)<<endl; //Average of elements
}
