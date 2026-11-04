# LeetCode 167: Two Sum II - Input Array Is Sorted
My C++ code to solve the Two Sum II problem on LeetCode. I used the two-pointer approach since the array is already sorted, but I hit an index-offset error and almost got a Time Limit Exceeded (TLE) because of a missing return statement!

## 📝 Problem Description
Given a **1-indexed** array of integers `numbers` that is already **sorted in non-decreasing order**, find two numbers such that they add up to a specific `target` number. Let these two numbers be `numbers[index1]` and `numbers[index2]` where `1 <= index1 < index2 <= numbers.length`.

Return the indices of the two numbers, `index1` and `index2`, **added by one** as an integer array `[index1, index2]` of length 2.

The tests are generated such that there is **exactly one solution**. You **may not** use the same element twice.

Your solution must use only constant extra space.

### Examples
**Example 1:**
* **Input:** `numbers = [2,7,11,15]`, `target = 9`
* **Output:** `[1,2]`
* **Explanation:** The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return.

**Example 2:**
* **Input:** `numbers = [2,3,4]`, `target = 6`
* **Output:** `[1,3]`

**Example 3:**
* **Input:** `numbers = [-1,0]`, `target = -1`
* **Output:** `[1,2]`

### Constraints
* `2 <= numbers.length <= 3 * 10^4`
* `-1000 <= numbers[i] <= 1000`
* `numbers` is sorted in non-decreasing order.
* `-1000 <= target <= 1000`
* The tests are generated such that there is exactly one solution.

---

## 💡 Approach & Implementation

### 1. Two-Pointer Approach (Accepted)
Since the array is already sorted, we can place one pointer at the very beginning (`start = 0`) and another at the very end (`end = numbers.size() - 1`).

* **Checking the Sum:** We calculate the sum of the elements at both pointers. If `sum < target`, we need a larger value, so we shift the left pointer forward (`start++`). If `sum > target`, we need a smaller value, so we shift the right pointer backward (`end--`).
* **Match Found:** When `sum == target`, we save the indices and exit.

### ⚠️ My Mistakes & How I Fixed Them

* **The 1-Based Indexing Bug:** At first, I pushed the raw 0-based indices (`start` and `end`) directly into my answer array. This caused a wrong answer error because LeetCode specifically requests a **1-indexed** result. I fixed this by pushing `start + 1` and `end + 1` instead.
* **The Near-TLE Infinite Loop Bug:** When I found the matching pair, I originally forgot to put a `return ans;` statement inside that specific `if` block. Because the pointers weren't changing after finding the answer, the loop got trapped running forever on the exact same indices. This almost gave me a **Time Limit Exceeded (TLE)** error before I added the early return!

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start=0;int end=numbers.size()-1;
        vector<int>ans;
        while(start<end){
            int sum=numbers[start]+numbers[end];
            if(sum==target){
                ans.push_back(start+1); // i used indexing first that caused error
                ans.push_back(end+1);
                return ans;  // nearly got a tle because of this 
                
                
            }
            else if(sum<target){
                start++;

            }
            else{
                end--;
            }
        }
        return ans ;
         
        
    }
};
```

---

## 📊 Complexity Analysis

| Complexity | Scale | Reason |
| :--- | :--- | :--- |
| **Time Complexity** | `O(n)` | In the worst-case scenario, each element is visited at most once by either the start or end pointer. |
| **Space Complexity** | `O(1)` | No dynamic allocation structures are utilized beyond the small output array container. |

---

## 🛠️ How to Run Locally
You can test this code on your computer by copying everything below into a file named `main.cpp`.

1. **Code with main function:**

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start=0; int end=numbers.size()-1;
        vector<int> ans;
        while(start<end){
            int sum=numbers[start]+numbers[end];
            if(sum==target){
                ans.push_back(start+1); 
                ans.push_back(end+1);
                return ans;  
            }
            else if(sum<target){
                start++;
            }
            else{
                end--;
            }
        }
        return ans;
    }
};

int main() {
    Solution solver;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = solver.twoSum(numbers, target);
    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl; // Should print [1, 2]
    
    return 0;
}
```

2. **Run it in terminal:**
```bash
g++ main.cpp -o main
./main
```
