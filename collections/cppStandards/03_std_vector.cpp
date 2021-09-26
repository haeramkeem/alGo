#include <iostream>
#include <vector>

using namespace std;

int main() {

    /**
     * Vector is length-modifiable array.
     * 
     * Unlike std::array, std::vector does not require length when create.
     * It also supports push or pop method.
     * 
     * Unlike std::list, std::vector is sequential data structure.
     */

    // Declare 0-length vector
    vector<int> vecTest;

    // Declare & Allocate vector
    vector<int> vecTest1 = {1, 2, 3, 4, 5};

    // Decalre 5-length vector, this will initiate all elements by 0.
    vector<int> vecTest2(5);

    // Declare 5-length vector & initiating all elements by 2.
    vector<int> vecTest3(5, 2);

    // Pushes one element to vector.
    //     when vector's capacity is already full, .push_back() method allocates new memory, but it's capacity is doubled.
    //     then copies all existing element. thus, it takes O(n).
    //     but, memory doubling is occured very often, so big-o of .push_back() is nearly O(1).
    vecTest.push_back(0);

    // Insert one element to specific point of vector.
    //     example below is inserting 6 to index 1. result is {1, 6, 2, 3, 4, 5}
    vecTest1.insert(vecTest1.begin() + 1, 6);

    // Pops one element from vector.
    //     .pop_back() method returns void. this means .pop_back() just delete last one element from vector, not return it.
    //     .pop_back() method takes O(1).
    int nLastElement = vecTest1.back();
    vecTest1.pop_back();

    // .erase() method deletes element by iterator.
    //     when one argument is given, .erase() deletes one pointed element.
    //     when two argument is given, .erase() deletes all element from the first point to before the second point.
    vecTest1.erase(vecTest1.begin());
    vecTest1.erase(vecTest1.begin(), vecTest1.begin() + 3);

    // .clear() method deletes all element from vector.
    vecTest1.clear();

    // .reserve() method sets capacity of vector.
    //     if given capacity is bigger than existing capacity, sets vector's capacity by given value.
    //     else, .reserve() method doesn't do anything.
    vecTest1.reserve(10);

    // .shrink_to_fit() sets vector's capacity by vector's size.
    //     thus, if size of the vector doesn't change, .shrink_to_fit() is useful.
    vecTest1.shrink_to_fit();

    return 0;
}