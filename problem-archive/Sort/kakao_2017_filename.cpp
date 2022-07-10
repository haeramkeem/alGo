/**
 * https://tech.kakao.com/2017/11/14/kakao-blind-recruitment-round-3/
 * 
 * Sorting file name
 * 
 * Sorting
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

// ----- Solution -----
bool fnCmp(string& str1, string& str2) {
    regex re("(\\D+)(\\d+)");

    auto it1 = *sregex_iterator(str1.begin(), str1.end(), re);
    auto it2 = *sregex_iterator(str2.begin(), str2.end(), re);

    string lstr1 = it1[1], lstr2 = it2[1];
    transform(lstr1.begin(), lstr1.end(), lstr1.begin(), ::tolower);
    transform(lstr2.begin(), lstr2.end(), lstr2.begin(), ::tolower);

    if(lstr1 != lstr2) { return lstr1 < lstr2; }
    if(it1[2] != it2[2]) { return stoi(it1[2]) < stoi(it2[2]); }

    return true;
}

// ----- Testing -----
const int TEST_SIZE = 2;

struct Testing {
    vector<string> vecInput;
    vector<string> vecOutput;
};

int main() {
    Testing t[TEST_SIZE] = {
        Testing{
            {"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"},
            {"img1.png", "IMG01.GIF", "img02.png", "img2.JPG", "img10.png", "img12.png"},
        },
        Testing{
            {"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"},
            {"A-10 Thunderbolt II", "B-50 Superfortress", "F-5 Freedom Fighter", "F-14 Tomcat"}
        }
    };

    for(int i = 0; i < TEST_SIZE; i++) {
        sort(t[i].vecInput.begin(), t[i].vecInput.end(), fnCmp);
        for(int j = 0; j < t[i].vecOutput.size(); j++) {
            if(t[i].vecInput[j] != t[i].vecOutput[j]) {
                cout << "FAIL: want " << t[i].vecOutput[j] << ", got " << t[i].vecInput[j] << endl << '{';
                for(string strEl : t[i].vecInput) {
                    cout << strEl << ' ';
                }
                cout << '}' << endl;
                return 1;
            }
        }
    }

    cout << "ok" << endl;
    return 0;
}