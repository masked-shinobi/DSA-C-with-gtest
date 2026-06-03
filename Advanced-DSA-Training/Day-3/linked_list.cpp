#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int value;
    ListNode* next;
    ListNode (int x){
        value = x;
        next = nullptr;
    }
};

ListNode* insertstart(ListNode* head, int value){
    ListNode* newNode = new ListNode(value);
    newNode -> next = head;
    return newNode;
}

ListNode* insertend(ListNode* head, int value){
    ListNode* newNode = new ListNode(value);
    if(head == nullptr) {
        return newNode;
    }
    ListNode* temp = head;

    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = nullptr;

    return head;
}

ListNode* insertmid(ListNode* head, int value, int pos){
    if(pos == 1){
        return insertstart(head, value);
    }

    ListNode* temp = head;

    for(int i = 0; i < pos - 1 && temp != nullptr; i++){
        temp = temp->next;
    }

    if(temp == nullptr){
        cout<<"Invalid position";
        return head;
    }

    ListNode* newNode = new ListNode(value);
    newNode->next = temp->next;
    temp->next =newNode;

    return head;
}


void printNodes(ListNode* head){
    while(head != nullptr){
        cout << head->value;
        head = head->next;
    }
    cout<< " NULL \n";
}

ListNode* deletestart(ListNode* head){
    if(head == nullptr){
        return nullptr;
    }

    ListNode* temp = head;
    head = head->next;
    delete temp;
    return head;

}

ListNode* deleteend(ListNode* head){
    if(head == nullptr){
        return nullptr;
    }
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    ListNode* temp = head;

    while(temp->next->next != nullptr){
        temp = temp->next;
    }

    delete temp->next;
    temp -> next =nullptr; // why is this line if we already deleted temp->next

    return head;
}

ListNode* deletemid(ListNode* head, int pos){
    if (head == nullptr)
        return nullptr;
    if (pos == 1)
        return deletestart(head);
    // move to position pos - 1
    ListNode* temp = head;
    for(int i = 1;i < pos - 1 && temp->next != nullptr; i++){
        temp = temp->next;
    }

    //check position validity
    if(temp->next == nullptr){
        cout<<"InvalidCode";
        return head;
    }

    ListNode* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;

    return head;
}
int main() {
    ListNode* head = nullptr;

    cout << "Insert at start:\n";
    head = insertstart(head, 30);
    head = insertstart(head, 20);
    head = insertstart(head, 10);
    printNodes(head);   // 10 20 30 NULL

    cout << "\nInsert at end:\n";
    head = insertend(head, 40);
    head = insertend(head, 50);
    printNodes(head);   // 10 20 30 40 50 NULL

    cout << "\nInsert in middle (25 at position 3):\n";
    head = insertmid(head, 25, 3);
    printNodes(head);   // 10 20 25 30 40 50 NULL

    cout << "\nDelete start:\n";
    head = deletestart(head);
    printNodes(head);   // 20 25 30 40 50 NULL

    cout << "\nDelete end:\n";
    head = deleteend(head);
    printNodes(head);   // 20 25 30 40 NULL

    cout << "\nDelete middle (position 2):\n";
    head = deletemid(head, 2);
    printNodes(head);   // 20 30 40 NULL

    // Free remaining nodes
    while(head != nullptr) {
        head = deletestart(head);
    }

    return 0;
}