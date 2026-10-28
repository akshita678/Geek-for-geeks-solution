#include <iostream>
#include <vector>

using namespace std;

    class Solution {
  public:
    int countZeroes(vector<int> &arr) {
        
        int end=arr.size()-1;
        int c=0;
        for(int i=0;i<=end;i++){
            if(arr[i]==0){
                c=c+1;
            }
       
        }
         return c;
    }
};

int main() {
    Solution solver;
    vector<int> nums = {1, 1, 0, 0};
    
    
    int result = solver.countZeroes(nums);
    cout << "The answer is: " << result << endl; 
    
    return 0; }