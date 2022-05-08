/**
 * Kakao 2022 tech internship test
 *
 * MBTI
 *
 * Etc
 */

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Solution
string solution(vector<string> survey, vector<int> choices) {
    int size = survey.size();

    vector<int> res(26, 0);

    for(int i = 0; i < size; i++) {
        int sel = choices[i] / 4;
        int won = abs(choices[i] - 4);
        res[survey[i][sel] - 'A'] += won;
    }

    string ans = "";
    ans += res['R' - 'A'] >= res['T' - 'A'] ? 'R' : 'T';
    ans += res['C' - 'A'] >= res['F' - 'A'] ? 'C' : 'F';
    ans += res['J' - 'A'] >= res['M' - 'A'] ? 'J' : 'M';
    ans += res['A' - 'A'] >= res['N' - 'A'] ? 'A' : 'N';

    return ans;
}

// Testing
struct Testing {
    vector<string> survey;
    vector<int> choices;
    string outp;
    static const int SIZE = 2;
    Testing(vector<string> s, vector<int> c, string o): survey(s), choices(c), outp(o) {}
};

int main() {
    Testing t[Testing::SIZE] = {
        Testing({"AN", "CF", "MJ", "RT", "NA"}, {5, 3, 2, 7, 5}, "TCMA"),
        Testing({"TR", "RT", "TR"}, {7, 1, 3}, "RCJA"),
    };

    for(auto& tcase : t) {
        auto res = solution(tcase.survey, tcase.choices);
        if(res != tcase.outp) {
            cout << "FAIL\n";
            cout << "Want: " << tcase.outp << endl;
            cout << "Got: " << res << endl;
            return 1;
        }
    }

    cout << "ok\n";
    return 0;
}
