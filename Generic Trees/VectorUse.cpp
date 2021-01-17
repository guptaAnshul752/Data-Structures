// Vectors
// Similar to Dynamic Arrays
// Vector uses templates
// Indexes start at 0

#include<iostream>
#include<vector> // Important

using namespace std;

int main(){

    /// Initializing Vector Statically
    vector <int> v;

    /// Initializing Vector Dynamically
    // vector<int> *v = new vector<int>();

    // Inserting Element
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    //Updating Element
    v[1] = 100;

    //Bad Practice to use [] for element insertion
    //v[5] = 45;
    //v[6] = 45;

    //Displaying Capacity (Total Space)
    cout << "Capacity: " << v.capacity() << endl;

    //Deleting element from last Index
    v.pop_back();

    //Displaying Size (Total Elements Present)
    cout << "Size: " << v.size() << endl;

    // Displaying Elements
    for (int i = 0; i<v.size() ; i++){
        cout << v.at(i) << endl;
        // Alternate
        // cout << v[i] << endl;
    }
    /*
    //Fun experiment
    for (int i =0 ; i<100 ; i++){
        cout << "Cap: " << v.capacity() << endl;
        cout << "Size: "<< v.size() << endl;
        v.push_back(i+1);
    }
    */
}
