// Map Implementation

#include <iostream>
#include <string>

using namespace std;

template <typename V>

// Linked List Node Class
class MapNode {
    public:
    string key;
    V value;
    MapNode* next;

    // Constructor
    MapNode(string key, V value){
    this -> key = key;
    this -> value = value;
    next = NULL;
    }

    // Destructor
    ~MapNode(){
    delete next;
    }
};

template <typename V>

// HashMap Class
class HashMap{

public:
    // BucketArray of type Head Node
    MapNode<V>** buckets;

    // Count of Entries in Map
    int count;

    // Size of Bucket Array
    int numBuckets;

    // Constructor
    HashMap(){
    count = 0;
    numBuckets = 5;

    // Creating Array
    buckets = new MapNode<V>*[numBuckets];

    // Initializing all Values of Empty Array to Null
    for (int i=0 ; i < numBuckets ; i++){
        buckets[i] = NULL;
    }
    }

    // Destructor
    ~HashMap(){

    // Deleting Head of LL first
    for (int i=0 ; i < numBuckets ; i++){
        delete buckets[i];
    }

    // Deleting Bucket Array
    delete [] buckets;
    }

    // Size Method--> Count of Entries in the Map
    int Size() {
        return count;
    }

    // Get Value at a particular key
    V getValue(string key){

    int bucketIndex = getBucketIndex(key);

    MapNode<V>* head = buckets[bucketIndex];

    while (head != NULL){
        if (head -> key == key){
            return head -> value;
        }
        head = head->next;
    }
    return 0; // Key Not Found
    }

    private:
    // Private getBucketIndex function which returns integer index value ranging between size of Array
    int getBucketIndex(string key){

    // Initializing HashCode and Current Coefficient Variables
    int hashCode = 0;
    int currentCoeff = 1;

    // Linear Probing Technique
    // Using Number Base 'p' concept
    // i.e if str = 'abc' , then hashCode = a*p^2 + b*p*1 + c*p^0
    // ,where p is a Prime Number (Chosen Randomly)

    // Loop operating from on string key from right to left
    for (int i = key.length()-1 ; i >= 0 ; i--){

        hashCode += key[i]*currentCoeff;

        // To Avoid out of Range of Int Error we will keep on decreasing HashCode to a limited range
        hashCode = hashCode % numBuckets;

        currentCoeff *= 37;
        // To Avoid out of Range Error of Int we will keep on decreasing currentCoeff to a limited range
        currentCoeff = currentCoeff % numBuckets;
    }
        
        return hashCode % numBuckets; // Return Compressed Value of keyIndex
        
    }

    // Rehashing Function
    void rehash(){

        // Creating Temp array pointing to buckets array
        MapNode<V>** temp = buckets;

        // Creating new buckets Array of twice the size
        buckets = new MapNode<V>*[2*numBuckets];

        // Initializing Values of new array to null
        for (int i=0; i<2*numBuckets; i++){
            buckets[i] = NULL;
        }

        // Updating values for new Array
        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        count = 0;

        // Traversing Old Array
        for (int i=0; i < oldBucketCount; i++){

            MapNode<V>* head = temp[i];

            // Traversing LL
            while (head != NULL){
                string key = head->key;
                V value = head->value;
                // Calling Insert
                insert(key,value);
                head = head->next;
            }
        }

        // Deleting Temp Array's LinkedList
        for (int i=0; i<oldBucketCount; i++){
            MapNode<V>* head = temp[i];
            delete head;
        }
        // Deleting Temp Array
        delete []temp;
    }

    public:

    // Function to get Load Factor
    double getLoadFactor(){
        return (1.0*count)/numBuckets;
    }
    // Insert Entry
    void insert (string key, V value){

    int bucketIndex = getBucketIndex(key);

    // Inserting Head of LL at bucketIndex in buckets Array
    MapNode<V>* head = buckets[bucketIndex];

    while (head != NULL){
        if (head->key == key){
            head -> value = value; // Updating Value
            return;
        }
        head = head -> next;
    }

    head = buckets[bucketIndex];

    // Creating LinkedListNode for New Entry
    MapNode<V>* node = new MapNode<V>(key,value);

    node->next = head;

    buckets[bucketIndex] = node;

    count++;

    // Load Factor
    double loadFactor = (1.0*count)/numBuckets;

    if (loadFactor > 0.7){
        rehash();
    }
    }

    // Remove Key
    V removeKey(string key){

    int bucketIndex = getBucketIndex(key);

    MapNode<V>* head = buckets[bucketIndex];

    MapNode<V>* prev = NULL;

    while (head != NULL){

        if (head -> key == key){
            if (prev == NULL){
                buckets[bucketIndex] = head -> next;
            }
            else {
                prev -> next = head -> next;
            }
            // Storing Value of Key to be Deleted
            V value = head -> value;

            head -> next = NULL;
            delete head;
            count--;
            return value;
        }
        prev = head;
        head = head -> next;
    }
    return 0; // Value not found
    }
};

int main(){

    HashMap<int> hashmp;

    // Rehashing is done twice here
    // 1st at iteration 4th
    // 2nd at iteration 8th
    for (int i=0; i<10; i++){
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i+1;
        hashmp.insert(key,value);
        cout << "Load Factor: " << hashmp.getLoadFactor() << endl;
    }

    cout << "Size: " << hashmp.Size() << endl;

    // Removing key
    cout << "Key Removed: " << hashmp.removeKey("abc2") << endl;
    cout << "Key Removed: " << hashmp.removeKey("abc7") << endl;

    // Printing out Key and Value
    for (int i=0; i<10; i++){
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout << key << ": " << hashmp.getValue(key) << endl;
    }
    cout << "Size: " << hashmp.Size() << endl;
}
