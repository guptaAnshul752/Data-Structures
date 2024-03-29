// Inbuilt Priority Queue
// Max heap --> Element in decreasing Order

#include<bits/stdc++.h>
#include<queue>

using namespace std;

int main(){

    // By default Inbuilt Queue is Max Priority Queue
    priority_queue<int> p;
    // or priority_queue<int, vector<int> , less<int> > p;

    // Adding Elements
    p.push(5);
    p.push(10);
    p.push(15);
    p.push(30);
    p.push(3);
    p.push(50);
    p.push(100);

    // Size of queue
    cout << "Size: " << p.size() << endl;

    // Topmost(Max) element
    cout << "Max element: " << p.top() << endl;

    // Checking if Queue is Empty or Not
    cout << "IsEmpty?: " << p.empty() << endl;

    while(!p.empty()){
        cout << p.top() << " ";
        p.pop();
    }
    
    // Removing elements
    //p.pop();
    //p.pop();

    // Size
    //cout << "Size: " << p.size() << endl;

    // Max element after removing
    //cout << "Max element: " << p.top() << endl;
}
