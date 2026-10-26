# Insertion Sort

Hi! This is my C++ solution for the Insertion Sort problem. It takes an array of numbers and sorts them in ascending order.

## How My Code Works
1. I start the first loop at `i = 1` because a single element at index 0 is already sorted.
2. The second loop goes backward from `i` down to `1`.
3. Inside, it compares the current number with the one before it (`arr[j] < arr[j-1]`).
4. If it's smaller, it swaps them to move the smaller number to the left.
5. If it's not smaller, it breaks out of the inner loop because the left side is already sorted!

## Code
```cpp
class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        
        for (int i = 1; i < n; i++) {
            for (int j = i; j > 0; j--) {
                if (arr[j] < arr[j - 1]) {
                    // Swap elements if they are out of order
                    swap(arr[j], arr[j - 1]);
                }
                else {
                    // Stop looking back if the element is in the right spot
                    break;
                }
            }
        }
    }
};
```

## Time and Space Complexity
* **Time Complexity:** O(N^2) in the worst case (like if the array is backwards). But it runs in O(N) time if the array is already sorted!
* **Space Complexity:** O(1) because I am sorting everything inside the original array and not making a new one.
