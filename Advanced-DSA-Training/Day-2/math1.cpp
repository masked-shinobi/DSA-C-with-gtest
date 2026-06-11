#include <iostream>
#include <vector>

using namespace std;

// Prime check
bool isPrime(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

// GCD
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

// Count primes up to n using sieve
int countPrimes(int n)
{
    vector<bool> prime(n + 1, true);

    if (n >= 0) prime[0] = false;
    if (n >= 1) prime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }

    int count = 0;

    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
            count++;
    }

    return count;
}

int main()
{
    long long a, b, m;
    cin >> a >> b >> m;

    bool prime = isPrime(a);

    long long g = gcd(a, b);

    long long lcm = (a / g) * b;

    int primeCount = countPrimes(a);

    cout << "Is Prime = "
         << (prime ? "true" : "false") << endl;

    cout << "GCD = " << g << endl;

    cout << "LCM = " << lcm << endl;

    cout << "Primes up to a = "
         << primeCount << endl;

    cout << "(a * b) mod m = "
         << (a * b) % m << endl;

    cout << "(a + b) mod m = "
         << (a + b) % m << endl;

    return 0;
}