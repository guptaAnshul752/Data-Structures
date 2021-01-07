/* Return First Index of a number in an Array using Recursion */
//Element is scanned from left to right.
/* 3 steps to be done
  1. Base case
  2. Recursive call
  3. Small calculations
  Order of 2. & 3. is changeable
*/

#include<iostream>

using namespace std;

int first(int a[],int size,int x)
{
    if(size==0) // Base Condition
        return -1;

    if(a[0]==x){
        return 0;
    }
    int ans = first(a+1,size-1,x);
    if(ans == -1){
        return ans;
    }
    else{
        return ans+1;
    }
}
int main()
{
    int x=8;
    int a[]={1,2,6,6,8}; //Element is scanned from left to right.
    cout<<"Element is at index : "<<first(a,6,x)<<endl;
}



