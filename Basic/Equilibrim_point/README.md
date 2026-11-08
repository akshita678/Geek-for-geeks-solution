# Equilibrium Point

## Problem Description
Given an array `arr[]` of integers, the task is to find the first **equilibrium index**. An equilibrium index is an index such that the sum of elements at lower indices is equal to the sum of elements at higher indices. 

If no such index exists, return `-1`.

### Examples
* **Input:** `arr = [1, 3, 5, 2, 2]`
* **Output:** `2`
* **Explanation:** At index 2, the left sum is `1 + 3 = 4` and the right sum is `2 + 2 = 4`.

---

## Debugging Notes & Logic Correction

During implementation, a bug was encountered due to how elements were accounted for in the tracking variables:
* **The Bug:** `prefix` is updated at the very start of the loop (`prefix = prefix + arr[i]`), meaning it *includes* the current element `arr[i]`. Meanwhile, `suffix` is calculated as `total - prefix`, meaning it *excludes* the current element. Comparing them directly or subtracting `arr[i]` from the wrong side broke the balance constraint, causing the condition to never match.
* **The Fix:** Changed a subtraction logic to an addition logic (`prefix == suffix + arr[i]`). By adding `arr[i]` back to the suffix side, it balances out the fact that `prefix` already contains `arr[i]`, ensuring an accurate comparison between the true left-side sum and right-side sum.

---

## Solution Approach
This solution optimizes the process using a **Two-Pass Total Sum** strategy to avoid nested loop overhead:
1. **First Pass:** Calculate the grand total sum of all elements in the array.
2. **Second Pass:** Maintain a running `prefix` sum as you iterate. Compute the remaining `suffix` sum on the fly by subtracting `prefix` from `total`.
3. **Check Equilibrium:** Evaluate the balance condition adjusting for the index offset, returning the current index immediately upon a match to guarantee the *first* equilibrium point is selected.

---

## Code (C++)

```cpp
class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        int prefix = 0;
        int total = 0;
        
        // Pass 1: Compute total array sum
        for (int i = 0; i < arr.size(); i++) {
            total = total + arr[i];
        }
        
        // Pass 2: Look for the equilibrium index
        for (int i = 0; i < arr.size(); i++) {
            prefix = prefix + arr[i];
            int suffix = total - prefix;
            
            // BUG fix: prefix includes arr[i] while suffix excludes it.
            // Adding arr[i] to suffix balances the comparison correctly.
            if (prefix == suffix + arr[i]) { 
                return i;
            }
        }
        return -1;
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** O(N) where N is the length of the array. The array is traversed at most twice linearly.
* **Auxiliary Space:** O(1) as the calculations are managed in-place using only constant accumulation variables.
