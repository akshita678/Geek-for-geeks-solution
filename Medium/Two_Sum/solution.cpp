#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start=0; int end=numbers.size()-1;
        vector<int> ans;
        while(start<end){
            int sum=numbers[start]+numbers[end];
            if(sum==target){
                ans.push_back(start+1); 
                ans.push_back(end+1);
                return ans;  
            }
            else if(sum<target){
                start++;
            }
            else{
                end--;
            }
        }
        return ans;
    }
};

int main() {
    Solution solver;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = solver.twoSum(numbers, target);
    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl; // Should print [1, 2]
    
    return 0;
}
