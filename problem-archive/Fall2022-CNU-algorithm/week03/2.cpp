#include <iostream>

using namespace std;

/**
 * 입력받은 문자에 대해 Longest Palindromic Substring을 반환하는 함수
 */
string fnLPS(string& strInput) {
    string strMax = "";
    for(auto it = strInput.begin(); it < strInput.end(); it++) { // 입력 문자열의 첫번째 문자부터 순회함
        if(it + 2 < strInput.end() && *it == *(it + 2)) { // "aba"처럼 가운데 문자 하나를 두고 양옆의 문자가 동일한 경우
            auto l = it, r = it + 2; // 첫번째 포인터를 동일한 문자의 왼쪽 문자를 가르키게 하고, 두번째 포인터를 동일한 문자의 오른쪽 문자를 가르키게 함
            // 첫번째 포인터와 두번째 포인터가 가르키는 문자가 동일하는 한 두 포인터를 양쪽으로 확장시킴
            while(strInput.begin() <= l && r < strInput.end() && *l == *r) { l--;r++; }
            strMax = strMax.size() < static_cast<u_int>(r - l - 1) ? strInput.substr(l + 1 - strInput.begin(), r - l - 1) : strMax;
            // 첫번째 포인터와 두번째 포인터 사이에 있는 substring의 길이가 strMax보다 크다면 해당 substring으로 갱신함
        }
        if(it + 1 < strInput.end() && *it == *(it + 1)) { // "aa"처럼 동일한 문자 두개가 연속으로 등장하는 경우
            auto l = it, r = it + 1; // 첫번째 포인터를 동일한 문자의 왼쪽 문자를 가르키게 하고, 두번째 포인터를 동일한 문자의 오른쪽 문자를 가르키게 함
            // 첫번째 포인터와 두번째 포인터가 가르키는 문자가 동일하는 한 두 포인터를 양쪽으로 확장시킴
            while(strInput.begin() <= l && r < strInput.end() && *l == *r) { l--;r++; }
            strMax = strMax.size() < static_cast<u_int>(r - l - 1) ? strInput.substr(l + 1 - strInput.begin(), r - l - 1) : strMax;
            // 첫번째 포인터와 두번째 포인터 사이에 있는 substring의 길이가 strMax보다 크다면 해당 substring으로 갱신함
        }
    }
    return strMax; // 결과로 나온 substring을 반환함
}

int main() {
    string strInput;
    cin >> strInput;
    cout << fnLPS(strInput) << endl;
    return 0;
}