#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int impCnt = 0, idx = 0 /* 수입 인덱스 - 다음에 예정된 수입일자를 나타내는 인덱스 */ ;
    priority_queue<int> maxq;
    while (stock < k) /* 지금있는 밀가루로는 버티는게 불가능할 경우 */ {
        for(int i = idx; i < dates.size(); i++) /* 앞으로 예정된 수입을 순회함 */ {
            if(dates[i] <= stock) /* 해당 수입 일자까지 버틸 수 있음 */ {
                maxq.push(supplies[i]);
                idx++;
            } else /* 해당 수입 일자까지 버틸 수 없음 */ {
                break;
            }
        }
        stock += maxq.top();
        maxq.pop();
        impCnt++;
    }
    return impCnt;
}

struct Testing {
    int stock;
    vector<int> dates;
    vector<int> supplies;
    int k;
    int out;
};

const int TCASE_SIZE = 3;

int main() {
    Testing t[TCASE_SIZE] {
        Testing{4, {4, 10, 15}, {20, 5, 10}, 30, 2},
    };
    for(const auto& tcase : t) {
        auto res = solution(tcase.stock, tcase.dates, tcase.supplies, tcase.k);
        if(res != tcase.out) {
            cout << "FAIL: want " << tcase.out << ", got " << res << endl;
            return 1;
        }
    }

    cout << "ok" << endl;
    return 0;
}