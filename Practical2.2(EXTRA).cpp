#include<iostream>
#include<algorithm>
using namespace std;
void sortByOneSwap(int arr[], int n)
{
	for (int i = n-1; i > 0; i--)
	{
		if (arr[i] < arr[i-1])
		{
			int j = i-1;
			while (j>=0 && arr[i] < arr[j])
				j--;
			swap(arr[i], arr[j+1]);
			break;
		}
	}
}
void printArray(int arr[], int n)
{
	int i;
	for (i=0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int main()
{
	int arr[] = {10, 30, 20, 40, 50, 60, 70};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Given array is \n";
	printArray(arr, n);
	sortByOneSwap(arr, n);
	cout << "Sorted array is \n";
	printArray(arr, n);
	return 0;
}