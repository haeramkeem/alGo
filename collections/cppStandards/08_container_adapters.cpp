#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {

    /**
     * Container adapters are wrappers of standard containers.
     * They limit some features of containers for specific reasons.
     * There are 3 container adapters.
     *     1. Stack
     *     2. Queue
     *     3. Priority queue
     * 
     * Stack & queue uses deque and priority queue uses vector for default container.
     * 
     * All methods of stack & queue takes, O(1).
     *     and 
     */

    // Unlike any other containers, stack only supports declaration.
    stack<int> stkTest;

    // These are some examples of stack's methods.
    stkTest.push(0); // result is {0}
    stkTest.push(1); // result is {0, 1}
    stkTest.pop(); // result is {0}
    stkTest.top(); // result is 0
    stkTest.empty(); // result is 0(false)
    stkTest.size(); // result is 1

    // Like stack, queue only supports declaration.
    queue<int> qTest;

    // These are some examples of stack's methods.
    qTest.push(0); // result is {0}
    qTest.push(1); // result is {0, 1}
    qTest.push(2); // result is {0, 1, 2}
    qTest.pop(); // result is {1, 2}
    qTest.front(); // result is 1
    qTest.back(); // result is 2
    qTest.empty(); // result is 0(false)
    qTest.size(); // result is 2

    // Priority queue is defined in queue.
    //     so if you want to use priority queue, you must #include <queue>.
    // Like stack or queue, priority queue only supports declaration.
    // Priority queue uses std::less for compare type as default, so it operates maxheap.
    //    to operate priority queue minheap, you must add std::greater compare type to template.
    priority_queue<int> pqMax; // Declare maxheap priority queue.
    priority_queue<int, vector<int>, less<int>> pqMax1; // Same as statement above.
    priority_queue<int, vector<int>, greater<int>> pqMin; // Declare minheap priority queue.

    // .push() and .pop() method takes O(log n).
    pqMax.push(2);
    pqMax.push(3);
    pqMax.push(1);
    pqMax.pop();
    pqMin.push(3);
    pqMin.push(1);

    // .top() method returns minimum or maximum value of queue.
    // This method takes O(1).
    pqMax.top(); // returns Maximum value. result is 1.
    pqMin.top(); // returns Minimum value. result is 3.

    return 0;
}