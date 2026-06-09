#include <iostream>
using namespace std;

long long factorial(int n){
    long long fact = 1;

    for(int i = 1; i <= n; i++)
        fact *= i;

    return fact;
}

long long nCr(int n, int r){

    long long res = 1;

    for(int i = 1; i <= r; i++){
        res = res * (n - r + i) / i;
    }

    return res;
}

void pascalRow(int n){

    long long val = 1;

    for(int k = 0; k <= n; k++){

        cout << val;

        if(k < n)
            cout << " ";

        val = val * (n - k) / (k + 1);
    }

    cout << endl;
}

long long fastPower(long long base,
                    long long exp,
                    long long mod){

    long long ans = 1;

    base %= mod;

    while(exp > 0){

        if(exp & 1)
            ans = (ans * base) % mod;

        base = (base * base) % mod;

        exp /= 2;
    }

    return ans;
}

int main(){

    long long n,r;
    long long base,exp,mod;
    long long p,q;

    cin >> n >> r
        >> base >> exp >> mod
        >> p >> q;

    cout << "Factorial = "
         << factorial(n)
         << endl;

    cout << "nCr = "
         << nCr(n,r)
         << endl;

    cout << "Pascal Row = ";
    pascalRow(n);

    cout << "Fast Power = "
         << fastPower(base,exp,mod)
         << endl;

    cout << "Floor = "
         << p/q
         << endl;

    cout << "Ceil = "
         << (p+q-1)/q
         << endl;

    cout << "Mod = "
         << p%q
         << endl;

    return 0;
}