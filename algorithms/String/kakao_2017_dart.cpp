/**
 * https://tech.kakao.com/2017/09/27/kakao-blind-recruitment-round-1/
 * 
 * Dart game
 * 
 * Regular expression
 */

#include <iostream>
#include <regex>
#include <vector>

using namespace std;

// ----- Solution -----
int fnGetScore(string strNum) {
    int nNum = stoi(strNum.substr(0, strNum.size()));
    switch(strNum[strNum.size() - 1]) {
        case 'D' :
        nNum *= nNum;
        break;
        case 'T' :
        nNum *= nNum * nNum;
        break;
    }
    return nNum;
}

int fnSum(vector<int> vecInput) {
    int nAcc = 0;;
    for(int el : vecInput) {
        nAcc += el;
    }
    return nAcc;
}

int fnSolve(string strInput) {
    regex tokenReg("\\d+S|\\d+D|\\d+T|[*#]");
    vector<int> vecRes;
    auto it = sregex_iterator(strInput.begin(), strInput.end(), tokenReg);
    while(it != sregex_iterator()) {
        string target = it->str();
        switch(target[target.size() - 1]) {
            case '*' :
            *(vecRes.end() - 1) *= 2;
            *(vecRes.end() - 2) *= vecRes.end() - 2 < vecRes.begin() ? 1 : 2;
            break;
            case '#' :
            *(vecRes.end() - 1) = vecRes.back() * -1;
            break;
            default:
            vecRes.push_back(fnGetScore(target));
        }
        it++;
    }
    return fnSum(vecRes);
}

// ----- Testing -----
struct Testing {
    string strInput;
    int nOutput;
};

int main() {
    Testing t[7] = {
        Testing{"1S2D*3T", 37},
        Testing{"1D2S#10S", 9},
        Testing{"1D2S0T", 3},
        Testing{"1S*2T*3S", 23},
        Testing{"1D#2S*3S", 5},
        Testing{"1T2D3D#", -4},
        Testing{"1D2S3T*", 59},
    };

    for(Testing el : t) {
        cout << el.strInput << ' ' << (fnSolve(el.strInput) == el.nOutput) << endl;
    }
    return 0;
}