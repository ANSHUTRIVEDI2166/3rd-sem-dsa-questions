#include <iostream>
using namespace std;

bool canPair(int arr[], int n, int k) {
    if (n % 2 == 1) {
        return false;
    }
    int count = 0;

    int vis[n];
    for (int i = 0; i < n; i++) {
        vis[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((arr[i] + arr[j]) % k == 0 && vis[i] == -1 && vis[j] == -1) {
                count++;
                vis[i] = 1;
                vis[j] = 1;
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
    bool result = canPair(arr, n, k);
    cout << (result ? "True" : "False") << endl;
    return 0;
}
