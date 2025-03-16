#include <iostream>
#include <vector>

void fixSwappedElements(std::vector<int>& arr) {
    int first = -1, second = -1;
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            if (first == -1) {
                first = i;
            } else {
                second = i + 1;
            }
        }
    }
    if (second == -1) {
        second = first + 1;
    }
    std::swap(arr[first], arr[second]);
}

void printArray(const std::vector<int>& arr) {
    for (const auto& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;
    std::vector<int> arr(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::cout << "Original array: ";
    printArray(arr);
    fixSwappedElements(arr);
    std::cout << "Fixed array: ";
    printArray(arr);
    return 0;
}