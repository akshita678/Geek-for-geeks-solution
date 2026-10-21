#include <iostream>

using namespace std;

class Solution {
  public:
    // Added 'size' as a parameter because raw arrays cannot find their own length
    int missingNumber(int arr[], int size) {
        int max = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        
        // Checking numbers from 1 to max
        for (int j = 1; j <= max; j++) {
            bool found = false; // Reset to false for each target 'j'
            
            for (int i = 0; i < size; i++) {
                // Corrected Approach: Use 'equal to' to confirm existence
                if (arr[i] == j) {
                    found = true;
                    break; // Found it! Stop checking the rest of the array for this 'j'
                }
            }
            
            // If we checked the whole array and 'j' wasn't found, it's our missing number
            if (!found) {
                return j; 
            }
        }
        return max + 1; // Fallback: if 1 to max are all present, the next number is missing
    } 
};

int main() {
    Solution solver;

    // Test Case 1: Missing a number in the middle (3 is missing)
    int test1[] = {1, 2, 4, 5};
    int size1 = 4; // Number of elements in the array
    cout << "Test 1 - Missing Number: " << solver.missingNumber(test1, size1) << " (Expected: 3)\n" << endl;

    // Test Case 2: Array is sequential, missing the next consecutive number
    int test2[] = {1, 2, 3};
    int size2 = 3; // Number of elements in the array
    cout << "Test 2 - Missing Number: " << solver.missingNumber(test2, size2) << " (Expected: 4)\n" << endl;

    return 0;
}

