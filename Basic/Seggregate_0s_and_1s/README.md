# Segregate 0s and 1s

## Problem Description
Given an array `arr[]` containing only `0`s and `1`s, the task is to segregate all `0s` to the left side and all `1s` to the right side of the array in-place.

### Examples
* **Input:** `arr = [0, 1, 1, 1, 0, 1, 0]`
* **Output:** `[0, 0, 0, 1, 1, 1, 1]`
* **Explanation:** All 0s are pushed to the left, and all 1s are pushed to the right.

---

## Solution Approach
This solution implements the **Counting Approach**:
1. **Count Frequencies:** Traverse the array once to count the total number of `0`s (`count0`) and `1`s (`count1`).
2. **Overwrite Array:** 
   * Fill the first `count0` positions of the array with `0`.
   * Fill the remaining positions up to the end of the array with `1`.

### Alternative Approaches Noted
* **Brute Force (Insertion Sort):** Sorting the elements manually via insertion sort. It takes **O(N²)** time.
* **Sorting Approach:** Using `sort(arr.begin(), arr.end())`. It takes **O(N log N)** time.
* **Two-Pointer Approach (Optimal)(yet to study as of now)**;

---

## Code (C++)

```cpp
class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int count1 = 0;
        int count0 = 0;
        
        // Step 1: Count 0s and 1s
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                count0++;
            } else {
                count1++;
            }
        }
        
        // Step 2: Fill 0s
        for (int i = 0; i < count0; i++) {
            arr[i] = 0;
        }
        
        // Step 3: Fill 1s
        for (int i = count0; i < arr.size(); i++) {
            arr[i] = 1;
        }
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** **O(N)** where *N* is the size of the array. The array is traversed twice: once for counting and once for rewriting.
* **Auxiliary Space:** **O(1)** as the segregation is performed in-place using only two counter variables.
