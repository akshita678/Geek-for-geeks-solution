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
    

