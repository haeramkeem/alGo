/**
 * Leetcode 1286) https://leetcode.com/problems/iterator-for-combination/
 *
 * Iterator for Combination
 */

#include <iostream>
#include <set>

using namespace std;

/* ----- Solution ----- */
class CombinationIterator {
    set<string> combinations;
    set<string>::iterator iter;
public:
    CombinationIterator(string characters, int combinationLength) {
        int N = characters.size();
        for(int it = (1 << combinationLength) - 1; it < (1 << N); it++) {
            string res;
            res.reserve(N);
            for(int i = 0; i < N; i++) {
                if(it & (1 << i)) {
                    res += characters[i];
                }
            }

            if(res.size() == combinationLength) {
                combinations.insert(res);
            }
        }

        iter = combinations.begin();
    }
    
    string next() {
        return *iter++;
    }
    
    bool hasNext() {
        return iter != combinations.end();
    }
};

/* ----- Testing ----- */
const int TCASE_SIZE = 2;
struct Testing {
    string characters;
    int combinationLength;
};

int main() {
    Testing t[TCASE_SIZE] = {
        Testing{"abc", 2},
        Testing{"bvwz", 2},
    };

    for(const auto& tcase : t) {
        CombinationIterator it(tcase.characters, tcase.combinationLength);
        while(it.hasNext()) {
            cout << it.next() << ' ';
        }
        cout << endl;
    }

    return 0;
}
