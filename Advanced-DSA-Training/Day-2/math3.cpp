#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long a, d, k;
    cin >> a >> d >> k;

    double A, B, C;
    cin >> A >> B >> C;

    // Sum 1..n
    long long sumN = n * (n + 1) / 2;

    // Sum of squares
    long long sumSquares =
            n * (n + 1) * (2 * n + 1) / 6;

    // Arithmetic series sum
    long long arithmeticSum =
            k * (2 * a + (k - 1) * d) / 2;

    // Discriminant
    double D = B * B - 4 * A * C;

    cout << "Sum 1..n = "
         << sumN << endl;

    cout << "Sum of squares = "
         << sumSquares << endl;

    cout << "Arithmetic Sum = "
         << arithmeticSum << endl;

    cout << "Discriminant = "
         << D << endl;

    // Roots
    if (D < 0)
    {
        cout << "Roots = Complex" << endl;
    }
    else
    {
        double root1 =
                (-B + sqrt(D)) / (2 * A);

        double root2 =
                (-B - sqrt(D)) / (2 * A);

        if (root2 > root1)
            swap(root1, root2);

        cout << fixed << setprecision(2);

        cout << "Roots = "
             << root1 << " "
             << root2 << endl;
    }

    // Vertex x
    double vertexX = -B / (2 * A);

    cout << fixed << setprecision(2);

    cout << "Vertex x = "
         << vertexX << endl;

    // Optimal value
    double optimalValue =
            C - (B * B) / (4 * A);

    cout << "Optimal value = "
         << optimalValue;

    if (A > 0)
        cout << " (minimum)";
    else
        cout << " (maximum)";

    cout << endl;

    return 0;
}