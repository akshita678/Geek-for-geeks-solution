#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int lastIndex(string &s) {
        int ans = -1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1') {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution solver;
    string s="00101";
   
    
    
    int result = solver.lastIndex(s);
    cout << "Last index " << result << endl; // Should print 4
    
    return 0;
}