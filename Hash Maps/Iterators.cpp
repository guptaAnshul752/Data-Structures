// Iterator
// Traversing entries of hashtable(unordered map) using iterators
// Ordering of element is NOT maintained

#include<iostream>
#include<unordered_map>

using namespace std;

int main(){

    unordered_map <string, int>  mapobj;

    mapobj["abc"] = 1;
    mapobj["def"] = 2;
    mapobj["ghi"] = 3;
    mapobj["jkl"] = 4;
    mapobj["mno"] = 5;
    mapobj["pqr"] = 6;

    // Iterator
    unordered_map <string, int> :: iterator it = mapobj.begin();

    while (it != mapobj.end())
    {
      // Key Value pair are not printed in order as it is unordered map
      cout << "Key: " << it->first << " " << ", Value: " << it->second << endl;
      it++;
    }

    // Finding Element
    // mapobj.find returns an iterator object
    unordered_map <string, int> :: iterator it1 = mapobj.find("pqr");
    cout << "Value Found: " << it1->second << endl;

}
