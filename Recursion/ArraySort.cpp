/* Checking whether given Array is sorted or not using Recursion */

#include<iostream>

using namespace std;

// Method - 1
bool sorted(int a[],int size)
{
    if(size<=1) // Base Condition
        return true;
    //Checking elements first
    if(a[0]>a[1]){
        return false;
    }
    return sorted(a+1,size-1); // Checking from starting array
}

// Method- 2
bool sorted2(int a[],int size)
{
    if(size<=1) // Base Condition
        return true;
    return sorted(a+1,size-1); // Checking from remaining array
    //Checking elements later
    if(a[0]>a[1]){
        return false;
    }
}

int main()
{
    int a[]={1,2,6,6,8};
    int b[]={1,2,9,6,8};
    cout<<"Is Array Sorted: "<<sorted(a,5)<<endl;
    cout<<"Is Array Sorted: "<<sorted2(b,5);
    
}


