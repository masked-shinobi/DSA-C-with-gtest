#include <iostream>

using namespace std;

int main() {
    // Right pyramid
    int n = 3;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i + 1; j++){
            cout<<"*";
        }
        cout << endl;
    }

    // Left pyramid
        // 2 space and 1 star

#include <iostream>
    using namespace std;

    int main() {
        int n = 5;

        for(int i = 1; i <= n; i++) {

            // print spaces
            for(int j = 1; j <= n - i; j++) {
                cout << " ";
            }

            // print stars
            for(int j = 1; j <= i; j++) {
                cout << "*";
            }

            cout << endl;
        }

        return 0;
    }
    // triangle pyramid
#include <iostream>
    using namespace std;

    int main() {
        int n = 5;

        for(int i = 1; i <= n; i++) {

            // spaces
            for(int j = 1; j <= n - i; j++) {
                cout << " ";
            }

            // stars
            for(int j = 1; j <= 2*i - 1; j++) {
                cout << "*";
            }

            cout << endl;
        }

        return 0;
    }


    return 0;
}