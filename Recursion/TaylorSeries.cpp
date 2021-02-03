/// Taylor Series using Recursion

// 3 operations involved:
// 1. Addition [ sum(n)=sum(n-1)+n ]
// 2. Power     [ pow(x,n)=pow(x,n-1)*x ]
// 3. Factorial [ fact(n)=fact(n-1)*n]

// Number of multiplications required = n(n+1)
// Taylor Series Complexity: O(n^2)
/// Taylor series involve all these operations.

#include<iostream>

using namespace std;

double e(int x,int n)
{
    static double p=1,f=1;
    double r;
    if(n==0)
        return 1;
    else
    {
        r=e(x,n-1);
        p=p*x;
        f=f*n;
        return r+p/f;
    }
}

int main()
{
    cout<<e(1,10);
}
