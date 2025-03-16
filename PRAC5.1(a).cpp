#include <iostream>
using namespace std;


class Stack
{
    int a[5];
    int top = -1;


public:
    void push(int n)
    {
        if (top == 5 - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        a[top] = n;
    }
    void pop()
    {
        if (top == -1)
            cout << "Stack Underflow" << endl;
        else
        {
            cout << "Popped Element : " << a[top] << endl;
            top--;
        }
    }
    void display()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << "Stack Elements are: " << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << "|" << a[i] << "|" << endl;
        }
    }
};
int main()
{
    Stack s;
    s.push(2);
    s.push(3);
    s.pop();
    s.push(4);
    s.pop();
    s.display();
    return 0;
}
