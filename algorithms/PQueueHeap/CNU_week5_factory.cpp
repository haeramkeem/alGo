#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int stock, k, dlen, slen, temp, nextImp = 0, impCnt = 0;
    cin >> stock >> k >> dlen >> slen;
    vector<int> dates, supls;
    for(int i = 0; i < dlen; i++) {
        cin >> temp;
        dates.push_back(temp);
    }
    for(int i = 0; i < slen; i++) {
        cin >> temp;
        supls.push_back(temp);
    }

    priority_queue<int> pq;
    // 재고를 나타내는 stock이 목표일수인 k보다 크거나 같으면 목표일수를 현재의 재고로 버틸 수 있으므로 stock이 k보다 작은 동안 while문이 실행된다.
    while(k > stock) {
        // nextImp은 현재의 재고로 버틸 수 없는 기간에 대한 첫번째 수입 일정을 가리키는 인덱스이다.
        //     하지만 수입 이후에는 해당 일자까지 버틸 수 있으므로 수입 이후에는 for문을 이용해 다시 버틸 수 없는 첫번째 수입 일정까지 nextImp를 옮겨준다.
        //     for문의 i 값의 초깃값으로 nextImp를 주어 수입 이전에는 버틸 수 없었지만 수입하고 나서는 버틸 수 있는 첫번째 수입 일자부터 순회하게 한다.
        for(int i = nextImp; i < dlen; i++) {
            // 만약 수입 일정까지 현재의 재고로 버틸 수 있을 때
            if(dates[i] <= stock) {
                // 해당 수입 일정에 예정된 수입양을 우선순위 큐에 넣어준다.
                pq.push(supls[i]);
                // nextImp를 1 올려준다.
                nextImp++;

            // 만약 수입 일정까지 현재의 재고로 버틸 수 없을 때
            } else {
                break;
            }
        }
        // 현재의 재고로 버틸 수 있는 일자까지의 수입 일정 중에 가장 많이 수입할 수 있는 양을 수입한다.
        stock += pq.top();
        pq.pop();
        // 수입 횟수를 1 증가시킨다.
        impCnt++;
    }

    cout << impCnt << endl;

    return 0;
}

