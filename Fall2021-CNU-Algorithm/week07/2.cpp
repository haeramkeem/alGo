#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main() {
	// 표준입출력
	string strIn, strNum;

	getline(cin, strIn);
	stringstream ss(strIn);
	vector<int> bases;
	while(getline(ss, strNum, ' ')) {
		if(strNum.size() > 0) {
			bases.push_back(stoi(strNum));
		}
	}

	getline(cin, strIn);
	stringstream sp(strIn);
	vector<int> powers;
	while(getline(sp, strNum, ' ')) {
		if(strNum.size() > 0) {
			powers.push_back(stoi(strNum));
		}
	}

	int nMax = -1;
	for(const auto& base : bases) {
		// base 하나에 대해 가장 가까운 power을 찾음
		int nMin = 1000000;
		for(const auto& power : powers) {
			nMin = min(nMin, abs(base - power));
		}
		// 가장 가까운 power와의 거리들 중 가장 큰 값을 저장함
		nMax = max(nMax, nMin);
	}

	cout << nMax << endl;

	return 0;
}
