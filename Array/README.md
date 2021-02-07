## Array Data Structure

An array is a collection of items stored at contiguous memory locations. The idea is to store multiple items of the same type together. This makes it easier to calculate the position of each element by simply adding an offset to a base value, i.e., the memory location of the first element of the array (generally denoted by the name of the array). The base value is index 0 and the difference between the two indexes is the offset.

### Array’s size:

In C language array has a fixed size meaning once the size is given to it, it cannot be changed i.e. you can’t shrink it neither can you expand it. The reason was that for expanding if we change the size we can’t be sure ( it’s not possible every time) that we get the next memory location to us as free. The shrinking will not work because the array, when declared, gets memory statically, and thus compiler is the only one to destroy it.
 
### Types of indexing in an array: 

- 0 (zero-based indexing): The first element of the array is indexed by a subscript of 0
- 1 (one-based indexing): The first element of the array is indexed by the subscript of 1
- n (n-based indexing): The base index of an array can be freely chosen. Usually, programming languages allowing n-based indexing also allow negative index values, and other scalar data types like enumerations, or characters may be used as an array index.

## Advantages of using arrays: 

- Arrays allow random access to elements. This makes accessing elements by position faster.
- Arrays have better cache locality that can make a pretty big difference in performance.
- Arrays represent multiple data items of the same type using a single name.

## Disadvantages of using arrays: 
You can’t change the size i.e. once you have declared the array you can’t change its size because of static memory allocated to it. Here Insertion and deletion are difficult as the elements are stored in consecutive memory locations and the shifting operation is costly too.

## Applications on Array

- Array stores data elements of the same data type.
- Arrays can be used for CPU scheduling.
- Used to Implement other data structures like Stacks, Queues, Heaps, Hash tables, etc.
