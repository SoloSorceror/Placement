#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Enqueue
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // 10
    cout << "Rear element: " << q.back() << endl;   // 30

    // Dequeue
    q.pop(); // removes 10

    cout << "After pop, front: " << q.front() << endl; // 20
    cout << "Size: " << q.size() << endl;

    // Check if empty
    if (q.empty())
        cout << "Queue is empty\n";
    else
        cout << "Queue is not empty\n";

    return 0;
}
