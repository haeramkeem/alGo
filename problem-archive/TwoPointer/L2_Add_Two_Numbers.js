/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */

/**
 * @param {ListNode} i1
 * @param {ListNode} i2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let i1 = l1;
    let i2 = l2;
    let overflow = 0;
    let isL1Longer = true;
    let oneBefore = null;
    while (true) {
        if (!!i1 && !!i2) {
            // Get sum
            overflow += i1.val + i2.val;
            // Sync
            i1.val = overflow % 10;
            i2.val = i1.val;
            // Calc overflow
            overflow = Math.floor(overflow / 10);
            // Move
            oneBefore = i1;
            i1 = i1.next;
            i2 = i2.next;
        } else if (!!i1) {
            overflow += i1.val;
            i1.val = overflow % 10;
            overflow = Math.floor(overflow / 10);
            oneBefore = i1;
            i1 = i1.next;
        } else if (!!i2) {
            overflow += i2.val;
            i2.val = overflow % 10;
            overflow = Math.floor(overflow / 10);
            oneBefore = i2;
            i2 = i2.next;
            isL1Longer = false;
        } else {
            // If overflow is not empty
            if (overflow !== 0) {
                oneBefore.next = new ListNode();
                oneBefore.next.val = overflow;
            }
            break;
        }
    }

    return isL1Longer ? l1 : l2;
};
