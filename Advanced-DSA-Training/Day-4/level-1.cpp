#include <iostream>
#include <stack>

using namespace std;

// enqueue function
void enqueue(stack<int>& a, int x){
    a.push(x);
}
// dequeue function
void dequeue(stack<int>& a, stack<int>& b){
    if (b.empty()){
        if(a.empty()){
            return;
        }
        //pushing elements to b
        while(!a.empty()){
            int x;
            x = a.top();
            a.pop();
            b.push(x);
        }
    }
    cout << b.top() << " ";
    b.pop();
}


int main(){
    //create stack
    stack<int> a;
    stack<int> b;
    // input
    int n;
    cin >> n;
    cout << "Served :";
    for(int i = 0; i < n; i++){
        string operation;
        cin >> operation;
        if(operation == "ENQUEUE"){
            int x;
            cin >> x;
            enqueue(a, x);
        }else if(operation == "DEQUEUE"){

            dequeue(a, b);
        }else{
            cout<<"something wrong in the input";
        }
    }
    cout << "\n";
    cout << "Pending :" << a.size() + b.size();
    return 0;
}