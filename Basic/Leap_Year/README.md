# 🌟 GeeksforGeeks Solutions

Welcome to my repository of coding solutions from [GeeksforGeeks](https://geeksforgeeks.org)! 🚀 

This repository tracks my journey in mastering **Data Structures, Algorithms (DSA)**, and sharpening my problem-solving skills for technical interviews.

---

## 📂 Project Structure

The solutions are organized by difficulty level and problem name to make navigation simple:

```text
├── Basic/
│   └── Leap_Year/
│       ├── README.md
│       └── solution.cpp
```

---

## 📝 Featured Problem: Leap Year

### 🔴 Problem Statement
Given an integer `n`, check whether it is a leap year or not. 

**Rules for a Leap Year:**
1. It must be perfectly divisible by **400**.
2. Alternatively, it must be divisible by **4** but **NOT** divisible by **100**.

### 💻 My Solution (C++)
```cpp
#include <stdbool.h>

bool checkYear(int n) {
    // 1. Check if it's a century leap year
    if (n % 400 == 0) {
        return true;
    }
    // 2. Check if it's a regular leap year
    else if (n % 4 == 0 && n % 100 != 0) {
        return true;
    }
    // 3. Otherwise, it's not a leap year
    else {
        return false;
    }
}
```

### ⚡ Complexity
* **Time Complexity:** `O(1)` — The execution time remains constant regardless of the year input.
* **Space Complexity:** `O(1)` — No extra memory or data structures are utilized.

---

## 🛠️ How to Run Locally

If you want to test this code on your computer, follow these simple steps:

1. **Clone the repository:**
   ```bash
   git clone https://github.com
   ```
2. **Navigate to the problem folder:**
   ```bash
   cd Basic/Leap_Year
   ```
3. **Compile and run (using G++):**
   ```bash
   g++ solution.cpp -o solution
   ./solution
   ```
