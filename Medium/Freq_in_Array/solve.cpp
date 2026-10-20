#include <iostream>
#include <vector>

using namespace std;

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


int main() {
    Solution solver;
    
    // Sample test data 
    vector<int> numbers = {1, 2, 3, 4, 2, 2, 5};
    int targetNumber = 2;
    
    // Call the function and get the result!
    int result = solver.countFreq(numbers, targetNumber);
    
    // Print the final answer to the VS Code terminal 
    cout << "The number " << targetNumber << " shows up " << result << " times! " << endl;
    
    return 0;
}
