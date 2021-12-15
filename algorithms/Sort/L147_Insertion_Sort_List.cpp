/**
 * Leetcode 147) https://leetcode.com/problems/insertion-sort-list/
 *
 * Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        head = new ListNode(INT_MIN, head);
        for(auto it = head; it->next;) {

            // Do insertion sort when value of next node is smaller
            if(it->next && it->val > it->next->val) {
                // Separate unordered node from list
                auto target = it->next;
                it->next = it->next->next;

                // Find lower bound
                auto lbound = head;
                for(; lbound->next && lbound->next->val < target->val; lbound = lbound->next) {}

                // Insert
                target->next = lbound->next;
                lbound->next = target;
            }

            // Iterate to next node only if value of next node is bigger or equal to current node.
            //      Condition for iteration is neccesary
            //      because it's possible that value of next node is still smaller than current node after insertion.
            if(it->next && it->val <= it->next->val) {
                it = it->next;
            }
        }
        return head->next;
    }
};
