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


int main(){

    return 0;
}