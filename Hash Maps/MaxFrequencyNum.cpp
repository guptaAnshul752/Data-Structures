// Return Number with maximum frequency in an Array
// Using HashMaps
// Key--> Number stored in Array
// Value--> Count of that number

#include <iostream>
#include <unordered_map>

using namespace std;

// Function to Return Max Frequency Number
int maxFreq(int *input, int n){

    unordered_map<int,int> m;

    for (int i=0; i<n; i++){

        int key = input[i];
        if (m.count(key) > 0)
            m[key]++;
        else
            m[key]=1;
        }

        // Storing Value of Max key
        int max = m[input[0]];
        // Storing Max key
        int ans = input[0];
        int j=1;

        while (j< n){

            if (m[input[j]] > max){
                max = m[input[j]];
                ans = input[j];
            }
            j++;
        }
        return ans;
}
int main(){

    int n;
    cout << "Enter the Size of Array: ";
    cin>>n;
    int arr[n];
    cout << "Enter Elements in Array" <<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int maxKey= maxFreq(arr, n);
    cout<<"Maximum Frequent Number is: "<<maxKey;

}
