// Inbuilt Queue

#include<iostream>
#include<queue> // Includes All Queue Methods

using namespace std;

int main()
{
    // Creating Object of Inbuilt Queue
    queue<int> q;

    // Adding Elements to Queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout << "Front Element: " << q.front()<<endl;
    cout << "Size: " << q.size()<<endl;
    q.pop(); // Doesn't return deleted element as Return type is void
    cout << "Front Element: " << q.front()<<endl;
    cout << "Size: " << q.size()<<endl;
    cout << "Is Queue Empty: " << q.empty()<<endl;

    cout << "Emptying Queue:" << endl;
    //Emptying Queue & Printing Elements
    while (!q.empty()){
        cout << q.front() <<endl;
        q.pop();
    }
}

