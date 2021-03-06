// Remove Duplicates from an integer array
// Using HashMaps

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Creating a function that returns a vector to store unique values
vector<int> removeDuplicates(int *arr, int size){

    vector<int> output;
    unordered_map<int, bool> seen;

    // Traversing through array
    for (int i=0; i<size ;i++){
        if (seen.count(arr[i]) > 0){
            continue;
        }
        // Assigning values to Hashtable
        seen[arr[i]] = true;

        // Adding entry to vector
        output.push_back(arr[i]);
    }

    return output;
}

int main()
{
  int Arr[10] = {1,2,1,4,5,2,7,8,1,2};
  
  vector<int> output = removeDuplicates(Arr, 10);

  for (int i=0;i<output.size();i++)
  {
      cout << output[i] << " ";
  }
}
