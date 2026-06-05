#include <iostream>
#include <vector>
using namespace std;


void push(vector<int>& a, vector<int>&   b, int value){
    a.push_back(value);
    if(b.empty()){
        b.push_back(value);

    }
    else{
        int small_value = min(b[b.size() - 1],value);
        b.push_back(small_value);

    }

}

void pop(vector<int>& a,vector<int>& b){
    if(a.empty() && b.empty()){
        cout << "Both stack is empty" << " ";
        return;
    }
    a.pop_back();
    b.pop_back();

}


int main() {
    // your code goes here

    vector<int> stack;
    vector<int> min_stack;


    int num_input;
    cin >> num_input;

    for(int i = 0; i < num_input; i++){
        string operation;
        cin >> operation;

        if (operation == "PUSH"){
            int x;
            cin >> x;
            push(stack,min_stack,x);
        }

        else if(operation == "POP"){
            pop(stack,min_stack);
        }

        else if(operation == "MIN"){
            if(min_stack.empty()){
                cout << "MIN: " << 0;
            }
            else{
                cout << "MIN: " << min_stack[min_stack.size() - 1];
                cout << endl;
            }

        }

    }

    int length_stack = min_stack.size();
    cout << "SIZE: " << length_stack;
    return 0;
}