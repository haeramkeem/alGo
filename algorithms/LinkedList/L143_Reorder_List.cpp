/**
 * Leetcode 143) https://leetcode.com/problems/reorder-list/
 *
 * Reorder List
 */

#include <iostream>
#include <vector>

using namespace std;

/* ----- Domain ----- */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* ----- Solution -----*/
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        int N = 0;
        for(auto it = head; it; it = it->next) {
            nodes.push_back(it);
            N++;
        }

        int thres = N / 2;
        for(int i = 0; i < N; i++) {
            if(i < thres) {
                nodes[i]->next = nodes[N - 1 - i];
            } else if(i == thres) {
                nodes[i]->next = nullptr;
            } else {
                nodes[i]->next = nodes[N - i];
            }
        }
    }
};
