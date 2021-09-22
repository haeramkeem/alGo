#include <iostream>
#include <forward_list>

using namespace std;

int main() {

    /**
     * std::forward_list is standard linked list.
     */

    // Declare & Allocate forward_list just like vector.
    forward_list<int> flistTest;
    forward_list<int> flistTest1 = {1, 2, 3, 4, 5};
    forward_list<int> flistTest2(5);
    forward_list<int> flistTest3(5, 3);

    // forward_list supports .front() to get first element.
    //     forward_list does not support direct-access element that is not first.
    //     this, you can't use [] operator or .at() method.
    cout << flistTest1.front() << endl;

    // You can get first or next-to-last iterator by .begin() or .end() just like vector.
    //     but, iterator of forward_list doesn't support + or - operation.
    //     you should use ++ operator to iterate.
    //     and std::forward_list is one-way list, so you can't access previous element.
    //     so you can't use -- operator.
    for(auto it = flistTest1.begin(); it != flistTest1.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;

    // forward_list supports two inserting method : .push_front(), .insert_after()
    //     .push_front() pushes one element to front of forward_list.
    //     .insert_after() inserts one element next to given iterator.
    flistTest1.push_front(0); // result is {0, 1, 2, 3, 4, 5}
    flistTest1.insert_after(flistTest1.begin(), 6); // result is {0, 6, 1, 2, 3, 4, 5}

    // .pop_front() method deletes first element and returns void just like vector.
    int nToPop = flistTest1.front();
    flistTest1.pop_front();

    // .erase_after() method deletes element followed by iterator. it's usage is same as vector.
    //     but unlike array or vector, this process takes O(1).
    flistTest1.erase_after(flistTest1.begin()); // result is {6, 2, 3, 4, 5}
    flistTest1.erase_after(flistTest1.begin(), flistTest1.end()); // result is {6}

    // .remove() method deletes all given value.
    //     .remove() method use == operator.
    //     so you can use .remove() method only if forward_list's template type supports == operator.
    flistTest = {1, 2, 3, 4, 5, 5, 5};
    flistTest.remove(5); // result is {1, 2, 3, 4}

    // .remove_if() method deletes all element if given lambda function is true.
    flistTest.remove_if([](int nElement) {
        return nElement < 3;
    }); // result is {1, 2}

    // As forward_list can't direct-access to element, forward_list can't sort by std::sort() function.
    //     instdead, you can use .sort() to sort forward_list
    //     you can also use greater<T>() to sort by decreasing-order
    //     to use .sort() method, forward_list's template type has to support compare operator like <
    //     and you can also use lambda functions to customize comparing.
    flistTest = {1, 3, 2, 5, 4};
    flistTest.sort(); // result is {1, 2, 3, 4, 5}
    flistTest.sort(greater<int>()); // result is {5, 4, 3, 2, 1}
    flistTest.sort([](int nTarget, int nNext) {
        return nTarget > nNext;
    }); // same as std::greater<int>()

    // .reverse() method reverses forward_list.
    flistTest = {1, 3, 2, 5, 4};
    flistTest.reverse(); // result is {4, 5, 2, 3, 1}

    // .unique() method delete all duplicated element.
    //     you can use lambda function to customize comparing.
    flistTest = {1, 1, 2, 2, 3, 3, 4, 4};
    flistTest.unique(); // result is {1, 2, 3, 4}
    flistTest = {1, 1, 2, 2, 3, 3, 4, 4};
    flistTest.unique([](int nFirst, int nSecond) {
        return nFirst == nSecond;
    }); // same as .unique()

    return 0;
}