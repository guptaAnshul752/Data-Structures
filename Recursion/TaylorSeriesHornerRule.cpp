/* Taylor Series using Horner Rule */
/* Recursive and Iterative method  */

// Number of multiplications is reduced by this rule
// Complexity: O(n)

#include<iostream>

using namespace std;

/// Recursive
double eR(int x,int n)
{
    static double result=1;
    if(n==0)
        return result;

    result=1 + x*result/n;
    return eR(x,n-1);
}

/// Iterative
double ei(int x, int n)
{
   double s=1;
   int i;
   double num=1;
   double den=1;

   for(i=1;i<=n;i++)
   {
   num*=x;
   den*=i;
   s+=num/den;
   }
   return s;
}

int main()
{
    cout<<eR(1,10)<<endl;
    cout<<ei(1,10);
}
