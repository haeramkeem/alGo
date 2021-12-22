#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

/**
 * 입력받은 두 문자열에 대해 anagram이 맞는지 판별하는 함수
 */
string anagram(string strInput1, string strInput2) {
    map<char, int> mapRes1, mapRes2;
    transform(strInput1.begin(), strInput1.end(), strInput1.begin(), ::tolower); // 첫번째 문자열을 소문자로 바꿈
    transform(strInput2.begin(), strInput2.end(), strInput2.begin(), ::tolower); // 두번째 문자열을 소문자로 바꿈
    for(auto cEl : strInput1) { // 첫번째 문자열을 순회함
        if(mapRes1.find(cEl) != mapRes1.end()) { // map에 문자가 존재하면 1을 증가
            mapRes1[cEl]++;
        } else { // map에 문자가 존재하지 않으면 1을 할당
            mapRes1[cEl] = 1;
        }
    }
    for(auto cEl : strInput2) { // 두번째 문자열을 순회함
        if(mapRes2.find(cEl) != mapRes2.end()) { // map에 문자가 존재하면 1을 증가
            mapRes2[cEl]++;
        } else { // map에 문자가 존재하지 않으면 1을 할당
            mapRes2[cEl] = 1;
        }
    }
    return mapRes1 == mapRes2 ? "True" : "False"; // 두 map이 동일한지 검사하여 그에 맞는 문자열을 반환
}

int main() {
    string strInput1, strInput2;
    cin >> strInput1 >> strInput2;
    cout << anagram(strInput1, strInput2) << endl;
    return 0;
}