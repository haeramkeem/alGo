#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <set>

using namespace std;

int main() {
    // 노드의 갯수
    int N;
    cin >> N;

    // 두개의 구 를 입력받음
    string node1, node2;
    cin >> node1 >> node2;

    map<string, set<string>> conn;
    set<string> districts;
    cin.ignore();

    string strIn, key, value, nation;
    for(int i = 0; i < N; i++) {
        getline(cin, strIn);
        stringstream ss(strIn);

        // 국가 혹은 도시를 입력받음
        getline(ss, key, ' ');

        // 국가인 경우 국가명을 별도로 저장함
        if(i == 0) {
            nation = key;
        }

        // 국가 혹은 도시에 포함된 것을 입력받음
        while(getline(ss, value, ' ')) {
            if(value.size() > 0) {
                conn[key].insert(value);
                districts.insert(value);
            }
        }
    }

    // 입력된 구가 국가 내에 존재하지 않는 구일 경우
    if(districts.count(node1) == 0 || districts.count(node2) == 0) {
        cout << 0 << endl;
        return 0;
    }

    string city1, city2;
    for(auto it = conn.begin(); it != conn.end(); it++) {
        // 국가-도시 쌍일 경우에는 무시
        if(it->first == nation) {
            continue;
        }
        // 첫번째로 입력받은 구가 현재의 도시에 포함될 경우
        if(it->second.count(node1) == 1) {
            city1 = it->first;
        }
        // 두번째로 입력받은 구가 현재의 도시에 포함될 경우
        if(it->second.count(node2) == 1) {
            city2 = it->first;
        }
    }

    if(node1 == node2) {
        // 같은 구일 경우
        cout << node1 << endl;
    } else if(city1 == city2) {
        // 같은 도시에 포함되어있는 구일 경우
        cout << city1 << endl;
    } else {
        // 같은 도시에 포함되어있지 않는 구일 경우
        cout << nation << endl;
    }
}
