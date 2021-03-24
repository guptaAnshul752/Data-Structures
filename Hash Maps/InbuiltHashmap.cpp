// Inbuilt HashMap
// Unordered_map --> HashTable

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {

    // Creating Object of unordered map
    unordered_map <string, int> hashmap;

    /// Insert

    // Option-1 -> Using inbuilt pair class
    pair <string, int> p("abc", 1);
    hashmap.insert(p);

    // Option-2
    hashmap["def"] = 2;

    /// Find or Access

    cout << hashmap.at("abc") <<endl;

    // Finding entry which is not present
    // option1
    // hashmap.at("ghi") gives Error

    // option2
    cout << hashmap["ghi"] << endl;
    // This adds an entry to the hashtable and assign value 0 and hence returns it.

    /// Size of Hashtable
    cout << "Size : "<< hashmap.size() << endl;

    /// Delete or Erase
    hashmap.erase("ghi");

    /// Size of Hashtable
    cout << "Size : "<< hashmap.size() << endl;

    /// Check presence
    if (hashmap.count("def") > 0){
        cout << "Present" << endl;
    }

}
