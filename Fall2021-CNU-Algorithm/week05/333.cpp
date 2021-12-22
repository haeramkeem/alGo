#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

int main() {
    string strIn, temp;
    getline(cin, strIn);
    stringstream ss(strIn);
    priority_queue<int> pq;
    // 소행성의 무게를 우선순위 큐에 넣어 항상 소행성의 가장 무거운 무게가 top에 위치하도록 한다.
    while(getline(ss, temp, ' ')) { pq.push(stoi(temp)); }
    // 우선순위 큐의 크기가 1보다 커 충돌시킬 수 있는 소행성이 항상 존재할때 while문이 실행된다.
    while(pq.size() > 1) {
        // 제일 무게가 많이 나가는 소행성을 꺼낸다.
        int head = pq.top();
        pq.pop();

        // 두번째로 무게가 많이 나가는 소행성을 꺼낸다.
        int next = pq.top();
        pq.pop();

        // 충돌해서 잔해가 남는 경우에는 잔해의 무게를 다시 우선순위 큐에 넣어준다.
        if(head > next) {
            pq.push(head - next);
        }
    }

    // 소행성이 모두 사라진 경우에는 0을 출력한다.
    if(pq.size() == 0) {
        cout << 0 << endl;

    // 소행성이 하나 남은 경우에는 해당 소행성의 무게를 출력한다.
    } else {
        cout << pq.top() << endl;
    }

    return 0;
}

