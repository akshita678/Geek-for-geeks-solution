#include <iostream>
#include <vector>

using namespace std;



int main() {
    int arr[6]={12,45,389,76,42,31};
    int n=6;
     for(int i=1;i<n;i++){
            
            for(int j=i;j>0;j--){
                if(arr[j]<arr[j-1]){
                    swap(arr[j],arr[j-1]);
                    
                }
                else{
                    break;
                }
                
            }
        }
    for (int k = 0; k<n; k++)
    {
        cout<<arr[k]<<endl;
    }
        
        
        

   
    return 0;
}
