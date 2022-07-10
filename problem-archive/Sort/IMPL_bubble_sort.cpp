#include <iostream>
#include <vector>

using namespace std;

// Sort target vector by ascending order.
void fnBubble(vector<int>& vecIn) {
    bool isChange = true;

    // While element is swapped, repeat the process.
    while(isChange) {
        isChange = false;

        // Loop from the head element to the element just before tail.
        for(auto it = vecIn.begin(); it < vecIn.end() - 1; it++) {

            // Check an element and a following element
            //     if an element followed by a current iterator's element is smaller, swap these two.
            if(*it > *(it + 1)) {
                auto tmp = *it;
                *it = *(it + 1);
                *(it + 1) = tmp;
                isChange = true;
            }
        }
    }
}

int main() {
    vector<int> vecTest = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    fnBubble(vecTest); // result is {1 2 3 4 5 6 7 8 9}

    return 0;
}