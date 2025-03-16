#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped in the inner loop, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}
int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    bubble_sort(arr);

    cout << "Sorted array is: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << std::endl;

    return 0;
}