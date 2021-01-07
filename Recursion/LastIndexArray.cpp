/* Return Last Index of a number in an Array */
/* 3 steps to be done
  1. Base case
  2. Recursive call
  3. Small calculations
  Order of 2. & 3. is changeable
*/
//Element is scanned from right to left.

#include<iostream>

using namespace std;

int last(int a[],int size,int x)
{
    if(size==0) // Base Condition
        return -1;

    int ans = last(a+1,size-1,x);
    if(a[0]==x && ans!=-1)
    {
        return ans+1;
    }
    else if(a[0]==x&&ans==-1)
    {
        return 0;
    }
    else if(a[0]!=x)
    {
        if(ans==-1)
        {
            return -1;
        }
        else
        {
            return ans+1;
        }
    }
}
int main()
{
    int x=6;
    int a[]={1,2,6,6,8}; //Element is scanned from right to left.
    cout<<"Element is at index : "<<last(a,5,x)<<endl;
}
