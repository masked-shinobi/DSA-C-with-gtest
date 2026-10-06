#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int a;
    Node* next;
    Node(int x){
        a = x;
        next = nullptr;
    }
};

int main() {
    int x;
    cin >> x;
    // circular linked list creation
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i = 0; i < x; i++){
        int a;
        cin >> a;

        Node* newNode = new Node(a);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }
        tail->next  = head;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast->next != head && fast->next->next != head){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    // even handling part
    if(fast->next->next == head)
    {
        fast = fast->next;
    }

    Node* head2 = slow->next;
    slow->next = head;
    fast->next = head2;

    cout << "First Half:";
    Node* tracker1 = head;

    do{
        cout << tracker1->a << " ";
        tracker1 = tracker1->next;
    }
    while(tracker1 != head);
    cout << endl;

    Node* tracker2 = head2;
    cout << "Second Half:";
    do{
        cout << tracker2->a << " ";
        tracker2 = tracker2->next;
    }
    while(tracker2 != head2);
    cout << endl;

    bool circular1 = (slow->next == head);
    bool circular2 = (fast->next == head2);

    if(circular1 && circular2){
        cout << "Both Circular: Yes";
    }else{
        cout << "Both Circular: No";
    }

    return 0;
}