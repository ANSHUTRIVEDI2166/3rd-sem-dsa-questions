#include <iostream>
#include <vector>

class Solution {
public:
    // Function to search for a target value in a 2D matrix.
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        int rowCount = matrix.size();               // Number of rows in the matrix
        int colCount = matrix[0].size();            // Number of columns in the matrix
        int left = 0, right = rowCount * colCount - 1; // Set search range within the flattened matrix
        
        // Binary search
        while (left <= right) {
            int mid = left + (right - left) / 2;   // Find the mid index
            int row = mid / colCount;              // Compute row index from mid
            int col = mid % colCount;              // Compute column index from mid
            
            // Compare the element at [row][col] with target
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                // If the element is less than target, move the left boundary right
                left = mid + 1;
            } else {
                // If the element is greater than target, move the right boundary left
                right = mid - 1;
            }
        }
        
        // Target not found
        return false;
    }
};

int main() {
    Solution sol;
    int rows, cols, target;
    
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;
    
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    
    std::cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    
    std::cout << "Enter the target value: ";
    std::cin >> target;
    
    if (sol.searchMatrix(matrix, target)) {
        std::cout << "Target " << target << " found in the matrix." << std::endl;
    } else {
        std::cout << "Target " << target << " not found in the matrix." << std::endl;
    }
    
    return 0;
}