#include <iostream>
#include <vector>

using namespace std;

void enqueue(vector<int>& queue, int value){
    queue.push_back(value);
}

void dequeue(vector<int>& queue){

    if(queue.empty()){
        cout<<"Queue Empty\n";
        return;
    }

    queue.erase(queue.begin());
}

int front(vector<int>& queue){

    if(queue.empty()){
        return -1;
    }

    return queue[0];
}

void print(vector<int>& queue){

    for(int x : queue){
        cout<<x<<" ";
    }

    cout<<"\n";
}

int main() {
    vector<int> queue;

    enqueue(queue,10);
    enqueue(queue,20);
    enqueue(queue,30);

    print(queue);

    dequeue(queue);

    print(queue);

    cout<<front(queue);
    return 0;
}
