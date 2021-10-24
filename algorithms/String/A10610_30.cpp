/**
 * BOJ 10610) https://www.acmicpc.net/problem/10610
 *
 * 30
 */

/* ----- Solution ----- */
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string strNum;
	cin >> strNum;
	auto zero = strNum.begin();
	int nSum = 0;
	for(auto it = strNum.begin(); it < strNum.end(); it++) {
		if(*it == '0') {
			zero = it;
		}
		nSum += *it - '0';
	}
	if(zero == strNum.begin() || nSum % 3 != 0) {
		cout << -1 << endl;
		return 0;
	}

	sort(strNum.begin(), strNum.end(), greater<char>());
	cout << strNum << endl;

	return 0;
}
