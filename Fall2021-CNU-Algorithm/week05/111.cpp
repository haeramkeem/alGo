#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

int main() {
    string participant, completion, temp;
    getline(cin, participant);
    getline(cin, completion);
    stringstream sp(participant), sc(completion);
    unordered_map<string, int> /* {이름: 명수} */ m;

    // 완료한 사람들을 한명씩 hashmap에 추가하고 이미 추가되어 있으면 명수를 1 증가시킨다.
    while(getline(sc, temp, ' ')) { m[temp]++; }
    // 참여한 사람들을 한명씩 hashmap에서 탐색한다.
    while(getline(sp, temp, ' ')) {
        // 만약 명수가 1보다 크거나 같으면 1을 감소시킨다.
        if(m[temp] > 0) {
            m[temp]--;

        // 만약 명수가 1보다 작으면 완료한 참가자가 아니므로 화면에 그의 이름을 출력한다.
        } else {
            cout << temp << ' ';
        }
    }
    cout << '\n';
    return 0;
}

