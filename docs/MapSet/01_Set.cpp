#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    
    /**
     * Set uses BST for containing elements.
     *     So searching and inserting element takes O(logn).
     *     And by using BST, the keys of set are always ordered(by default, they are ordered by ascending order).
     * However, Unordered set uses hash function to allocate memory address.
     *     It's simmilar with SHA256, but size of bits is much smaller(usually 8-bit).
     *     As size of bits hash function returned is quite small, it's always possible to collide between two elements.
     *     When two elements collides, unordered set uses chaining to store collided elements.
     *     Because unordered set uses hash function, searching and inserting element usually takes O(1).
     *     And for the same reason, the keys of set are not ordered(this is why their name starts with "unordered_").
     */

    vector<int> vecTemp = {1, 9, 2, 8, 3};

    // These are various ways to decalre & allocate set.
    set<int> s;
    set<int> s1(vecTemp.begin(), vecTemp.end());
    set<int> s2(s1);
    set<int> s3 = s1;

    // You can iterate set just as vector.
    for(auto it = s1.begin(); it != s1.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl; // result is "1 2 3 8 9".

    // Size, empty, capacity getters just like vector.
    cout << s1.size() << endl; // result is 5.
    cout << boolalpha << s1.empty() << endl; // result is false.
    cout << s1.max_size() << endl; // result is capacity of set.

    // Insert, erase, clear methods
    s1.insert(4); // result is {1 2 3 4 8 9}.
    s1.erase(s1.find(2)); // result is {1 3 4 8 9}.
    s1.erase(s1.begin(), s1.find(3)); // result is {3 4 8 9}. Erase method erases element in range of (first parameter ~ second parameter - 1).
    s1.clear(); // result is {}.

    // Finding element in set
    s2.find(3); // returns iterator of given element.
    s2.lower_bound(3); // lower_bound() is simmilar with find(). it returns iterator of given element.

    // upper_bound() is simmilar with find(), but it returns iterator of following element of given element.
    //     so it's useful when using .erase().
    //     it's because when set is {1, 2, 3, 4, 5}, result of `set.erase(set.begin(), set.find(3))` is {3, 4, 5},
    //     but result of `set.erase(set.begin(), set.upper_bound(3))` is {4, 5}.
    s2.upper_bound(3);


    // Counts how many given element are in set.
    //     As set does not have duplicate value, it returns 0 or 1.
    //     So it's helpful when checking existance of element.
    s2.count(8); // result is 1.

    // Usage of unordered set are same as set.
    //     declaring & allocating unordered set.
    unordered_set<int> us;
    unordered_set<int> us1(vecTemp.begin(), vecTemp.end());
    unordered_set<int> us2(us1);
    unordered_set<int> us3 = us1;

    //     iterating unordered set.
    us1.begin(); // iterator of first element.
    us1.end(); // iterator of next to last element.
    //     getting size.
    us1.size(); // result is 5.
    us1.empty(); // result is false.
    us1.max_size(); // result is capacity of set.
    //    inserting & deleting element.
    us1.insert(4); // result is {1 2 3 4 8 9}.
    us1.erase(us1.find(2)); // result is {1 3 4 8 9}.
    us1.erase(us1.begin(), us1.find(3)); // result is {3 4 8 9}. Erase method erases element in range of (first parameter ~ second parameter - 1).
    us1.clear(); // result is {}.
    //    finding element.
    us2.find(3); // returns iterator of given element.
    // us2.lower_bound(3); -> unordered_set doesn't support lower_bound.
    // us2.upper_bound(3); -> unordered_set doesn't support upper_bound.
    us2.count(8); // result is 1.

    return 0;
}