#include <iostream>
#include <vector>

using namespace std;

// Your sorting function
void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[index]) {
                index = j;
            }
        }
        swap(arr[i], arr[index]);
    }
}

int main() {
    // 1. Create an unsorted array
    vector<int> arr = {64, 25, 12, 22, 11};

    // 2. Run the sorting function
    selectionSort(arr);

    // 3. Print the sorted results
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
