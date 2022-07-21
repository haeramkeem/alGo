#include <climits>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto preHead = new ListNode(INT_MIN, head);

        auto leftBound = preHead;
        for(int i = 0; i < left - 1; i++) {
            leftBound = leftBound->next;
        }

        auto rightBound = leftBound->next;
        stack<ListNode*> stk;
        for (int i = 0; i < right - left + 1; i++) {
            stk.push(rightBound);
            rightBound = rightBound->next;
        }

        while (!stk.empty()) {
            leftBound->next = stk.top();
            leftBound = leftBound->next;
            stk.pop();
        }
        leftBound->next = rightBound;

        head = preHead->next;
        delete preHead;

        return head;
    }
};

int main() {
    return 0;
}
