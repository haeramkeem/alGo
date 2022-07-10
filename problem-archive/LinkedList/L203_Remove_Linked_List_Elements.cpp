/**
 * Leetcode 203) https://leetcode.com/problems/remove-linked-list-elements/
 *
 * Remove Linked List Elements
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

/* ----- Solution ----- */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val) {
            head = head->next;
        }
        auto it = head;
        while(it) {
            while(it->next && it->next->val == val) {
                it->next = it->next->next;
            }
            it = it->next;
        }
        return head;
    }
};
