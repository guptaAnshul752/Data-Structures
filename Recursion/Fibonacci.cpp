/* Fibonacci series using Recursion */
/* Emphasis is laid on Base case in Recursion according to PMI */
/* Use PMI logic to form recursive codes */

#include<iostream>

using namespace std;

int fibo(int n)
{
    if(n<=1) // Base Condition
        return n;
    
    return fibo(n-1)+fibo(n-2);
}

int main()
{
    int n;
    
    cout<<"Enter the number :"<<endl;
    
    cin>>n;
    
    cout<<"Fibo number is: "<<fibo(n);
}
