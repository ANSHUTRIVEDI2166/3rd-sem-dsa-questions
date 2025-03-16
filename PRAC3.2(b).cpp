#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* prev = nullptr;
    ListNode* current = slow;

    while (current != nullptr) {
        ListNode* next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }

    ListNode* left = head;
    ListNode* right = prev;

    while (right != nullptr) {
        if (left->val != right->val) {
            return false;
        }
        left = left->next;
        right = right->next;
    }

    return true;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    // Create the linked list: 1 -> 2 -> 2 -> 1
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(1);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    std::cout << "Linked List: ";
    printList(head);

    bool isPalindromeList = isPalindrome(head);

    if (isPalindromeList) {
        std::cout << "The linked list is a palindrome." << std::endl;
    } else {
        std::cout << "The linked list is not a palindrome." << std::endl;
    }

    // Free the memory
    delete head;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}