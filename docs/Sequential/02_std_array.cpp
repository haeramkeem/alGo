#include <iostream>
#include <array>

using namespace std;

int main() {

    // Declare std::array.
    array<int, 5> stdArray;

    // Declare and allocate std::array.
    array<int, 5> stdArray2 = {1, 2, 3, 4, 5};

    // Get element by index just like C-style array.
    cout << stdArray2[0] << endl;

    // Or you can get element by .at(index) method.
    //     it throws exception when index not valid.
    try {
        cout << stdArray2.at(5) << endl;
    } catch(const out_of_range& err) {
        cerr << err.what() << endl;
    }

    // These are method to get first or last elemtnt
    cout << stdArray2.front() << endl;
    cout << stdArray2.back() << endl;

    // .data() method returns pointer of array.
    cout << *(stdArray2.data() + 1) << endl;

    // You can iterate array by ':'.
    //     It's similar with range keyword of GO.
    for(auto el : stdArray2) {
        cout << el << " ";
    }
    cout << endl;

    // .begin() method returns iterator of first element of array.
    // .end() method returns iterator of next to last element of array.
    //     iterator is similar with pointer.
    for(auto it = stdArray2.begin(); it != stdArray2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // .rbegin() method returns reverse_iterator of last element of array.
    // .rend() method returns reverse_iterator of next to first element of array.
    //     reverse_iterator is similar with pointer, but moves reversed-way when increases.
    for(auto rit = stdArray2.rbegin(); rit != stdArray2.rend(); rit++) {
        cout << *rit << " ";
    }
    cout << endl;

    // You can compare arrays with <, >, <=, >=, !=, ==
    array<int, 5> stdArray3 = {5, 4, 3, 2, 1};
    cout << (stdArray2 < stdArray3) << endl; // Result is 1.

    // '=' assignment operator copies array deeply.
    array<int, 5> stdArray4 = stdArray3;
    cout << (&stdArray3 == &stdArray4) << endl; // Result is 0.

    return 0;
}