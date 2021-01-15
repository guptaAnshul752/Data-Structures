// Reverse Stack
// Print Stack Elements in Reversed Order

#include <iostream>
#include <stack>

using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {

	int len = input.size();

    for(int i=0;i<len;i++){
        extra.push(input.top());
        input.pop();
    }
    input = extra;
}

int main(){

    stack<int> s1, s2;
    cout << "Enter Size of Stack: ";
    int size;
    cin >> size;

    cout << "Enter the elements in Stack: ";
    int val;
    for(int i = 0; i < size; i++) {
    	cin >> val;
    	s1.push(val);
    }

    reverseStack(s1, s2);

    cout << "Elements Printed in Reversed Manner are: ";
    while(!s1.empty()) {
    	cout << s1.top() << " ";
    	s1.pop();
    }
}
