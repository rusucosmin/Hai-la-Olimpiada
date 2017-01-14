#include <queue>
#include <iostream>

using namespace std;

int main() {
    priority_queue <int, vector<int>, greater<int>> pq; // min heap
    priority_queue <int> mh; // min heap

    pq.push(15);
    pq.push(10);
    pq.push(25);
    pq.push(20);
    pq.push(-1);

    mh.push(15);
    mh.push(10);
    mh.push(25);
    mh.push(20);
    mh.push(-1);
    cout << "minimul ar trebui sa fie: " << pq.top();
    cout << "\nmaximul ar trebui sa fie: " << mh.top();
}
