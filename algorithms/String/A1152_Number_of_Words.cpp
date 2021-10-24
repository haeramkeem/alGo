/**
 * BOJ 1152) https://www.acmicpc.net/problem/1152
 *
 * Number of Words
 */

/* ----- Solution ----- */
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	stringstream ss(s);
	int nCnt = 0;
	while(getline(ss, s, ' ')) {
		if(s.size() > 0) {
			nCnt++;
		}
	}

	cout << nCnt << endl;
	return 0;
}
