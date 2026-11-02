# Find the Largest Element in an Array

## Problem Description
Given an array `arr[]` of integers, the task is to find and return the maximum (largest) element present in the array.

### Examples
* **Input:** `arr = [1, 8, 7, 56, 90]`
* **Output:** `90`
* **Explanation:** The largest element of the given array is 90.

---

## Solution Approach
The problem is solved using a **single-pass linear scan** (Greedy approach):
1. **Initialize:** Assume the first element (`arr[0]`) is the maximum and store it in a variable `max`.
2. **Iterate:** Loop through the array starting from the second element (index 1) to the end.
3. **Compare & Update:** At each element, if the current element is greater than `max`, update `max` with the current element's value.
4. **Return:** After checking all elements, return `max`.

---

## Code (C++)

```cpp
class Solution {
  public:
    int largest(vector<int> &arr) {
        int max = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** **O(N)** where *N* is the number of elements in the array. We traverse the array exactly once.
* **Auxiliary Space:** **O(1)** as we only use a single variable (`max`) to store the result, requiring constant extra space.
