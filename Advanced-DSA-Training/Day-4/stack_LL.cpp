#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;

    Node(int x){
        value = x;
        next = nullptr;
    }
};

Node* push(Node* top, int value){

    Node* newNode = new Node(value);

    newNode->next = top;

    return newNode;
}

Node* pop(Node* top){

    if(top == nullptr){
        return nullptr;
    }

    Node* temp = top;

    top = top->next;

    delete temp;

    return top;
}

int peek(Node* top){

    if(top == nullptr){
        return -1;
    }

    return top->value;
}

void print(Node* top){

    while(top != nullptr){
        cout<<top->value<<" ";
        top = top->next;
    }

    cout<<"\n";
}

int main() {
    Node* top = nullptr;

    top = push(top,10);
    top = push(top,20);
    top = push(top,30);

    print(top);

    top = pop(top);

    print(top);

    cout<<peek(top);
    return 0;
}
