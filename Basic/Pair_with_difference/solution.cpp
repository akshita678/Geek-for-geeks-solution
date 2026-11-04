#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        int start = 0;
        int end = 1;
        
        // Sorting is required for the forward two-pointer approach to work
        sort(arr.begin(), arr.end());
        
        while (end < arr.size()) { 
            // Avoid comparing an element with itself
            if (start == end) {
                end = end + 1; 
            }
            
            int diff = arr[end] - arr[start];
            
            if (diff == x) {
                return true;
            }
            else if (diff < x) {
                end = end + 1; // Expand the window to increase the difference
            }
            else {
                start = start + 1; // Shrink the window to decrease the difference
            }
        }
        return false;
    }
};

int main() {
    Solution solver;
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    
    bool result = solver.findPair(arr, target);
    cout << result << endl; // Should return true or 1
    
    return 0;
}
