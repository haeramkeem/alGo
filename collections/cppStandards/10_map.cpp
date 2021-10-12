#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main() {

    /**
     * Just like difference between set and unordered set, map uses BST and unordered map uses hash function.
     * And other differences between set and unordered_set still apply to map and unordered_map.
     *     inserting and serching element takes O(logn) for map, O(1) for unordered map.
     *     keys are sorted in case of map but not in case of unordered_map.
     *     just like unordered set, keys of unordered map are contained by chaining when two keys are collide.
     */

    // Ways to declare & allocate map.
    map<string, int> m;
    map<string, int> m1(m);

    // You can insert key-value pair by .insert() method.
    m.insert(make_pair("first element", 1));
    m.insert(make_pair("second element", 2));
    m.insert(make_pair("third element", 3));

    // You can delete pair by key.
    m.erase("third element");

    // .clear() method clearing all pairs in map.
    m1.clear();

    // You get iterator of map by .begin() and .end() just like other containers.
    for(auto it = m.begin(); it != m.end(); it++) {

        // `first` field of map_iterator contains key of that iterator's pair.
        cout << it->first << endl;

        // `second` field of map_iterator contains value of that iterator's pair.
        cout << it->second << endl;
    }

    // These methods are useful when checking if a map contains a given key.
    //     .find() method returns iterator of given key, so when it's same with map's end, that means key isn't exists.
    //     .count() method returns a number of pairs with a given key. but map doesn't allow duplicate keys, so the result of this method is always 0 or 1.
    cout << boolalpha << (m1.find("fourth element") != m1.end()) << endl; // result is false.
    cout << m1.count("fourth element") << endl; // result is 0.

    // .empty() method and .size() method runs just like you expected.
    cout << boolalpha << m1.empty() << endl; // result is true.
    cout << m1.size() << endl; // result is 0.

    // Usage of unordered map are same as map.
    //     declaring & allocating unordered_map.
    unordered_map<string, int> um;
    unordered_map<string, int> um1(um);
    //     inserting & deleting pair.
    um.insert(make_pair("first element", 1)); // result is {"first element":1}
    um.insert(make_pair("second element", 2)); // result is {"first element":1 "second element":2}
    um.insert(make_pair("third element", 3)); // result is {"first element":1 "second element":2 "third element":3}
    um.erase("third element"); // result is {"first element":1 "second element":2}
    um1.clear(); // result is {}
    //     iterating unordered_map.
    for(auto it = um.begin(); it != um.end(); it++) {
        cout << it->first << endl;
        cout << it->second << endl;
    }
    //     finding pair by key.
    cout << boolalpha << (um1.find("fourth element") != um1.end()) << endl; // result is false.
    cout << um1.count("fourth element") << endl; // result is 0.
    //     getting size.
    cout << boolalpha << um1.empty() << endl; // result is true.
    cout << um1.size() << endl; // result is 0.

    return 0;
}