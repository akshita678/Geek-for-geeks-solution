# Basic Searching: Linear Search

This folder contains beginner-friendly solutions for basic searching problems on GeeksforGeeks. It forms part of my larger repository dedicated to tracking my problem-solving journey.

## 📌 Problem Overview

Searching is the fundamental process of finding the index or position of a specific target element within a collection of data. This module covers **Linear Search**, which is the foundational approach for inspecting datasets.

### Key Highlights
* **Category:** Basic Data Structures / Algorithms
* **Platform:** GeeksforGeeks (GFG)
* **Language:** C++ (g++ 5.4+)

---

## 💡 Logic Explanation (For Revision)

The core logic relies on a sequential scan, making it highly intuitive:
1. **Start at the Beginning:** The algorithm begins checking elements from index `0`.
2. **Step-by-Step Inspection:** It looks at each element one by one, moving from left to right.
3. **Match Found:** The moment the current element matches the target value `x`, the algorithm immediately stops and provides the current index.
4. **Exhaustive Search:** If the loop finishes checking every single element in the vector and finds no match, it concludes that the element does not exist. It then provides `-1` as a standard flag for "Not Found".

---

## 💻 Code Breakdown

The problem logic is encapsulated within a `Solution` class to match GFG's submission layout. Below is the complete source code followed by an explanation of its internal mechanics.

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int search(vector<int>& arr, int x) {
        // Sequential scan of the array
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == x) {
                return i; // Element located; return its index
            }
        }
        return -1; // Element not present in the vector
    }
};

int main() {
    Solution solver;
    
    // Test Case: Target exists
    vector<int> numbers = {10, 20, 30, 40, 50};
    int target = 30;
    
    int result = solver.search(numbers, target);
    
    if (result != -1) {
        cout << "Element " << target << " found at index: " << result << endl;
    } else {
        cout << "Element " << target << " not found." << endl;
    }
    
    return 0;
}
```

### ⚙️ How the Code Works Line-by-Line:
* **`for (int i = 0; i < arr.size(); i++)`**: This loop runs from index `0` up to the final index of the vector (`arr.size() - 1`). It guarantees that no element is skipped.
* **`if (arr[i] == x)`**: A conditional check performed at every iteration to see if the current value matches our target `x`.
* **`return i;`**: If the conditional check is true, this statement executes. It instantly terminates the function execution and returns the index `i` back to the caller. This saves CPU cycles by avoiding unnecessary iterations once the job is done.
* **`return -1;`**: This line is placed outside the loop. It acts as a fallback mechanism. It will only ever be reached if the loop completes entirely without hitting the inner `return i;` statement.
## One more thing to keep in mind is the use of .size() function and not the size of(array) function as it is not gonna give us the number of elements in array but rather the size of vector 
---

## 📊 Complexity Analysis

* **Time Complexity:** **O(N)** — In the worst-case scenario (if the target element is at the very end or absent), the algorithm must check all N elements.
* **Space Complexity:** **O(1)** — Auxiliary space is constant because no additional data structures are allocated.

---

## 🛠️ Local Compilation

To verify modifications or test alternative inputs locally before committing to the repository:

```bash
g++ -std=c++14 main.cpp -o local_test
./local_test
```
