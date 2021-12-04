/**
 * Leetcode 328) https://leetcode.com/problems/odd-even-linked-list/
 *
 * Odd Even Linked List
 */

#include <iostream>

using namespace std;

/* ----- Domain ----- */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* -----Solution ----- */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) { return head; }

        auto tail = head;
        int N = 1;
        for(; tail->next; tail = tail->next) {
            N++;
        }
        
        if(N == 1) { return head; }

        auto odd = head;
        auto evenStart = head->next;
        auto even = evenStart;

        for(int i = 0; i < N - 2; i++) {
            if(i % 2 == 0) {
                odd->next = odd->next->next;
                odd = odd->next;
            } else {
                even->next = even->next->next;
                even = even->next;
            }
        }

        if(N % 2 == 1) {
            tail->next = evenStart;
            even->next = nullptr;
        } else {
            odd->next = evenStart;
        }

        return head;
    }
};
