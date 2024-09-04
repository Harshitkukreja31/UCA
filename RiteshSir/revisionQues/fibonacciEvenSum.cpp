#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cout << "Enter the upper limit: ";
    cin >> n;

    int a = 1, b = 1, c = 2;
    int sum = 0;

    // Every third number in the Fibonacci series is even
    while (c <= n) {
        sum += c;
        a = b + c;
        b = c + a;
        c = a + b;
    }

    cout << "The sum of even Fibonacci numbers up to " << n << " is: " << sum << endl;

    return 0;
}