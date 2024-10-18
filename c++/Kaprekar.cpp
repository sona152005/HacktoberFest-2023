// modified this code in short
#include <iostream>
using namespace std;

bool isKaprekar(int number, int base) {
    if (number < 0 || base <= 1) return false;

    long long squared = static_cast<long long>(number) * number;
    long long divisor = 1;

    while (squared / divisor >= base) divisor *= base;

    while (divisor > 0) {
        long long left = squared / divisor;
        long long right = squared % divisor;
        if (left + right == number && right > 0) return true;
        divisor /= base;
    }
    return false;
}

int main() {
    int number, base;
    cout << "Enter a number and base: ";
    cin >> number >> base;

    cout << number << (isKaprekar(number, base) ? " is" : " is not") 
         << " a Kaprekar number in base " << base << endl;

    return 0;
}
