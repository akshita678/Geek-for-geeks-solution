# Missing Number Solution

A C++ solution to find the missing number in an array using an iterative search approach.

## Table of Contents
1. [Problem Statement](#problem-statement)
2. [Approach & Evolution](#approach--evolution)
3. [Code Implementation](#code-implementation)
4. [Complexity Analysis](#complexity-analysis)

---

## Problem Statement
Given an array `arr` containing distinct numbers, find the missing number in the sequential range.

## Approach & Evolution

### 1. Initial Logic (The "Not Equal To" Pitfall)
* **Concept:** The initial idea was to loop through the range and check if elements were **not equal to** (`arr[i] != j`) the target number to immediately flag it as missing.
* **Flaw:** This approach fails because a number being unequal to *one* element in the array does not mean it is missing from the *entire* array. It incorrectly flags numbers as missing prematurely.

### 2. Corrected Logic (The "Equal To" Approach)
* **Fix:** The logic was inverted to the **equal to** (`arr[i] == j`) approach. 
* **Mechanism:** The inner loop searches the entire array to confirm if a number `j` exists (`found = true`). After scanning the whole array, if `found` remains `false`, we can definitively conclude that `j` is the missing number.

## Code Implementation

```cpp
class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int max=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        
        for(int j=1;j<=max;j++){
            bool found=false; 
            for(int i=0;i<arr.size();i++){
                if(arr[i]==j){
                    found=true;
                    break; 
                }
            }
            if(!found) {
                return j; 
            }
        }
        return max + 1; 
    } 
};
```

## Complexity Analysis
* **Time Complexity:** \(O(N^2)\) due to the nested loop scanning the array for each integer up to `max`.
* **Space Complexity:** \(O(1)\) as it only uses a few primitive variables for tracking.
