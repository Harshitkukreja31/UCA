#include <stdio.h>

void reachend(int i, int j, int m, int n) {
    if (i >= m || j >= n) {
        return;
    }

    printf("Reached at %d %d \n", i, j);


    if (i == m - 1 && j == n - 1) {
        printf("End reached at %d %d\n", i, j);
        return;
    }


    reachend(i, j + 1, m, n);

    reachend(i + 1, j, m, n);
}

int main() {
    int m = 3;
    int n = 3;
    reachend(0, 0, m, n);
    return 0;
}
