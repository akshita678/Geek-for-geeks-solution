# Finding Min and Max Numbers

Hey everyone! This is a solution to the above stated problem I wrote to find the smallest (minimum) and biggest (maximum) numbers in a list of numbers. 

I'm sharing this to show how I solved it using basic loops and `if` statements.

## How My Logic Works

I used a card-checking trick to think about this problem:
1. I created two variables: `mn` for the minimum and `mx` for the maximum.
2. I started `mx` at the super tiny number `INT_MIN` so *any* number I find will be bigger than it.
3. I started `mn` at the super huge number `INT_MAX` so *any* number I find will be smaller than it.
4. Then I used a standard `for` loop to look at each number in the list one by one.
5. Inside the loop, I just check if the current number beats my current min or max, and update them.
6. At the end, I put both answers inside curly braces `{mn, mx}` to send them back as a vector!

## The Code

Here is my full code. You can copy it and test it out yourself!

```cpp
#include <iostream>
#include <vector>
#include <climits> // I needed this header to use INT_MIN and INT_MAX!

using namespace std; // Using this so I don't have to type std:: everywhere

class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        // Setting up my starting values
        int mx = INT_MIN; // The lowest integer possible
        int mn = INT_MAX; // The highest integer possible

        // A loop to go through the whole array
        for (int i = 0; i < arr.size(); i++) {
            // Check if this number is the new biggest
            if (arr[i] > mx) {
                mx = arr[i];
            }
            // Check if this number is the new smallest
            if (arr[i] < mn) {
                mn = arr[i]; 
            }
        }

        // Return the two answers together
        return {mn, mx}; 
    }
};

int main() {
    Solution solver;
    
    // My test numbers
    vector<int> numbers = {3, 5, 4, 1, 9, -2, 6};
    
    // Call the function
    vector<int> result = solver.getMinMax(numbers);
    
    // Show the results on the screen!
    cout << "Minimum number is: " << result[0] << endl;
    cout << "Maximum number is: " << result[1] << endl;
    
    return 0;
}
```

## What I Learned From This
* **Time Complexity:** It's O(N) because the `for` loop goes through the array exactly one time.
* **Space Complexity:** It's O(1) because I only made two integer variables (`mn` and `mx`) to keep track of the values, so it doesn't use up extra memory.

