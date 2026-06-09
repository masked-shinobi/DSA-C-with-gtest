#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n){

    if(n < 2)
        return false;

    for(int i = 2; i * i <= n; i++){

        if(n % i == 0)
            return false;
    }

    return true;
}

long long gcdValue(long long a,
                   long long b){

    while(b != 0){

        long long temp = a % b;

        a = b;
        b = temp;
    }

    return a;
}

long long lcmValue(long long a,
                   long long b){

    long long g =
            gcdValue(a,b);

    return a / g * b;
}

int countPrimes(int n){

    vector<bool> prime(n + 1,true);

    if(n >= 0)
        prime[0] = false;

    if(n >= 1)
        prime[1] = false;

    for(int i = 2;
        i * i <= n;
        i++){

        if(prime[i]){

            for(int j = i * i;
                j <= n;
                j += i){

                prime[j] = false;
            }
        }
    }

    int count = 0;

    for(int i = 2;
        i <= n;
        i++){

        if(prime[i])
            count++;
    }

    return count;
}

int main(){

    long long a,b,m;

    cin >> a >> b >> m;

    cout << "Is Prime = "
         << (isPrime(a) ? "true" : "false")
         << endl;

    long long g =
            gcdValue(a,b);

    cout << "GCD = "
         << g
         << endl;

    cout << "LCM = "
         << lcmValue(a,b)
         << endl;

    cout << "Primes up to a = "
         << countPrimes(a)
         << endl;

    cout << "(a * b) mod m = "
         << (a * b) % m
         << endl;

    cout << "(a + b) mod m = "
         << (a + b) % m
         << endl;

    return 0;
}