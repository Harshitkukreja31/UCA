#include <iostream>
#include <vector>
using namespace std;

bool isValid(int x, int y, int n, int m) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return false;
    }
    return true;
}
int collectCherries(int x, int y, int n, int m, vector<vector<char>>& grid) {
    if (x == n - 1 && y == m - 1) {
        return grid[x][y] - '0';
    }
    bool choice1valid = isValid(x + 1, y, n, m);
    bool choice2valid = isValid(x, y + 1, n, m);
    if (choice1valid && choice2valid) {
        int calc1 = collectCherries(x + 1, y, n, m, grid);
        int calc2 = collectCherries(x, y + 1, n, m, grid);
        return (grid[x][y] - '0') + max(calc1, calc2);
    }
    if (choice1valid) {
        int calc1 = collectCherries(x + 1, y, n, m, grid);
        return (grid[x][y] - '0') + calc1;
    }
    int calc2 = collectCherries(x, y + 1, n, m, grid);
    return (grid[x][y] - '0') + calc2;
}
int main() {
    vector<vector<char>> grid = {
            {'1', '1', '1', '1'},
            {'1', '1', '1', '1'},
            {'1', '1', '1', '1'},
            {'0', '0', '0', '0'}
    };
    int n = grid.size();
    int m = grid[0].size();
    // cout<<n<<" "<<m;
    int ans = collectCherries(0, 0, n, m, grid);
    cout << "MinCherries: " << ans << endl;
}
