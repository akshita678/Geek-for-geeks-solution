#include <iostream>
using namespace std;
#include <iostream>

// The function to find the second largest distinct element
int getSecondLargest(int *arr, int n) {
    // Step 1: Find the absolute maximum element in the array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int ans = -1; // Default value if no distinct second largest exists

    // Step 2: Count down from max-1 to find the largest existing element below max
    for (int j = max - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == j) {
                ans = j;
                return ans; // Return immediately once found
            }
        }
    }

    // Step 3: The Safety Net Return
    return ans; 
}

// The main function where the program starts executing
int main() {
    // A simplified test array of positive integers
    int myArray[] = {12, 35, 1, 10, 34, 1};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    // Call the function and grab the result
    int result = getSecondLargest(myArray, size);

    // Print the output to the console
    std::cout << "The second largest distinct element is: " << result << std::endl;

    return 0;
}


