#include <iostream>
#include <vector>

using namespace std;

bool primenumber(int n){
    bool isprime = true;
    if (n <= 1){
        isprime = false;
        return isprime;
    }

    for ( int i = 2; i*i <= n; i++){
        if(n % i == 0){
            isprime = false;
            break;
        }
    }
    return isprime;
}

int main() {
    int k;
    cin>>k;

    cout << primenumber(k);

    return 0;
}