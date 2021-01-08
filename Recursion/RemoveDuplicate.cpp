// Recursion
/* Remove duplicates or consecutive characters in a char array */
#include<iostream>

using namespace std;

int removeD(char s[])
{
    if(s[0]=='\0'){
        return 0;
    }
    removeD(s+1);
    if(s[0] != s[1]){
    return removeD(s+1);
   }
    else{
        int i=1;
    for(; s[i] != '\0';i++){
        s[i-1]=s[i];
    }

   s[i-1]=s[i];
   removeD(s);
    }
}

int main()
{
    char str[100];
    cout<<"Enter characters: ";
    cin>>str;
    cout<<"Character Array Before: ";
    cout<<str<<endl;
    removeD(str);
    cout<<"Character Array After: ";
    cout<<str<<endl;
}


