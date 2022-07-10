package main

// Example codes
// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
type NestedInteger struct {}

// Return true if this NestedInteger holds a single integer, rather than a nested list.
func (this NestedInteger) IsInteger() bool { return false }

// Return the single integer that this NestedInteger holds, if it holds a single integer
// The result is undefined if this NestedInteger holds a nested list
// So before calling this method, you should have a check
func (this NestedInteger) GetInteger() int { return 0 }

// Set this NestedInteger to hold a single integer.
func (n *NestedInteger) SetInteger(value int) {}

// Set this NestedInteger to hold a nested list and adds a nested integer to it.
func (this *NestedInteger) Add(elem NestedInteger) {}

// Return the nested list that this NestedInteger holds, if it holds a nested list
// The list length is zero if this NestedInteger holds a single integer
// You can access NestedInteger's List element directly if you want to modify it
func (this NestedInteger) GetList() []*NestedInteger { return nil }

// Solution
type NestedIterator struct {
    cur     int
    flat    []int
}

// Recursive func to convert *NestedInteger to []int
func flattenNestedInteger(nestedEl *NestedInteger) []int {

    // If nested integer holds a sigle integer
    if nestedEl.IsInteger() {
        return []int{ nestedEl.GetInteger() }
    }

    // If nested integer holds a nestedInteger list
    acc := make([]int, 0)
    for _, nestedListEl := range nestedEl.GetList() {
        acc = append(acc, flattenNestedInteger(nestedListEl)...)
    }
    return acc
}

func Constructor(nestedList []*NestedInteger) *NestedIterator {
    flat := make([]int, 0)

    for _, nestedEl := range nestedList {
        flat = append(flat, flattenNestedInteger(nestedEl)...)
    }

    return &NestedIterator{
        cur: 0,
        flat: flat,
    }
}

func (this *NestedIterator) Next() int {
    this.cur++
    return this.flat[this.cur - 1]
}

func (this *NestedIterator) HasNext() bool {
    return len(this.flat) != this.cur
}
