// Implementing Inbuilt Stack

#include <iostream>
#include <stack> // Inbuilt stack methods are included

using namespace std;

int main()
{
    // Inbuilt Stack implementation
    stack<int> s;

    // Push
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << "Size: " << s.size()<<endl;

    s.pop(); // Return Type of Pop is void
    s.pop();

    cout << "Size: " << s.size()<<endl;

    // Check if Stack is Empty
    cout << "Is Stack Empty? : " << s.empty() <<endl;

}
