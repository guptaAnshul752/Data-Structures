/* Factorial of a number using Recursion */
/* Emphasis is laid on Base case in Recursion according to PMI */
/* Use PMI logic to form recursive codes */

#include<iostream>

using namespace std;

int fact(int n)
{
    /* Segmentation error as condition to when recursion should be stopped not provided.
    cout<<n<<endl;
    int out=fact(n-1);
    return n*out; */
    cout<<n<<endl;
    if(n==0) // Base Condition
        return 1;
    int out=fact(n-1);
    return n*out;
}

int main()
{
    int n;
    cout<<"Enter the number :"<<endl;
    cin>>n;
    cout<<"Factorial is: "<<fact(n);
}
