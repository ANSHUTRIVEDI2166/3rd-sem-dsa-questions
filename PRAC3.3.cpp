#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) {
        return list2;
    }
    if (list2 == nullptr) {
        return list1;
    }
    ListNode* mergedHead;
    if (list1->val <= list2->val) {
        mergedHead = list1;
        mergedHead->next = mergeTwoLists(list1->next, list2);
    } else {
        mergedHead = list2;
        mergedHead->next = mergeTwoLists(list1, list2->next);
    }
    return mergedHead;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create two sorted linked lists
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    std::cout << " List1: ";
    printList(list1);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    std::cout << " List2: ";
    printList(list2);
    // Merge the two lists
    ListNode* mergedList = mergeTwoLists(list1, list2);

    
    
    std::cout << "Merged List: ";
    printList(mergedList);

    // Clean up memory
    while (mergedList != nullptr) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}