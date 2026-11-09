# Majority Element

## Problem Description
We are given an array of numbers. We need to find the "majority element." This is a number that appears **more than half the time** in the array (strictly more than N/2 times). 

If there is no such number, we just return `-1`.

### Examples
* **Input:** `arr = [3, 1, 3, 3, 2]`
* **Output:** `3`
* **Explanation:** The array has 5 numbers. Half of 5 is 2. The number 3 appears 3 times, which is more than 2, so it's the majority!

---

## How I Solved It (My Approach)

I used a really cool trick that involves **sorting** the array! 

### The Big Idea: The Middle Element Trick
If a number appears more than half the time, then no matter what, **it will always land on the middle index** after the array is sorted. 

Think about it like this:
* If the majority numbers are small, they fill up the left side and cross the middle.
* If they are big, they fill up the right side and cross the middle.
* If they are in between, they stay right in the center.

So, if a majority element exists, it *has* to be sitting at `arr[arr.size() / 2]`. 

### My Step-by-Step Plan:
1. **Sort the array:** I used `sort(arr.begin(), arr.end())` to put all the numbers in order from smallest to biggest. This groups all matching numbers together.
2. **Pick the candidate:** I looked right at the middle index and saved that number into a variable called `answer`.
3. **Count and Double-Check:** Sorting tells us *where* the answer should be, but we still have to make sure it actually appears more than half the time (for example, in `[1, 2, 3]`, the middle is 2, but 2 only appears once, which is not a majority). So, I ran a simple loop to count how many times our `answer` appears.
4. **Final Check:** If the count is bigger than `arr.size() / 2`, I return the number. If not, I return `-1`.

---

## Bugs I Ran Into & Fixed

* **The Index vs Element Bug:** When I first wrote the code, I accidentally tried to return the middle index number (`ans`) instead of the actual value stored at that index (`arr[ans]`). 
* **How I fixed it:** I created a separate variable `int answer = arr[ans];` before running my loop. This made sure I was counting and returning the actual number, not its position!

---

## Code (C++)

```cpp
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // Step 1: Sort the array so identical numbers sit next to each other
        sort(arr.begin(), arr.end());
        
        // Step 2: The majority element will always be at the middle index
        int ans = arr.size() / 2; 
        int answer = arr[ans]; // Saved the actual number here to fix my bug!
        
        // Step 3: Count how many times this middle number actually shows up
        int c = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == answer) {
                c = c + 1;
            }
        }
        
        // Step 4: If it shows up more than half the time, it's our winner
        if (c > ans) {
            return answer;
        }
        else {
            return -1;
        }   
    }
};
```

---

## Complexity (How fast it is)

* **Time Complexity:** **O(N log N)** because of the `sort()` function. Sorting takes up the most time. The loop after it is just **O(N)** because it checks the array only once.
* **Space Complexity:** **O(1)** because I didn't create any extra arrays or vectors. I only used a couple of basic variables (`ans`, `answer`, `c`) to keep track of my counts.
