#include <iostream>

using namespace std;

void towerOfHanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << from << " to rod " << to << endl;
        return;
    }

    towerOfHanoi(n - 1, from, aux, to);
    cout << "Move disk " << n << " from rod " << from << " to rod " << to << endl;
    towerOfHanoi(n - 1, aux, to, from);
}

int main()   
 {
    int n = 4;
    towerOfHanoi(n,1, 3, 2);
    return 0;
}