#include <iostream>
#include <map>
#include <deque>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string strTemp, strIn;
    deque< deque<string> > deqOut;
    map< string, deque<string> > mAns;
    
    getline(cin, strIn);
    stringstream ss(strIn);

    // 입력 문자열을 공백으로 구분하여 하나씩 꺼낸다.
    while(getline(ss, strTemp, ' ')) {

        // 단어 하나를 소문자로 변환한다.
        transform(strTemp.begin(), strTemp.end(), strTemp.begin(), ::tolower);

        // 해당 단어를 오름차순으로 정렬하여 strS에 저장한다.
        string strS = strTemp;
        sort(strS.begin(), strS.end());

        // map의 key에서 해당 단어를 조회하고 존재하지 않는다면 해당 단어를 포함하는 벡터를 할당해준다.
        if(mAns.find(strS) == mAns.end()) {
            mAns[strS] = {strTemp};

        // map의 key에 해당 단어가 이미 존재하면 연결되어있는 벡터에 해당 단어를 추가한다.
        } else {
            mAns[strS].push_back(strTemp);
        }
    }

    // map을 순회하며 각각의 key에 대칭되는 value인 anagram group을 오름차순으로 정렬한다.
    // 이후 anagram group을 2차원 데크에 추가한다.
    for(const auto& it : mAns) {
        auto deqGroup = mAns[it.first];
        sort(deqGroup.begin(), deqGroup.end());
        deqOut.push_back(deqGroup);
    }

    // anagram group들을 저장한 2차원 데크에서 각각의 그룹을 그룹의 첫번째 원소를 기준으로 정렬한다.
    sort(deqOut.begin(), deqOut.end(), [](deque<string> deq1, deque<string> deq2) {
        return deq1[0] < deq2[0];
    });

    for(const auto& deqGroup : deqOut) {
        for(auto it = deqGroup.begin(); it < deqGroup.end() - 1; it++) {
            cout << *it << ' ';
        }
        cout << *(deqGroup.end() - 1) << '\n';
    }
}