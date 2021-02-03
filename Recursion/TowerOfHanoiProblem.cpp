/* C++ Recursive Program to solve Tower of Hanoi puzzle */

#include<iostream>

using namespace std;

int TOH(int n,int a,int b,int c)
{
    if(n>0)
    {
        TOH(n-1,a,c,b);
        cout<<"("<<a<<","<<c<<")"<<endl;
        cout<<"Move from "<<a<<" to "<<c<<endl;
        TOH(n-1,b,a,c);
    }
}

int main()
{
    int n;
    cout << "Enter Number of Disks: ";
    cin >> n;
    TOH(n,1,2,3);
}
