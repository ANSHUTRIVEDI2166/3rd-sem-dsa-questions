#include <iostream>
using namespace std;
int BinarySearchMatrix(int a[][4], int row, int column, int search_key)
{
    int high = row - 1, low = 0, index = -1;
    while (low <= high)
    {
        int mid = (high - low) / 2 + low;
        if (search_key >= a[mid][0] && search_key <= a[mid][column - 1])
        {
            index = mid;
            break;
        }
        else if (search_key >= a[mid][0])
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (index == -1)
    {
        cout << "[-1,-1]" << endl;
        return -1;
    }
    low = 0;
    high = column - 1;
    while (low <= high)
    {
        int mid = (high - low) / 2 + low;
        if (a[index][mid] == search_key)
        {
            cout << "Element Found at : " << "[" << index << ", " << mid << "]" << endl;
            return 1;
        }
        else if (a[index][mid] > search_key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int main()
{
    int m, n, key;
    cout << "Enter the number of rows(Column is set to 4): ";
    cin >> m;
    n = 4;
    int matrix[m][4];
    cout << "Enter the Elements : " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << "Enter the search key: ";
    cin >> key;
    int result = BinarySearchMatrix(matrix, m, n, key);
    if (result == -1)
        cout << "Element not found in the 2D array.";
    return 0;
}
