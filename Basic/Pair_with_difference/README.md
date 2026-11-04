# Find Pair Given Difference

## Problem Description
Given an array `arr[]` of integers and an integer `x`, determine if there exists a pair of elements `(arr[i], arr[j])` such that their absolute difference is exactly `x` (i.e., |arr[i] - arr[j]| = x where i != j). 

Return `true` if such a pair exists, otherwise return `false`.

### Examples
* **Input:** `arr = [5, 20, 3, 2, 50, 80]`, `x = 78`
* **Output:** `true`
* **Explanation:** The pair `(2, 80)` has an absolute difference of 78 (80 - 2 = 78).

---

## Debugging Notes & Edge Cases Handled

During implementation, two critical edge cases were identified and resolved:
* **Same Index Error (i = j):** A valid pair requires two *distinct* elements. If `start` and `end` point to the same index, the difference evaluates to 0. If `x` is 0, the code could falsely return `true`. 
  * *Fix:* Added an explicit check (`if (start == end)`) to force the `end` pointer forward.
* **Segmentation Fault (Out of Bounds):** Advancing pointers continuously can cause the `end` pointer to overrun the vector boundaries.
  * *Fix:* Restricted the loop driver with an explicit size constraint (`end < arr.size()`).

---

## Solution Approach
This solution leverages a **Sorting + Forward-Facing Two-Pointer** approach.

### Key Logic
1. **Why not a traditional meet-in-the-middle approach?** Initializing pointers at `0` and `n-1` works perfectly for finding a *target sum*. However, for finding a *target difference*, shrinking a window from both sides does not yield a predictable change in the difference.
2. **Moving Forward in Tandem:** By sorting the array and moving both pointers (`start` and `end`) from left to right, we can reliably manage the difference:
   * **If `diff < x`:** The current difference is too small. We expand the window by incrementing `end` to increase the gap.
   * **If `diff > x`:** The current difference is too large. We shrink the window by incrementing `start` to close the gap.

---

## Code (C++)

```cpp
class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        int start = 0;
        int end = 1;
        
        // Sorting is required for the forward two-pointer approach to work
        sort(arr.begin(), arr.end());
        
        while (end < arr.size()) { 
            // Avoid comparing an element with itself
            if (start == end) {
                end = end + 1; 
            }
            
            int diff = arr[end] - arr[start];
            
            if (diff == x) {
                return true;
            }
            else if (diff < x) {
                end = end + 1; // Expand the window to increase the difference
            }
            else {
                start = start + 1; // Shrink the window to decrease the difference
            }
        }
        return false;
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** O(N log N) where N is the number of elements in the array. Sorting takes O(N log N) time, while the two-pointer traversal takes linear O(N) time since each pointer moves at most N times.
* **Auxiliary Space:** O(1) as the operations are performed in-place with constant extra memory.
