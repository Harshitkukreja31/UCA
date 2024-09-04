#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int minimizeMaxLoad(vector<int>& population, int m) {
    priority_queue<pair<double, double>> pq;
    
    for (int i : population) {
        pq.push({(double)i, 1.0});
        m--;
    }
    
    while (m-- > 0) {
        auto [max_load, count] = pq.top(); pq.pop();
        pq.push({max_load / ++count, count});
    }
    
    return (int)pq.top().first;
}

int main() {
    cout << minimizeMaxLoad({100, 50, 200}, 4) << endl; // Output: 100
    
    return 0;
}