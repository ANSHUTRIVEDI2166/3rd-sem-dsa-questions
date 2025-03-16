#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtFront(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        display();
    }

    void deleteAtLast() {
        if (!head) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        if (current->prev) {
            current->prev->next = nullptr;
        } else {
            head = nullptr;
        }
        delete current;
        display();
    }

    void deleteAll() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        display();
    }

    void display() {
        Node* current = head;
        std::cout << "Linked List: ";
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

// Test the implementation
int main() {
    DoublyLinkedList dll;
    dll.insertAtFront(3);
    dll.insertAtFront(2);
    dll.insertAtFront(1);
    dll.deleteAtLast();
    dll.deleteAll();
    dll.insertAtFront(1);
    dll.insertAtFront(2);
    dll.insertAtFront(3);
    return 0;
}