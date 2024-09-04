#include <iostream>

using namespace std;

long long modularExponentiation(int x, int y, int p) {
    long long res = 1;

    while (y > 0) {
        if (y & 1) {
            res = (res * x) % p;
        }
        x = (x * x) % p;
        y >>= 1;
    }

    return res;
}

int main() {
    int x = 2, y = 5, p = 13;
    cout << modularExponentiation(x, y, p) << endl;
    return 0;
}