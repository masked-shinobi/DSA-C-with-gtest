#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Sum 1 + 2 + ... + n
long long sumN(long long n) {
    return n * (n + 1) / 2;
}

// Sum 1² + 2² + ... + n²
long long sumSquares(long long n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

// Arithmetic Progression Sum
long long arithmeticSum(long long a, long long d, long long k) {
    return k * (2 * a + (k - 1) * d) / 2;
}

// Discriminant
long long discriminant(long long A, long long B, long long C) {
    return B * B - 4 * A * C;
}

// Print roots
void findRoots(long long A, long long B, long long C) {
    long long D = discriminant(A, B, C);

    if (D < 0) {
        cout << "Roots = Complex" << endl;
        return;
    }

    double root1 = (-B + sqrt(D)) / (2.0 * A);
    double root2 = (-B - sqrt(D)) / (2.0 * A);

    if (root2 > root1)
        swap(root1, root2);

    cout << fixed << setprecision(2);
    cout << "Roots = " << root1 << " " << root2 << endl;
}

// Vertex x-coordinate
double vertexX(long long A, long long B) {
    return -B / (2.0 * A);
}

// Optimal value at vertex
double optimalValue(long long A, long long B, long long C) {
    return C - (1.0 * B * B) / (4.0 * A);
}

int main() {
    long long n;
    cin >> n;

    long long a, d, k;
    cin >> a >> d >> k;

    long long A, B, C;
    cin >> A >> B >> C;

    cout << "Sum 1..n = " << sumN(n) << endl;

    cout << "Sum of squares = "
         << sumSquares(n) << endl;

    cout << "Arithmetic Sum = "
         << arithmeticSum(a, d, k) << endl;

    cout << "Discriminant = "
         << discriminant(A, B, C) << endl;

    findRoots(A, B, C);

    cout << fixed << setprecision(2);

    cout << "Vertex x = "
         << vertexX(A, B) << endl;

    double opt = optimalValue(A, B, C);

    if (A > 0)
        cout << "Optimal value = "
             << opt << " (minimum)" << endl;
    else
        cout << "Optimal value = "
             << opt << " (maximum)" << endl;

    return 0;
}