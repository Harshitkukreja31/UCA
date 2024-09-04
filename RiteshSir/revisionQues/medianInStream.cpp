#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
public:
    MedianFinder() {}

    void addNum(int num) {
        if (left.size() == right.size()) {
            if (right.size() > 0 && num > right.top()) {
                left.push(right.top());
                right.pop();
                right.push(num);
            } else {
                left.push(num);
            }
        } else {
            if (num < left.top()) {
                right.push(left.top());
                left.pop();
                left.push(num);
            } else {
                right.push(num);
            }
        }
    }

    double findMedian() {
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        } else {
            return left.top();
        }
    }

private:
    priority_queue<int, vector<int>, greater<int>> right;
    priority_queue<int> left;
};

int main() {
    MedianFinder obj;
    obj.addNum(1);
    obj.addNum(2);
    cout << obj.findMedian() << endl;
    obj.addNum(3);
    cout << obj.findMedian() << endl; 
    return 0;
}