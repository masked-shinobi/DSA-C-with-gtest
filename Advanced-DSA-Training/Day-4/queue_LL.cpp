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

void enqueue(Node*& front, Node*& rear, int value){

    Node* newNode = new Node(value);

    // first node
    if(front == nullptr){
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

void dequeue(Node*& front, Node*& rear){

    if(front == nullptr){
        cout<<"Queue Empty\n";
        return;
    }

    Node* temp = front;
    front = front->next;

    delete temp;

    // queue became empty
    if(front == nullptr){
        rear = nullptr;
    }
}

int getFront(Node* front){

    if(front == nullptr){
        return -1;
    }

    return front->value;
}

void printQueue(Node* front){

    while(front != nullptr){
        cout<<front->value<<" ";
        front = front->next;
    }

    cout<<"\n";
}

int main(){

    Node* front = nullptr;
    Node* rear = nullptr;

    cout<<"Enqueue:\n";

    enqueue(front,rear,10);
    enqueue(front,rear,20);
    enqueue(front,rear,30);

    printQueue(front);

    cout<<"\nFront Element: ";
    cout<<getFront(front);

    cout<<"\n\nDequeue:\n";

    dequeue(front,rear);

    printQueue(front);

    cout<<"\nFront Element: ";
    cout<<getFront(front);

    // free memory
    while(front != nullptr){
        dequeue(front,rear);
    }

    return 0;
}