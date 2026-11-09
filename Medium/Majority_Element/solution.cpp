#include <iostream>
#include <vector>
#include<algorithm>


using namespace std;

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    int ans=arr.size()/2; // element at middle will always be majority since its sorted 
    int answer=arr[ans];
    // bug here returned indx instead of element 
    int c=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==answer){
            c=c+1;
        }
    }
    if(c>ans){
        return answer;
    }
     else{
         return -1;
     }   
    }
};
int main() {
    Solution solver;
    vector<int> arr = {1, 2, 4, 3,6,7};
   
    
    int result = solver.majorityElement(arr);
    cout << result << endl; // Should return -1
    
    return 0;
}
