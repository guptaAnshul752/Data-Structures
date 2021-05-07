// In-Place HeapSort
// Min Heap --> Decreasing Order Sort
// Space Complexity --> O(1)
// In-Place means without taking extra space

#include<bits/stdc++.h>
#include<vector>

using namespace std;

// HeapSort
void InplaceheapSort(int arr[],int n){

    // Build heap in Input Array
    for(int i=1;i<n;i++)
    {
        int childIdx = i;

        while(childIdx > 0){

            int parentIdx = (childIdx - 1)/2;

            if(arr[childIdx] < arr[parentIdx]){
                int temp = arr[childIdx];
                arr[childIdx] = arr[parentIdx];
                arr[parentIdx] = temp;
            }
            else{
                break;
            }
            childIdx = parentIdx;
    }
    }
    // Remove Min
    // Swapping root with element at last index
    int size = n;

    while(size > 1)
    {
    int root = arr[0];
    arr[0] = arr[size - 1];
    arr[size - 1] = root;

    size--;

    int ParentIdx = 0;
    int LIdx = 2*ParentIdx + 1;
    int RIdx = 2*ParentIdx + 2;

    while(LIdx < size){

    int minIdx = ParentIdx;
    if (arr[minIdx] > arr[LIdx]){
        minIdx = LIdx;
    }
    if (RIdx < size && arr[minIdx] > arr[RIdx]){
        minIdx = RIdx;
    }

    if (minIdx == ParentIdx){
        break;
    }
    // Swapping parent with child
    int temp = arr[minIdx];
    arr[minIdx] = arr[ParentIdx];
    arr[ParentIdx] = temp;

    ParentIdx = minIdx;
    LIdx = 2*ParentIdx + 1;
    RIdx = 2*ParentIdx + 2;

    }
    }
}

int main()
{
    int arr[] = {10,5,8,1,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    InplaceheapSort(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
