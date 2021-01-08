// Recursion
// Find length of character array
#include<iostream>

using namespace std;

int len(char s[])
{
    if(s[0]=='\0'){  // \0 represents null character/value
        return 0;
    }
    int smallLenght= len(s+1);
    return 1+smallLenght;
}

int main()
{
    char str[100];
    cout<<"Enter characters: ";
    cin>>str;
    cout<<"Length of Character array: "<<len(str);
}
