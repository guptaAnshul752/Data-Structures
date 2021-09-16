// Implementation of Priority Queues
// Min Heap

#include<bits/stdc++.h>
#include<vector>

using namespace std;

// PriorityQueue Class
class PriorQueue{

    vector<int> pq;

    public:

    // Constructor
    PriorQueue(){

    }

    // Get MinValue
    int getMinVal(){
        if (IsEmpty()){
            return 0;
        }
        return pq[0];
    }

    // IsEmpty
    bool IsEmpty(){
        return pq.size() == 0;
    }

    // GetSize --> Return size of Priority Queue
    int getSize(){
        return pq.size();
    }
    // Insert Value
    void insertVal(int val){

        pq.push_back(val);

        int ChildIdx = pq.size() - 1;

        while(ChildIdx > 0){

        int ParentIdx = (ChildIdx - 1)/2;

        // Up-Heapify
        if ( pq[ChildIdx] < pq[ParentIdx]){
            // Swapping parent & its child
            int temp = pq[ChildIdx];
            pq[ChildIdx] = pq[ParentIdx];
            pq[ParentIdx] = temp;
        }
        else{
            break;
        }
        ChildIdx = ParentIdx;
        }

    }

    // Remove Value(Min)
    int removeVal(){

    if (IsEmpty()){
        return 0;
    }
    // Swapping root with element at last index
    int root = pq[0];
    pq[0] = pq[pq.size() - 1];
    pq[pq.size() - 1] = root;
    pq.pop_back();

    int ParentIdx = 0;
    int LIdx = 2*ParentIdx + 1;
    int RIdx = 2*ParentIdx + 2;

    while(LIdx < pq.size()){

    int minIdx = ParentIdx;
    if (pq[minIdx] > pq[LIdx]){
        minIdx = LIdx;
    }
    if (RIdx < pq.size() && pq[minIdx] > pq[RIdx]){
        minIdx = RIdx;
    }

    if (ParentIdx == minIdx){
        break;
    }
    // Swapping parent with child
    int temp = pq[minIdx];
    pq[minIdx] = pq[ParentIdx];
    pq[ParentIdx] = temp;

    ParentIdx = minIdx;
    LIdx = 2*ParentIdx + 1;
    RIdx = 2*ParentIdx + 2;
    }
    return root;

    }
};

int main()
{

    PriorQueue p;
    /*
    p.insertVal(100);
    p.insertVal(10);
    p.insertVal(15);
    p.insertVal(4);
    p.insertVal(17);
    p.insertVal(21);
    p.insertVal(67);
    */
    int val;
    for(int j=1;j<7;j++){
        cin>>val;
        p.insertVal(val);
    }

    cout << "Size: " << p.getSize() << endl;

    cout << "Min Element: " << p.getMinVal() << endl;

    //cout << "Value Removed: " << p.removeVal() << endl;
    while(!p.IsEmpty()){
        cout << p.removeVal() << " ";
    }
    cout << endl;
}
