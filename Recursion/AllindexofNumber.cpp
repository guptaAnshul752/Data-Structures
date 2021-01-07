/* All Index of a number in an Array using Recursion */
// Array to be formed containing each index at which element is present
// To return: Size of output array

#include<iostream>

using namespace std;

int all(int a[],int size,int x,int output[])
{
    if(size==0) // Base Condition
        return -1;
    for(int idx=0;idx<size;idx++){
        if(a[idx]==x){

        return output[idx];
    }
    }
    int ans = all(a+1,size-1,x,output);

    int i;
    output[i]=output[i+1];

    if(a[0]==x){
        // Shift the array
        return 0;
    }
    return ans+1;
    }

int main()
{
    int x=6;
    int output[10];
    int a[]={1,2,6,6,8,6}; //Element is scanned from left to right.
    cout<<"Element is at index : "<<all(a,6,x,output)<<endl;
}




