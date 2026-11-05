#include <iostream>
#include <vector>
#include <climits> // imp if one wants to use INT_MIN


using namespace std;
class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {

        int n=arr.size();
        int prefix=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            prefix=prefix+arr[i];
            maxi=max(maxi,prefix);
            if(prefix<0){    // got a bug bcz of this 
                prefix=0;
            }
        }
        return maxi;
    }
};
int main() {
    Solution solver;
    vector<int> arr = {2, 7, -11, 15};
   
    
    int result = solver.maxSubarraySum(arr);
    cout << result << endl; // Should return 15
    
    return 0;
}
