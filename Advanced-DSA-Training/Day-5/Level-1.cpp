#include <deque>
#include <iostream>
#include <vector>

using namespace std;

void addregular(deque<int>& dq, int id){
    dq.push_back(id);
}

void vip(deque<int>& dq, int id){
    dq.push_front(id);
}

void board(deque<int>& dq, vector<int>& boarders){
    if(dq.empty()){
        cout << "queue empty";
        return;
    }
    int c = dq.front();
    dq.pop_front();
    boarders.push_back(c);
}

void quit(deque<int>& dq, vector<int>& quitters){
    if(dq.empty()){
        cout << "queue empty";
        return;
    }
    int c = dq.back();
    dq.pop_back();
    quitters.push_back(c);
}

int main() {

    //input
    int n;
    cin >> n;

    // storage
    vector<int> boarders;
    vector<int> quitters;

    deque<int> dq;

    for(int i = 0; i < n; i++){
        string function;
        cin >> function;
        if(function == "REGULAR"){
            int id;
            cin >> id;
            addregular(dq, id);
        }else if(function == "VIP"){
            int id;
            cin >> id;
            vip(dq, id);
        }else if(function == "BOARD"){
            board(dq, boarders);
        }else if(function == "QUIT"){
            quit(dq, quitters);
        }else{
            cout << "Invalid Input has been provided";
        }
    }
    //print boarders and quitters
    cout<< "Boarded: ";
    for(int num : boarders){
        cout << num << " ";
    }
    cout << endl;
    cout << "Quit: ";
    for(int num : quitters){
        cout << num << " ";
    }
    cout << endl;
    // printing remaining in deque
    cout << "Waiting: ";
    for(int i: dq){
        cout << i << " ";
    }

    return 0;
}