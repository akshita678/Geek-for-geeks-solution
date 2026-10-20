# counting how many times a number shows up in an array

Hi! This is my solution to solve the problem where you have an array of numbers and you need to find out how many times a specific target number appears.

## Code
Here is my C++ code that works:

```cpp
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int count=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==target){
                count=count+1;
            }
        }
        return count;
        
    }
};
```

## How my code works
1. First, I made a variable called `count` and set it to 0. This will keep track of how many times we see the target.
2. Then I got the size of the array using `arr.size()` and put it in a variable `n`.
3. Next, I made a `for` loop that starts at index 0 and goes all the way to `n-1`.
4. Inside the loop, it checks `if` the current number `arr[i]` matches the `target`.
5. If it matches, it adds 1 to `count`.
6. At the very end, it returns the `count` total.

## Time and Space
* **Time Complexity:** O(N) because the loop has to look at every single number in the array one time.
* **Space Complexity:** O(1) because I only made two regular variables (`count` and `n`) so it doesn't use extra memory.
