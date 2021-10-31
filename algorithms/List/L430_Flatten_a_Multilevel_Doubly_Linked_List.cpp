/**
 * Leetcode 430) https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
 *
 * Flatten a Multilevel Doubly Linked List
 */

#include <iostream>

using namespace std;

/* ----- Domain ----- */
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

/* ----- Solution ----- */
class Solution {
	Node* endOfFlatten(Node* head) {
		Node* it = head;
 		while(true) {
			if(it->child) {
				Node* tempNext = it->next;
				Node* end = endOfFlatten(it->child);
				it->next = it->child; it->child->prev = it; it->child = NULL;
				end->next = tempNext;
				if(!tempNext) {
					it = end;
					break;
				}
				tempNext->prev = end;
				it = tempNext;
			} else if(it->next) {
				it = it->next;
			} else {
				break;
			}
		}
		return it;
	}
public:
    Node* flatten(Node* head) {
		if(!head) { return NULL; }
		endOfFlatten(head);
		return head;
    }
};
