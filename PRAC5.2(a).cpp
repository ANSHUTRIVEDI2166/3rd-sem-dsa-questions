#include <iostream>
#include <queue>

class Queue {
private:
    std::queue<int> q;

public:
    void push(int x) {
        q.push(x);
    }

    int pop() {
        if (is_empty()) {
            return -1;
        }
        int front = q.front();
        q.pop();
        return front;
    }

    bool is_empty() {
        return q.empty();
    }
};

void process_queries(int queries[][2], int n, int result[]) {
    Queue queue;
    int index = 0;

    for (int i = 0; i < n; ++i) {
        if (queries[i][0] == 1) {
            queue.push(queries[i][1]);
        } else if (queries[i][0] == 2) {
            int popped = queue.pop();
            if (popped != -1) {
                result[index++] = popped;
            }
        }
    }
}

// Example usage
int main() {
    int queries[][2] = {{1, 2}, {2, 0}, {1, 3}, {2, 0}, {1, 4}, {2, 0}};
    int n = sizeof(queries) / sizeof(queries[0]);
    int result[n];

    process_queries(queries, n, result);

    for (int i = 0; i < n / 2; ++i) {
        std::cout << result[i] << " ";
    }
    // Output: 2 3

    return 0;
}