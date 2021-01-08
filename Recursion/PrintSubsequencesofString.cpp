/* Printing Subsequences of a string,
   Recursion (Approach - 2) */
/* In this approach there's no need of loading of data,
   decision is made by us and then further work is to
   be done by recursion. */
/* Faster and takes up less space */
/* Subsequences means subsets */
/* Total no. of subsequences possible = 2^n , n= Size of string */
/* Always note how the recursion/breakdown of recursion is applied */
#include<iostream>

using namespace std;

void print_subs(string input,string output)
{
    if(input.length()==0){     // Checks for empty string
        cout<<output<<endl;  //Base Case
        return;
    }

    print_subs(input.substr(1),output); // First String not included
    print_subs(input.substr(1),output+input[0]); // First String included

}
int main()
{
    string input;
    string output = "";
    cout<<"Enter a String: "<<endl;
    cin>>input;
    cout<<input.size()<<endl;
    print_subs(input,output);
}


