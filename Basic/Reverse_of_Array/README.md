# Array Reversal in C++

A simple C++ program that takes an array of numbers and copies them into a second array in **reverse order**.

## 📌 What the Program Does
It takes a starting array and flips the sequence completely.
* **Original Array:** `[1, 2, 3, 4, 56]`
* **Reversed Array:** `[56, 4, 3, 2, 1]`

---

## 💡 How It Works (The "Mirror" Logic)
The code uses a **mirror-matching rule**: the first item goes to the last slot, the second item goes to the second-to-last slot, and so on. 

Mathematically, if the array size is 5, two positions are mirrors if their index numbers add up to **4**:
* Position **0** maps to Position **4** (0 + 4 = 4)
* Position **1** maps to Position **3** (1 + 3 = 4)
* Position **2** maps to Position **2** (2 + 2 = 4)

### Code Step-by-Step:
1. **Outer Loop (`i`):** Starts at the beginning of the original array and moves forward.
2. **Inner Loop (`j`):** Starts at the end of the new array and moves backward.
3. **The Match Check:** The code looks for the moment `i + j == 4`.
4. **The Copy:** Once matched, it copies the value from the old array directly into the flipped position in the new array.
5. **The Break:** The `break` keyword stops the search instantly once the right slot is filled, making it faster.

---

## 💻 Code

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 56};
    int p[5]; // Target array to hold the reversed numbers

    for (int i = 0; i < 5; i++) {
        // Look for the exact mirror position from the back
        for (int j = 4; j >= 0; j--) {
            // A match happens when indices add up to 4
            if (i + j == 4) { 
                p[j] = arr[i];
                break; // Stop looking once the item is copied
            }
        }
    }

    // Print the final reversed array
    for (int i = 0; i < 5; i++) {
        cout << p[i] << " ";
    }
 
    return 0;
}
```

---

## 🛠️ How to Run It
1. Copy the code into a file named `main.cpp`.
2. Open your terminal and run these commands:

```bash
g++ main.cpp -o reverse
./reverse
```
