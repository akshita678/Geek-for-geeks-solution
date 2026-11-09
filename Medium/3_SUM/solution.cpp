#include <iostream>
#include <vector>
#include<algorithm>


using namespace std;

class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        
        int n=arr.size();
        sort(arr.begin(),arr.end());
               for(int i=0;i<n-2;i++){
                   for(int j=i+1;j<n-1;j++){
                       int find=target-arr[i]-arr[j];

                       int start=j+1;int end=n-1;
                       while(start<=end){
                           int mid=start+(end-start)/2;
                           if(arr[mid]==find){
                               return true;
                           }
                           else if(arr[mid]<find){
                               start=mid+1;
                           }
                           else{
                               end=mid-1;
                           }
                       }
                   } 
               }
               return false;
    }
};

int main() {
    Solution solver;
    vector<int> arr = {1, 2, 4, 3,6,7};
   
    
    int result = solver.hasTripletSum(arr,10);
    cout << result << endl; // Should return true
    
    return 0;
}
