#include <iostream>
#include <vector>

using namespace std;

struct Node {
    char name;
    Node* next;
    Node(char x){
        name = x;
        next = nullptr;
    }
};

void caller(Node*& curr, vector<char>& record){
    record.push_back(curr->name);
    curr = curr->next;
}

void rotation(Node*& curr, int k){
    for(int i = 0; i < k; i++){
        curr = curr->next;
    }
}

int main() {

    //input
    int n;
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;
    vector<char> record;
    //build circular linked list
    for(int i = 0; i < n; i++){
        char input;
        cin >> input;

        Node* newNode = new Node(input);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    tail->next = head;

    Node* curr = head;

    int c;
    cin >> c;

    for(int i = 0; i < c; i++){
        string function;
        cin >> function;
        if(function == "CALL"){
            caller(curr, record);
        }else if(function == "ROTATE"){
            int x;
            cin >> x;
            rotation(curr, x);
        }else{
            cout << "Invalid Input function";
        }
    }
    cout << "Called:";
    for(char x : record){
        cout << x << " ";
    }
    cout << endl;

    cout << "Current:" << curr->name;

    return 0;
}