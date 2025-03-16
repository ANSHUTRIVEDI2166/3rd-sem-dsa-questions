#include <iostream>
using namespace std;
class Stack
{
    int info;
    Stack *next;
    Stack *top = NULL;


public:
    void push(int n)
    {
        Stack *temp = new Stack;
        temp->info = n;
        temp->next = NULL;
        if (top == NULL)
        {
            top = temp;
            return;
        }
        temp->next = top;
        top = temp;
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        else if (top->next == NULL)
        {
            cout << " popped Element : " << top->info << endl;
            delete top;
            top = NULL;
            return;
        }
        else
        {
            Stack *temp = top;
            top = top->next;
            cout << "Popped Element : " << temp->info << endl;
            delete temp;
        }
    }
    void display()
    {
        Stack *temp = top;
        if (temp == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << "Stack Elements : ";
        while (temp != NULL)
        {
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << endl;
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

