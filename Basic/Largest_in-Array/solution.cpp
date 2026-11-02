#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int largest(vector<int> &arr) {
    
        int max=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        return max;
    }
};

int main() {
    Solution solver;
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    
    
    int result = solver.largest(arr);
    cout << "Largest " << result << endl; // Should print 4
    
    return 0;
}