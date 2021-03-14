// Iterator
// Traversing entries of Vector using iterators
// Ordering of element is NOT maintained

#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector <int>  var;

    var.push_back(10);
    var.push_back(20);
    var.push_back(30);
    var.push_back(40);
    var.push_back(50);
    var.push_back(60);
    var.push_back(70);

    // Iterator
    vector <int> :: iterator it = var.begin();

    // Printing Elements
    while (it != var.end())
    {
      cout << *it << endl;
      it++;
    }

    cout << "Size: " << var.size() << endl;

    // Erasing Elements in a particular range
    // erase is an iterator
    // var.erase([StartIndex , EndIndex)) ,EndIndex is exclusive
    vector <int> :: iterator it1 = var.begin();
    var.erase(it1, it1+4);
    cout << "Size: " << var.size() << endl;

}

