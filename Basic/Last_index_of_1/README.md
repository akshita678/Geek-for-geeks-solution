# Last Index of 1

## Problem Description
Given a string `s` consisting of only `'0'` and `'1'`, the task is to find and return the **last (rightmost) index** of the character `'1'` using 0-based indexing. If `'1'` is not present in the string, return `-1`.

### Examples
* **Input:** `s = "00001"`
* **Output:** `4`
* **Explanation:** The last '1' is present at index 4.

* **Input:** `s = "0000"`
* **Output:** `-1`
* **Explanation:** Since '1' is not present in the string, the output is -1.

---

## Solution Approach
The problem is solved using a **reverse linear scan** to maximize efficiency:
1. **Iterate Backwards:** Start the loop from the final character of the string (`s.size() - 1`) and move toward the first character (index `0`).
2. **Early Exit:** The first time a `'1'` is encountered, that index is guaranteed to be the *last* index of `'1'` in the forward string.
3. **Return immediately:** Return that index and break out of the function.
4. **Fallback:** If the loop finishes without finding a `'1'`, return `-1`.

---

## Code (C++)

```cpp
class Solution {
  public:
    int lastIndex(string &s) {
        int ans = -1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1') {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** **O(N)** where *N* is the length of the string. In the worst-case scenario (where '1' is at the very beginning or missing entirely), we traverse the string once. In the best-case scenario, it runs in **O(1)** time if the last character is '1'.
* **Auxiliary Space:** **O(1)** as the algorithm updates a single variable (`ans`) and operates directly on the input string without using extra memory.
