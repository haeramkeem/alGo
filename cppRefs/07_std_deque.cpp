#include <iostream>
#include <deque>

using namespace std;

int main() {

    /**
     * Deque is the container that supports these 3 features :
     *     1. Supports .push_back(), .push_front(), .pop_back(), .pop_front() methods with O(1).
     *     2. Supports random-access to elements with O(1).
     *     3. If length of deque is n, insertion or deletation of one element takes O(n/2).
     * 
     * While vectors can only be extened in one direction, deques can be extended in both directions.
     *     it allows deque to push or pop element with O(1).
     *     it also allows deque to move up to n/2 elements instead of n when inserting or deleting.
     * 
     * Deque doesn't use a single chunk memory to contain. instead, it uses fixed-size multiple chunks.
     *     because length of chunk is fixed, deque knows which chunk contains element of given index.
     *     (divide index by length of chunk)
     */

    // Declare & Allocate deque just like vector.
    deque<int> deqTest;
    deque<int> deqTest1 = {1, 2, 3, 4, 5};
    deque<int> deqTest2(5);
    deque<int> deqTest3(5, 3);

    // Push, pop, erase elements. usage is same as any other containers.
    deqTest.push_back(2); // result is {2}
    deqTest.push_front(1); // result is {1, 2}
    deqTest1.pop_back(); // result is {1, 2, 3, 4}
    deqTest1.pop_front(); // result is {2, 3, 4}
    deqTest1.erase(deqTest1.begin() + 1); // result is {2, 4}
    deqTest1.erase(deqTest1.begin() + 1, deqTest1.end()); // result is {2}

    return 0;
}