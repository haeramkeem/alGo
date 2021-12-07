/**
 * Leetcode 1290) https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
 *
 * Convert Binary Number in a Linked List to Integer
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
    int getDecimalValue(ListNode* head) {
        uint res{};
        while(head) {
            res = (res << 1) + head->val;
            head = head->next;
        }
        return res;
    }
};
