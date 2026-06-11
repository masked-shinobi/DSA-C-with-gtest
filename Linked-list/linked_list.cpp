


//
// Created by baska on 10-06-2026.
//

ListNode* insertatstart(ListNode* head, int value){
    ListNode* newNode = new ListNode(value);
    newNode->next = head;
    return newNode;
}

istNode* deleteatstart(ListNode* head){
    ListNode* deleter = head;
    head = head->next;
    delete deleter;
    return head;
}

