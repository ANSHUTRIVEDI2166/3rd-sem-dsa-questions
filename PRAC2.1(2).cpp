#include <iostream>
#include <vector>
using namespace std;
void selection_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    selection_sort(arr);

    cout << "Sorted array is: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}