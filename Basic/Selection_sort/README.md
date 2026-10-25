# GeeksforGeeks / Standard DSA - Selection Sort 🚀

Hey there! This is my beginner-friendly solution for the standard **Selection Sort** problem on GeeksforGeeks/DSA. Building on my previous challenge, I stripped out the temporary console logs and adapted the function to work generically on any reference vector `vector<int> &arr`!

## My Approach 💡

I stuck with the clean, intuitive mechanics of **Selection Sort** to solidify how boundaries shift during in-place mutations:
1. I find the total size of the vector `n` so I know exactly how far to scan.
2. The outer loop (`i`) marks the boundary. Everything to the left of `i` is fully sorted, and everything to the right is the remaining unsorted territory.
3. I initialize `index = i`, assuming the first unsorted item is the smallest.
4. The inner loop (`j`) scans the rest of the array. If it discovers a smaller element than what's at `arr[index]`, it saves that new position to `index`.
5. After the inner pass finishes, I use C++'s standard `swap()` to pop that absolute minimum element right into position `i`.

## C++ Code 💻

```cpp
class Solution {
  public:
    void selectionSort(vector<int> &arr) {
        int n=arr.size();
        for(int i=0;i<n-1;i++){
           int index=i;
           for(int j=i+1;j<n;j++){
               if(arr[j]<arr[index]){
                   index=j;
               }
              
           }
           swap(arr[i],arr[index]);
          
        }
      
    }
};
```

## Key Learnings Re-enforced 🧠

Writing it cleanly as a standard void utility function taught me a few more great habits:
* **No `cout` in Production:** Removing the debug loop makes the function pure, modular, and much faster since console I/O operations are quite heavy.
* **Pass by Reference (`&`):** Because `arr` is passed as a reference (`vector<int> &arr`), all the swaps happen directly on the caller's array. I don't need to waste time or memory duplicating the data.
* **Stable Swap Logic:** Waiting until the inner loop completely finishes before executing `swap()` minimizes memory writes, making Selection Sort uniquely efficient in terms of the maximum number of swaps ($O(n)$ swaps total).

## Complexity Analysis 📊

* **Time Complexity:** $O(n^2)$ 
  Both the best-case and worst-case scenarios take quadratic time because the nested loops will always look through the remaining elements to ensure it found the absolute minimum.
* **Space Complexity:** $O(1)$ 
  Auxiliary space remains constant because the algorithm safely reorganizes the items in-place.
