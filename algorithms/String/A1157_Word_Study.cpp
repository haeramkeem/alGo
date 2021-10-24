/**
 * BOJ 1157) https://www.acmicpc.net/problem/1157
 *
 * Word Study
 */

/* ----- Solution ----- */
#include <iostream>

using namespace std;

int main() {
	string strIn;
	cin >> strIn;
	int nMax = -1;
	bool isDupl = false;
	char chMax;
	int alpha[26] = {};
	for(const auto& ch : strIn) {
		int idx = tolower(ch) - 'a';
		alpha[idx]++;
		if(alpha[idx] > nMax) {
			nMax = alpha[idx];
			chMax = toupper(ch);
			isDupl = false;
		} else if(alpha[idx] == nMax) {
			isDupl = true;
		}
	}
	if(isDupl) {
		cout << "?" << endl;
	} else {
		cout << chMax << endl;
	}

	return 0;
}
