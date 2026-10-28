# Problem: Count Zeroes
My C++ code to solve the Count Zeroes problem. I wrote a simple loop that checks each element one by one to count how many zeroes are in the array.

## 📝 Problem Description
Given a sorted binary array `arr[]` consisting only of 0s and 1s, where all 1s appear before all 0s, find the total number of zeroes in the array.

### Examples
**Example 1:**
* **Input:** `arr[] = {1, 1, 1, 1, 0, 0}`
* **Output:** `2`

**Example 2:**
* **Input:** `arr[] = {1, 0, 0, 0, 0}`
* **Output:** `4`

### Constraints
* `1 <= arr.size() <= 10^5`
* `arr[i]` can only be `0` or `1`.

---

## 💡 Approach & Implementation

### 1. Linear Search Loop (Accepted)
I used a straightforward `for` loop to look at every single slot in the array from the beginning up to the `end` index.

* **Why it works:** I set up a counter variable `c = 0` at the start. Every time the loop encounters an element equal to `0`, it adds `1` to `c`. Once the loop finishes checking the whole array, it returns the final count.

```cpp
class Solution {
  public:
    int countZeroes(vector<int> &arr) {
        // code here
        int end=arr.size()-1;
        int c=0;
        for(int i=0;i<=end;i++){
            if(arr[i]==0){
                c=c+1;
            }
       
        }
         return c;
    }
};
```

---

## 📊 Complexity Analysis

| Complexity | Scale | Reason |
| :--- | :--- | :--- |
| **Time Complexity** | `O(n)` | The loop scans every single element in the array once, so the time grows based on array size. |
| **Space Complexity** | `O(1)` | I only created two simple integer variables (`end` and `c`), so it uses no extra memory space. |

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
    int countZeroes(vector<int> &arr) {
        int end=arr.size()-1;
        int c=0;
        for(int i=0;i<=end;i++){
            if(arr[i]==0){
                c=c+1;
            }
        }
         return c;
    }
};

int main() {
    Solution solver;
    vector<int> arr = {1, 1, 1, 1, 0, 0};
    
    int result = solver.countZeroes(arr);
    cout << "The number of zeroes is: " << result << endl; // Should print 2
    
    return 0;
}
```

2. **Run it in terminal:**
```bash
g++ main.cpp -o main
./main
```
