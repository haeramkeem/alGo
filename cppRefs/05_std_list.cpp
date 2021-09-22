#include <iostream>
#include <list>

using namespace std;

int main() {

    /**
     * Unlike std::forward_list, std::list is doubly-linked list.
     */

    // Declare & Allocate forward_list just like vector.
    list<int> listTest;
    list<int> listTest1 = {1, 2, 3, 4, 5};
    list<int> listTest2(5);
    list<int> listTest3(5, 3);

    // Like std::forward_list, std::list can't support random access.
    //     so you can't use [] operator.
    //     you can direct access to first & last element only.
    cout << listTest1.front() << endl; // result is 1
    cout << listTest1.back() << endl; // result is 5

    // Unlike std::forward_list, std::list supports .size() method to get length of list.
    cout << listTest1.size() << endl;

    // Unlike std::forward_list, std::list is doubly-linked list, so you can also iterate backward.
    //     iterator of std::list supports ++ and -- operator.
    //     but you can't use + or - operator as same as std::forward_list.
    for(auto it = listTest1.begin(); it != listTest1.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl; // result is 1 2 3 4 5
    for(auto it = listTest1.end(); it != listTest1.begin(); it--) {
        cout << *it << ' ';
    }
    cout << endl; // result is 5 5 4 3 2

    // You can insert element by .insert(), .push_front(), .push_back() method.
    listTest.push_back(2);
    listTest.push_front(1);
    listTest.insert(listTest.begin(), 0);

    // Unlike std::forward_list, std::list supports .pop_back()
    listTest1.pop_back(); // result is {1, 2, 3, 4}
    listTest1.pop_front(); // result is {2, 3, 4}

    // .erase() method deletes elements, similar to the .erase_after() method of std::forward_list.
    //     but unlike .erase_after() method, .erase() method deletes element of exact point, not after.
    listTest1.erase(listTest1.begin()); // result is {3, 4}
    listTest1.erase(listTest1.begin(), listTest1.end()); // result is {}

    //  .remove() method deletes elements in exactly the same way as the .remove() method of std::forward_list.
    listTest1 = {1, 2, 3, 4, 5, 6, 7, 7, 7};
    listTest1.remove(7); // result is {1, 2, 3, 4, 5, 6}
    listTest1.remove_if([](int nElement) {
        return nElement < 3;
    }); // result is {3, 4, 5, 6}

    // .reverse() method & .unique() method actes in exactly the saem way as that of std::forward_list.
    listTest = {1, 3, 2, 5, 4};
    listTest.reverse(); // result is {4, 5, 2, 3, 1}
    listTest = {1, 1, 2, 2, 3, 3, 4, 4};
    listTest.unique(); // result is {1, 2, 3, 4}
    listTest = {1, 1, 2, 2, 3, 3, 4, 4};
    listTest.unique([](int nFirst, int nSecond) {
        return nFirst == nSecond;
    }); // same as .unique()

    return 0;
}