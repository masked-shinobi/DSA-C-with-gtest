#include <iostream>
#include <vector>

using namespace std;

void push(vector<int>& stack, int value){
    stack.push_back(value);
}

void pop(vector<int>& stack){
    if(stack.empty()){
        cout<<"Stack Empty\n";
        return;
    }

    stack.pop_back();
}

int top(vector<int>& stack){
    if(stack.empty()){
        return -1;
    }

    return stack.back();
}

void print(vector<int>& stack){
    for(int x : stack){
        cout<<x<<" ";
    }
    cout<<"\n";
}

int main(){

    vector<int> stack;

    push(stack,10);
    push(stack,20);
    push(stack,30);

    print(stack);

    pop(stack);

    print(stack);

    cout<<top(stack);

}