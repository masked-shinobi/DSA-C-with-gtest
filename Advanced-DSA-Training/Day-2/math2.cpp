#include <iostream>
#include <vector>

using namespace std;

// Factorial
long long factorial(int n)
{
    long long fact = 1;

    for(int i = 1; i <= n; i++)
    {
        fact *= i;
    }

    return fact;
}

// nCr
long long nCr(int n, int r)
{
    if(r > n)
        return 0;

    r = min(r, n - r);

    long long res = 1;

    for(int i = 1; i <= r; i++)
    {
        res = res * (n - r + i) / i;
    }

    return res;
}

// Fast Power
long long fastPower(long long base,
                    long long exp,
                    long long mod)
{
    long long result = 1;
    base %= mod;
    while(exp > 0)
    {
        if(exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main()
{
    long long n, r;
    long long base, exp, mod;
    long long p, q;

    cin >> n >> r
        >> base >> exp >> mod
        >> p >> q;

    // Factorial
    cout << "Factorial = "
         << factorial(n)
         << endl;

    // nCr
    cout << "nCr = "
         << nCr(n, r)
         << endl;

    // Pascal Row
    cout << "Pascal Row = ";

    long long current = 1;

    for(int k = 0; k <= n; k++)
    {
        cout << current << " ";

        current = current * (n - k) / (k + 1);
    }

    cout << endl;

    // Fast Power
    cout << "Fast Power = "
         << fastPower(base, exp, mod)
         << endl;

    // Floor
    cout << "Floor = "
         << p / q
         << endl;

    // Ceil
    cout << "Ceil = "
         << (p + q - 1) / q
         << endl;

    // Mod
    cout << "Mod = "
         << p % q
         << endl;

    return 0;
}