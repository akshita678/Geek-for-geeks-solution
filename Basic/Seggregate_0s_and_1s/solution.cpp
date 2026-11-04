#include <iostream>
#include <vector>

using namespace std;


class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // can also be attempted with  insertion sort --> brute force  
        // Better approach---> easiest to think 
        //sort(arr.begin(),arr.end()); 
        
        // Another approach 
        // Counter approach:
        int count1=0;
        int count0=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                count0++;
            }
            else{
                count1++;}
                
        }
        for(int i=0;i<count0;i++){
            arr[i]=0;
        }
        for(int i=count0;i<arr.size();i++){
            arr[i]=1;
        }
        
        
        
    }
};
int main() {
    Solution solver;
    vector<int>arr={1,0,0,1,0,1,0};
   
    
    
     solver.segregate0and1(arr);
  for (int i = 0; i < arr.size(); i++)
     {
        cout<<arr[i]<<endl;
     }   // to finally print result 

    
    return 0;
}
