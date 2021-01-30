// Array Representation and Display Using
// 1. Structure
// 2. Class

#include <iostream>

using namespace std;

// Creating a structure for Array Representation
struct Array {
   int *A;    // Dynamic Memory allocation i.e in Heap
   int size;
   int length;

};

// Display Array
void display(struct Array arr)
{
    for(int i=0;i<arr.size;i++)
    {
        cout<<arr.A[i]<<" ";
    }
}

int main()
{
    struct Array arr;
    cout<<"Enter the size of Array: ";
    cin>>arr.size;
    arr.A= new int[arr.size]; // DMA(Heap)
    int length = 0;
    cout << "Enter the elements of the Array: ";
    for(int i=0;i<arr.size;i++)
    {
        cin>>arr.A[i];
    }
    cout<<"The elements of the Array are: ";
    display(arr);

    delete []arr.A;
    return 0;
}

/// Array representation using Class concept(OOPS)

/*
class Array {
private:
    int* A;
    int size;
    int length;

public:
    Array(int size) {
        this->size = size;
        A = new int [size];
    }

    void create(){
        cout << "Enter number of elements: " << flush;
        cin >> length;
        cout << "Enter the array elements: " << endl;
        for (int i = 0; i < length; i++){
            cout << "Array element: " << i << " = " << flush;
            cin >> A[i];
        }
    }

    void display(){
        for (int i = 0; i < length; i++){
            cout << A[i] << " ";
        }
    }

    ~Array(){
        delete[] A;
        cout << "Array destroyed" << endl;
    }
};

int main() {
    Array arr(10);
    arr.create();
    arr.display();
    return 0;
}
*/
