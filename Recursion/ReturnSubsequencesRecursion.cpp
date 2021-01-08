/* Returning Subsequences of a string,
   storing it in an array
   using Recursion */
/* In this approach ,data is loaded and then work is done on it
   and it is returned in its double size. */

/* Subsequences means subsets */
/* Total no. of subsequences possible = 2^n , n= Size of string */
/* Always note how the recursion/breakdown of recursion is applied */
#include<iostream>

using namespace std;

int subs(string input,string output[])
{
    if(input.empty()){     // Checks for empty string
        output[0]="";  //Base Case
        return 1;
    }
    string smallString = input.substr(1);
    int OutputSize = subs(smallString,output);
    for (int i=0; i <OutputSize; i++)
    {
        output[i+OutputSize]= input[0] + output[i];
    }
    return 2*OutputSize;

}
int main()
{
    string input;
    cout<<"Enter a String: "<<endl;
    cin>>input;
    cout<<input.size()<<endl;
    string* output = new string[100];
    int count = subs(input,output);
    for(int i=0;i<count;i++)
    {
        cout<< output[i] <<endl;
    }
}

