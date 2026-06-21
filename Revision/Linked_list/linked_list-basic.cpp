#include <iostream>

using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        next = nullptr;
    }
};



void printNodes(ListNode* head){
    ListNode* temp = head;

    while(temp != head){
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main() {
    ListNode* first = new ListNode(10);
    ListNode* second = new ListNode(20);
    ListNode* third = new ListNode(30);

    first->next = second;
    second->next = third;

    ListNode* head = first;

    return 0;
}