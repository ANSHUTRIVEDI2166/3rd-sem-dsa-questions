#include <iostream>
using namespace std;

bool canPair(int arr[], int n, int k, int pairs[][2]) {
    if (n % 2 == 1) {
        return false;//ODD PAIRS
    }
    int count = 0;

    int vis[n];
    for (int i = 0; i < n; i++) {
        vis[i] = -1;
    }

    int pairIndex = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((arr[i] + arr[j]) % k == 0 && vis[i] == -1 && vis[j] == -1) {
                vis[i] = 1;
                vis[j] = 1;
                pairs[pairIndex][0] = arr[i];
                pairs[pairIndex][1] = arr[j];
                pairIndex++;
                count++;
            }
        }
    }

    if (count == n / 2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int arr[] = {92, 75, 65, 48, 45, 35};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 10;
    int pairs[n / 2][2];
    bool result = canPair(arr, n, k, pairs);
    cout << (result ? "True" : "False") << endl;

    if (result) {
        cout << "The pairs are:" << endl;
        for (int i = 0; i < n / 2; i++) {
            cout << "(" << pairs[i][0] << ", " << pairs[i][1] << ")" << endl;
        }
    }

    return 0;
}
