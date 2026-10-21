# Rotate Array by 1 position

Hey! This is a solution to cyclic rotate by clockwise which means to **rotate an array to the right by 1 position**. 

It takes the last number of the array and puts it at the very beginning, and pushes all the other numbers forward.

## What it does

If you give it this array:
`[1, 2, 3, 4, 5]`

The program changes it to:
`[5, 1, 2, 3, 4]`

---

## My Code

Here is the code I wrote for the solution:

```cpp
class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
         int n=arr.size();
       int temp=arr[n-1]; // save the last number before it gets erased
       for(int i=n-2;i>=0;i--){
           arr[i+1]=arr[i]; // move numbers to the right
         
     
      
      
       }
        arr[0]=temp; // put the last number at the start
    }
};
```

---

## How I made it work

1. First, I find the **size of the array** using `arr.size()` and save it in `n`.
2. I copy the **very last element** (`arr[n-1]`) into a variable called `temp` so I don't lose it.
3. I use a `for` loop that goes backwards from `n-2` down to `0`. Inside the loop, it copies the value of `arr[i]` into the next box `arr[i+1]`.
4. Finally, I put the saved `temp` number into the **first box** (`arr[0]`).

## Speed and Memory

* **Time:** **O(n)** because the loop goes through the array once.
* **Space:** **O(1)** because I only created one extra variable called `temp`.
