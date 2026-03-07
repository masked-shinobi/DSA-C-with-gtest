#include <iostream>
#include <vector>

using namespace std;

int main(){
    int a = 0;
    int b = 1;

    int k;
    cin >> k;

    for(int i = 0; i < k; i++){
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    return 0;
}