#include <iostream>
#include <vector>

using namespace std;

/* ----- Example Structure ----- */
struct Planet {
    double weight;
    string name;
    bool operator<(Planet p) const {
        if(this->weight == p.weight) {
            return this->name < p.name;
        } else {
            return this->weight < p.weight;
        }
    }

    bool operator>(Planet p) const {
        if(this->weight == p.weight) {
            return this->name > p.name;
        } else {
            return this->weight > p.weight;
        }
    }
};

void print(vector<Planet> vecArg) {
    cout << '{';
    for(auto el : vecArg) {
        cout << el.name << ' ';
    }
    cout << '}' << endl;
}

/* ----- Examples of std::sort ----- */
int main() {

    // Vectors
    vector<int> vecInts = {3, 7, 2, 4, 1, 0, 9, 8, 5, 6};
    vector<Planet> vecCustom = {
        Planet{0.0553, "Mercury"},
        Planet{0.88112, "Venus"},
        Planet{1, "Earth"},
        Planet{0.107, "Mars"},
        Planet{318.721, "Jupiter"},
        Planet{95.152, "Saturn"},
        Planet{14.534, "Uranus"},
        Planet{17.145, "Neptune"},
    };

    // Sort by ascending order.
    //     if, comparator si not given, std::sort() will sort by (default) ascending order.
    //     you can get same result by using std::less<T>() comparator.
    sort(vecInts.begin(), vecInts.end()); // result is {0 1 2 3 4 5 6 7 8 9}
    sort(vecInts.begin(), vecInts.end(), less<int>()); // result is {0 1 2 3 4 5 6 7 8 9}

    // Sort by descending Order
    sort(vecInts.begin(), vecInts.end(), greater<int>()); // result is {9 8 7 6 5 4 3 2 1 0}

    // Sort planets by their weight in ascending order using custom comparator.
    sort(vecCustom.begin(), vecCustom.end(), [](Planet p1, Planet p2) {
        return p1.weight < p2.weight;
    });
    print(vecCustom); // result is {Mercury Mars Venus Earth Uranus Neptune Saturn Jupiter}

    // Sort planets by their weight in descending order using custom comparator.
    sort(vecCustom.begin(), vecCustom.end(), [](Planet p1, Planet p2) {
        return p1.weight > p2.weight;
    });
    print(vecCustom); // result is {Jupiter Saturn Neptune Uranus Earth Venus Mars Mercury}

    // Sort planets by overrided operator '<'.
    sort(vecCustom.begin(), vecCustom.end());
    print(vecCustom); // result is {Mercury Mars Venus Earth Uranus Neptune Saturn Jupiter}

    // Sort planets by overrided operator '>'.
    sort(vecCustom.begin(), vecCustom.end(), greater<Planet>());
    print(vecCustom); // result is {Jupiter Saturn Neptune Uranus Earth Venus Mars Mercury}

    return 0;
}