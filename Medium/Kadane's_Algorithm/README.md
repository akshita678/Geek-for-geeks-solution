# Max Subarray Sum (Kadane's Algorithm)

## Problem Description
Given an integer array `arr[]`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

### Examples
* **Input:** `arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]`
* **Output:** `6`
* **Explanation:** The contiguous subarray `[4, -1, 2, 1]` has the largest sum = 6.

---

## Evolution of the Solution

### 1. Brute Force Approach (Initial Attempt)
* **Logic:** Use nested loops to generate all possible subarrays, calculate their sums, and keep track of the maximum sum found.
* **Time Complexity:** O(N²) or O(N³).
* **Limitation:** TLE (Time Limit Exceeded) on larger inputs due to redundant calculations.

### 2. Optimized Approach (Kadane's Algorithm)
* **Logic:** Traverse the array linearly while maintaining a running prefix sum. If the prefix sum drops below zero, reset it to zero since a negative sum will only decrease the sum of any subsequent subarray.

---

## Debugging Notes & Logic Ordering

During the implementation of Kadane's algorithm, a critical bug was encountered regarding the ordering of operations inside the loop:
* **The Bug:** Resetting the prefix sum (`prefix = 0`) *before* updating the maximum (`maxi`) causes failures on arrays containing **only negative numbers** (e.g., `[-2, -3, -1]`). If reset too early, `maxi` would incorrectly evaluate to `0` instead of `-1`.
* **The Fix:** Always update `maxi` with the current `prefix` *first* to capture the maximum single element or subarray sum, and *then* check if `prefix < 0` to reset it for the next window.

---

## Code (C++)

```cpp
class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int prefix = 0;
        int maxi = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            prefix = prefix + arr[i];
            
            // Fix: Update maximum first to safely handle all-negative arrays
            maxi = max(maxi, prefix);
            
            // Reset prefix if it becomes negative
            if (prefix < 0) {    
                prefix = 0;
            }
        }
        return maxi;
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** O(N) as the array is traversed exactly once.
* **Auxiliary Space:** O(1) as the maximum subarray sum is calculated in-place using only constant helper variables.
