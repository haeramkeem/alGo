class EventListNode {
    constructor(start, end, next) {
        this.start = start;
        this.end = end;
        this.next = next;
    }

    insertAfterMe(eventListNode) {
        eventListNode.next = this.next;
        this.next = eventListNode;
    }

    get hasNext() {
        return this.next !== null;
    }
}

// Constructor
var MyCalendar = function() {
    this.eventEnd = new EventListNode(1000000001, 1000000001, null);
    this.eventBegin = new EventListNode(0, 0, this.eventEnd);
};

/**
 * @param {number} start
 * @param {number} end
 * @return {boolean}
 */
MyCalendar.prototype.book = function(start, end) {
    for (let it = this.eventBegin; it !== this.eventEnd; it = it.next) {
        if (it.end <= start && end <= it.next.start) {
            it.insertAfterMe(new EventListNode(start, end, null));
            return true;
        }
    }

    return false;
};
