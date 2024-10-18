// modified this code in short
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter an odd number of rows: ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "Please enter an odd number." << endl;
        return 1;
    }

    for (int i = 1; i <= n; i += 2) {
        cout << string((n - i) / 2, ' ') << string(i, '*') << endl;
    }
    for (int i = n - 2; i >= 1; i -= 2) {
        cout << string((n - i) / 2, ' ') << string(i, '*') << endl;
    }

    return 0;
}
