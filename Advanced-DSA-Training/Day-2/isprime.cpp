#include <iostream>
#include <vector>

using namespace std;

bool primenumber(int x){
    int count = 0;
    bool isprime = true;
    for(int i = 0; i < x+1; i++){
        if(x%i){
            count++;
        }
    }
    if(count>2){
        isprime = false;
    }

    return isprime;
}

int main(){
    int k;
    bool final;
    cin >> k;

    final = primenumber(k);

    cout<<final;
    return 0;
}