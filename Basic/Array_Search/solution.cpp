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