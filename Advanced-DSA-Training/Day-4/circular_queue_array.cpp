#include <iostream>
#include <vector>

using namespace std;

int front = -1;
int rear = -1;
int size = 5;

bool isEmpty(){
    return front == -1;
}

bool isFull(){
    return (rear + 1) % size == front;
}

void enqueue(vector<int>& q, int value){

    if(isFull()){
        cout<<"Queue Full\n";
        return;
    }

    if(isEmpty()){
        front = rear = 0;
    }
    else{
        rear = (rear + 1) % size;
    }

    q[rear] = value;
}

void dequeue(){

    if(isEmpty()){
        cout<<"Queue Empty\n";
        return;
    }

    if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front + 1) % size;
    }
}

int getFront(vector<int>& q){

    if(isEmpty()){
        return -1;
    }

    return q[front];
}

void print(vector<int>& q){

    if(isEmpty()){
        return;
    }

    int i = front;

    while(true){

        cout<<q[i]<<" ";

        if(i == rear){
            break;
        }

        i = (i + 1) % size;
    }

    cout<<"\n";
}

int main(){

    vector<int> q(size);

    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);

    print(q);

    dequeue();
    dequeue();

    print(q);

    enqueue(q,40);
    enqueue(q,50);
    enqueue(q,60);

    print(q);

    return 0;
}