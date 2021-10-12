/**
 * Programmers 42576) https://programmers.co.kr/learn/courses/30/lessons/42576
 * 
 * Hash map
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/* ----- Solution ----- */
string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> refined;
    for(const auto& strCom : completion) {
        if(refined.find(strCom) == refined.end()) { refined[strCom] = 0; }
        refined[strCom]++;
    }
    for(const auto& strPar : participant) {
        if(!refined[strPar]) { return strPar; }
        refined[strPar]--;
    }
    return "";
}

/* ----- Testing ----- */
struct Testing{
    vector<string> participant;
    vector<string> completion;
    string strRes;
};

int main() {
    Testing t[3] = {
        Testing{{"leo", "kiki", "eden"}, {"eden", "kiki"}, "leo"},
        Testing{{"marina", "josipa", "nikola", "vinko", "filipa"}, {"josipa", "filipa", "marina", "nikola"}, "vinko"},
        Testing{{"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"}, "mislav"},
    };

    string strRes;
    for(const auto& tcase : t) {
        strRes = solution(tcase.participant, tcase.completion);
        if(tcase.strRes != strRes) {
            cout << "FAIL: want " << tcase.strRes << " got " << strRes << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}