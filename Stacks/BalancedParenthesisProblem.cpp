// Check for Balanced Parenthesis Problem
// Stack DS is used

#include <iostream>
#include <stack> // Inbuilt stack methods are included
#include <string>

using namespace std;

bool checkBalanced(char *exp) {

    stack<char> s;
    int i = 0;

	while(exp[i]!=NULL){

        if(exp[i]=='{' || exp[i]=='[' || exp[i]=='('){
            s.push(exp[i]);
        }

        else if(exp[i]=='}'){

            if(s.empty()) {
                return false;
            }
            if(s.top()=='{'){
                s.pop();
            }
            else
                return false;
        }
        else if(exp[i]==']'){

            if(s.empty()) {
                return false;
            }
            if(s.top()=='['){
                s.pop();
            }
            else
                return false;
        }
        else if(exp[i]==')'){
            if(s.empty()) {
                return false;
            }
            if(s.top()=='('){
                s.pop();
            }
            else
                return false;
        }
        i++;
    }
    if(s.empty()){
        return true;
    }
    else
        return false;
}
int main()
{
    char input[100000];
    cout << "Please Enter the String: ";
    cin.getline(input, 100000);
//    cin >> input;
    if(checkBalanced(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}


