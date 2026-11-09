# Triplet Sum in Array (3Sum)

## Problem Description
Given an array `arr[]` of integers and an integer `target`, determine if there exists a triplet `(arr[i], arr[j], arr[k])` such that their sum is exactly equal to the `target` (where `i`, `j`, and `k` are distinct indices).

Return `true` if such a triplet exists, otherwise return `false`.

### Examples
* **Input:** `arr = [1, 4, 45, 6, 10, 8]`, `target = 13`
* **Output:** `true`
* **Explanation:** The triplet `[1, 4, 8]` sums up to 13 (1 + 4 + 8 = 13).

---

## Multiple Solution Approaches

### 1. Brute Force Approach
* **Logic:** Use three nested loops to generate every possible triplet combination in the array and check if their sum matches the target.
* **Time Complexity:** O(N³) 
* **Limitation:** Very inefficient for larger inputs, leading to TLE (Time Limit Exceeded).

### 2. Optimized Approach (Sorting + Binary Search)
* **Logic:** 
  1. Sort the array first to allow binary searching.
  2. Fix the first two elements using nested loops (`arr[i]` and `arr[j]`).
  3. Calculate the remaining value needed to hit the target: `find = target - arr[i] - arr[j]`.
  4. Perform a binary search for `find` in the remaining right portion of the array (`j + 1` to `n - 1`).
* **Time Complexity:** O(N² log N)
* **Space Complexity:** O(1) or O(log N) depending on the sort implementation.

---

## Code Implementations (C++)

### Brute Force Approach
```cpp
class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        int n = arr.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (arr[i] + arr[j] + arr[k] == target) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
```

### Optimized Approach (Sorting + Binary Search)
```cpp
class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        int n = arr.size();
        
        // Sorting allows us to look for the third element using Binary Search
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int find = target - arr[i] - arr[j];

                // Binary search for the 'find' value in the remaining array
                int start = j + 1;
                int end = n - 1;
                while (start <= end) {
                    int mid = start + (end - start) / 2;
                    if (arr[mid] == find) {
                        return true;
                    }
                    else if (arr[mid] < find) {
                        start = mid + 1;
                    }
                    else {
                        end = mid - 1;
                    }
                }
            } 
        }
        return false;
    }
};
```

---

## Complexity Analysis (Optimized Version)

* **Time Complexity:** O(N² log N). The outer two loops take O(N²) time altogether. For every pair, running the binary search takes O(log N) time. The sorting step takes O(N log N), which is dominated by the search steps.
* **Auxiliary Space:** O(1) as the calculations use the existing sorted array without any extra containers.
