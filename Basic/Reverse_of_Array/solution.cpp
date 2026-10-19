#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 56};
    int p[5];

    for (int i = 0; i < 5; i++) {
        // The inner loop searches for the exact mirror index of i
        for (int j = 4; j >= 0; j--) {
            // A mirror match happens when their indices add up to 4 (e.g., i=0 maps to j=4)
            if (i + j == 4) { 
                p[j] = arr[i];
                break; // Stop the inner loop early once the match is found
            }
        }
    }

    // Print the reversed array
    for (int i = 0; i < 5; i++) {
        cout << p[i] << " ";
    }
 
    return 0;
}

    

