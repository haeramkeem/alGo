#include <iostream>
#include <vector>
#include <forward_list>
#include <list>

using namespace std;

int main() {

    /**
     * Let's see these four iterators.
     *     (1) Random access iterator
     *     (2) Forward iterator
     *     (3) Bidirectional iterator
     *     (4) Reverse iterator
     */

    // std::srray and std::vector supports (1) Random access iterator.
    //     these are iterators that supports direct access to one point of container.
    //     by (1) Random access iterator, you can use +, -, +=, -=, ++, -- operations to iterate.
    vector<int> vecTest = {1, 2, 3, 4, 5, 6, 7};
    vector<int>::iterator itVec = vecTest.begin();
    cout << *(itVec +3) << endl; // result is 4

    // std::forward_list supports (2) Forward iterator.
    //      these are iterators that do not supports direct access, only access to first or next element.
    //      by (2) Forward iterator, you can use only ++ operation to iterate.
    forward_list<int> flistTest = {1, 2, 3, 4, 5, 6, 7};
    forward_list<int>::iterator itFlist = flistTest.begin();
    itFlist++;
    cout << *itFlist << endl; // result is 2

    // std::list supports (3) Bidirectional iterator.
    //      these are iterators that do not supports direct access, only access to first, last, next or prev element.
    //      by (3) Bidirectional iterator, you can use only ++, -- operations to iterate.
    list<int> listTest = {1, 2, 3, 4, 5, 6, 7};
    list<int>::iterator itList = listTest.begin();
    itList++;
    cout << *itList << endl; // result is 2
    itList--;
    cout << *itList << endl; // result is 1

    // .rend() or .rbegin() method of std::array, std::vector, std::list gives you (4) Reverse iterator.
    //     in (4) Reverse iterator of std::array and std::vector, you can use +, -, +=, -=, ++, -- operations to iterate.
    //     in (4) Reverse iterator of std::list, you can use ++, -- operations only.
    //     but as in (4) Reverse iterator, it moves backward.
    //     for example, when use ++ operation of (4) Reverse iterator, iterator points previous element.
    vector<int>::reverse_iterator revItVec = vecTest.rbegin();
    list<int>::reverse_iterator revItList = listTest.rbegin();
    cout << *revItVec << endl; // result is 7
    cout << *(revItVec + 3) << endl; // result is 4
    cout << *revItList << endl; // result is 7
    revItList++;
    cout << *revItList << endl; // result is 6

    // next() function is same as +1.
    //     it's different from ++. next() function do not move iterator.
    cout << *itVec << ' ' << *next(itVec) << endl; // result is 1 2
    cout << *itFlist << ' ' << *next(itFlist) << endl; // result is 2 3
    cout << *itList << ' ' << *next(itList) << endl; // result is 1 2

    // prev() function is same as -1.
    //     like next(), it's different from --. prev() function do not move iterator.
    //     and of course, (2) Forward iterator can't move backward, you can't use prev() function with (2) Forward iterator.
    itVec++;
    itList++;
    cout << *itVec << ' ' << *prev(itVec) << endl; // result is 2 1
    cout << *itList << ' ' << *prev(itList) << endl; // result is 2 1

    // advance() function is same as +n.
    //     advance() function moves iterator by given distance, and returns void.
    //     and you can also use advance() function in iterator of std::forward_list, std::list.
    //     iterator of std::array and std::vector, advance() take O(1), but iterator of std::forward_list and std::list, it takes O(n).
    //     when distance is negative value, iterator moves backward.
    //     but (2) Froward iterator does not support moving backward, so iterator doesn't move.
    //     so it's useless to use advance() function with negative distance in (2) Forward iterator.
    advance(itVec, 3);
    advance(itFlist, 3);
    advance(itList, 3);
    cout << *itVec << endl; // before advance(), result is 2, after advance, result is 5
    cout << *itFlist << endl; // before advance(), result is 2, after advance, result is 5
    cout << *itList << endl; // before advance(), result is 2, after advance, result is 5

    // It is sometimes dangerous to use a previously allocated iterator after insertion.
    //     this is because inserts occur after reallocating memory when the container is full in std::array or std::vector.
    //     however, with std::forward_list or std::list there is no memory reallocation during insert, so it is safe to use the old iterator.
    //     it's also dangerous to use the old iterator when the element pointed by the iterator is deleted.
    vecTest.shrink_to_fit();
    vecTest.push_back(1); // using iterator itVec is dangerous.
    
    return 0;
}