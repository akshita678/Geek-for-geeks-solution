#include <iostream>
#include <vector>



using namespace std;
class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        // code here
        int prefix=0;
        int total=0;
        for(int i=0;i<arr.size();i++){
            total=total+arr[i];

        }
        for(int i=0;i<arr.size();i++){
            prefix=prefix+arr[i];
            int suffix=total-prefix;
            // BUG here : Changed '-' to '+' inside the comparison bcz prefix was including arr[i] whereas suffix was excluding it so it will never be equal
            if(prefix==suffix + arr[i]){ // temporarily added arr[i]so it works
                return i;
            }
        }
        return -1;
    }
};


int main() {
    Solution solver;
    vector<int> arr = {1, 2, 0, 3};
   
    
    int result = solver.findEquilibrium(arr);
    cout << result << endl; // Should return 2
    
    return 0;
}
