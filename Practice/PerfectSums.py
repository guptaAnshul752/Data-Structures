# Python Program to find perfect sums

# Problem Description
# Given an array arr[] of integers and an integer K, the task is to print all subsets of the given array with the sum equal to the given target K.

# Find all subsets of an array
def subsets(nums):
        ans = []
        for i in range(0,2**len(nums)):
            subset = []
            for j in range(0,len(nums)):
                if (i>>j) & 1 == 1:
                    subset.append(nums[j])
            
            ans.append(subset)
        return ans

# Function to find perfect sums
def perfectSums(arr,K):
    # Subarrays of given array
    subarr = subsets(arr)
    
    count = 0
    
    for val in subarr[1:]:
        if sum(val) == K:
            count += 1
            
    return count
    
if __name__ == '__main__':
  
  N = int(input())
  
  arr = list(map(int,input().split()))

  K = int(input())
  
  output = perfectSums(arr,K)

  print(output)
