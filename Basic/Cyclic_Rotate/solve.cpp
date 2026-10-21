#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void rotate(vector<int> &arr) {
        int n = arr.size();
       
        
        int temp = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            arr[i + 1] = arr[i];
        }
        arr[0] = temp;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    // Run your rotation code
    sol.rotate(arr);

    cout << "Rotated array:  ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}



   
