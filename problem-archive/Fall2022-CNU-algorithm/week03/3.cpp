#include <iostream>
#include <regex>
#include <vector>

using namespace std;

/**
 * "\d+[SDT]형태의 문자열을 숫자로 바꾸는 함수"
 */
int fnCount(string strCur) {
    int nRes = 0;
    int nNum = stoi(strCur.substr(0, strCur.size() - 1)); // 마지막 문자만 뺀 나머지를 숫자로 변환함
    switch(strCur[strCur.size() - 1]) { // 마지막 문자에 대해 switch문을 이용함
        case 'S' :
        nRes = nNum; // S로 끝날때는 그대로 반환
        break;
        case 'D' :
        nRes = nNum * nNum; // D로 끝날때는 제곱을 반환
        break;
        case 'T' :
        nRes = nNum * nNum * nNum; // T로 끝날때는 세제곱을 반환
        break;
    }
    return nRes;
}

int dart(string strInput) {
    strInput += "0T"; // 마지막에 *가 들어올 경우에도 동일하게 이전과 이후의 값을 2배 해주는 로직을 사용하기 위해 0의 값을 추가함
    regex re("\\d+S|\\d+D|\\d+T|[*#]"); // 사용한 정규식
    auto it = sregex_iterator(strInput.begin(), strInput.end(), re); // 정규식으로 매칭된 문자열을 순회하는 반복자 선언
    vector<int> vecRes; // 각 라운드의 결과를 담는 벡터
    while(it != sregex_iterator()) { // 반복자가 끝까지 갈때까지 순회함
        string strCur = (*it).str(), strNext = ""; // 현재 매칭된 문자열을 strCur에 저장함(strNext는 사용하지 않은 변수)
        switch(strCur[strCur.size() - 1]) {
            case '*' :
            *(vecRes.end() - 1) *= 2; // *일 경우 벡터의 마지막 원소를 2배 해줌
            it++; // 반복자를 1 전진시킴
            vecRes.push_back(fnCount((*it).str())); // 1 전진시킨 반복자에 매칭되는 문자열을 fnCount로 점수로 변환하고 벡터에 push함
            *(vecRes.end() - 1) *= 2; // 방금 push한 원소를 2배 해줌
            break;
            case '#' :
            *(vecRes.end() - 1) *= -1; // #일 경우 벡터의 마지막 원소의 부호를 바꿔줌
            break;
            default :
            vecRes.push_back(fnCount(strCur)); // *나 #가 아닐때는 매칭된 문자열을 fnCount를 통해 점수로 변환해 벡터에 push함
            break;
        }
        it++;
    }
    int nRes = 0;
    for(auto el : vecRes) { // 각 라운드의 결과를 총합해 반환
        nRes += el;
    }
    return nRes;
}

int main() {
    string strInput;
    cin >> strInput;
    cout << dart(strInput) << endl;

    return 0;
}