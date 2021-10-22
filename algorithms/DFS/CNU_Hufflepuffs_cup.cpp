/**
 * CNU week6
 * 
 * Hufflepuff's cup
 * 
 * DFS
 * 
 * refs: getline + stoi
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// 트로피들의 관계를 저장하는 2차원 배열
vector<vector<int>> mMap;
// 방문체크를 위한 배열
bool* visited;
// 트로피의 갯수
int nCups;

bool fnVisit(int cur) {
	// 만약 마지막 트로피에 도달하면 참을 반환하고 종료
	if(cur == nCups - 1) {
		return true;
	}
	// 현재의 노드를 방문했음으로 변경함
	visited[cur] = true;
	// 트로피에 담긴 쪽지들을 순회함
	for(const auto& nTicket : mMap[cur]) {
		// 만약 방문하지 않은 트로피가 쪽지에 있으면
		if(!visited[nTicket]) {
			// 해당 트로피를 방문하고 만약 제일 끝까지 도달하였으면 바로 참을 반환하고 종료
			if(fnVisit(nTicket)) {
				return true;
			}
		}
	}
	// 만약 인접한 어느 트로피도 마지막까지 도달하지 못했으면 거짓을 반환하고 종료
	return false;
}

int main() {
	// input을 받아옴
	cin >> nCups;
	visited = new bool[nCups];
	string strIn, chIn;
	mMap.reserve(nCups);
	cin.ignore();
	for(int i = 0; i < nCups; i++) {
		visited[i] = false;
		getline(cin, strIn);	
		stringstream ss(strIn);
		vector<int> vecTemp;
		while(getline(ss, chIn, ' ')) {
			if(chIn.size() > 0) {
				vecTemp.push_back(stoi(chIn));
			}
		}
		mMap.push_back(vecTemp);
	}

	// 0번 트로피부터 방문하여
	//     마지막 트로피까지 도달하였으면 True를 출력하고
	//     도달하지 못하였으면 False를 출력함
	if(fnVisit(0)) {
		cout << "True" << endl;
	} else {
		cout << "False" << endl;
	}

	delete visited;
	return 0;
}
