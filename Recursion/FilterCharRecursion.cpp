/* Recursion-2 */
// 2
/* Filter character in a char array */
#include<iostream>

using namespace std;

void removeX(char s[])
{
    if(s[0]=='\0'){
        return;
    }
    if(s[0] != 'x'){
    removeX(s+1);
   }
    else{
        int i=1;
    for(; s[i] != '\0';i++){
        s[i-1]=s[i];
    }

   s[i-1]=s[i];
   removeX(s);
    }
}

int len(char s[])
{
    if(s[0]=='\0'){
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
    cout<<"Character Array Before: ";
    cout<<str<<endl;
    cout<<"Length of Character array before: "<<len(str)<<endl;
    removeX(str);
    cout<<"Character Array After: ";
    cout<<str<<endl;
    cout<<"Length of Character array after: "<<len(str);

}
