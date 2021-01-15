// Reversing a Queue

#include <iostream>
#include <queue>

using namespace std;

void reverseQueue (queue<int> &q) {

    if(q.empty()){
        return;
    }

    int a = q.front();
    q.pop();
    reverseQueue(q);
    q.push(a);

}

int main() {

    queue<int> q;
    int size;
    cout << "Enter Size of Queue: ";
    cin >> size;

    int val;
    cout << "Enter elements:" << endl;
    for(int i = 0; i < size; i++) {
    	cin >> val;
    	q.push(val);
    }
    reverseQueue(q);
    cout << "Reversed Queue is: ";
    while(!q.empty()) {
    	cout << q.front() << " ";
    	q.pop();
    }
}
