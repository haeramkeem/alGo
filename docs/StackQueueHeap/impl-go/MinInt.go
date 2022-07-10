package heap

import "errors"

/* ----- TYPE ----- */
type MinInt struct{
	Tail	int
	Tree	[]int
}

/* ----- CONSTRUCTOR ----- */
func NewMinInt(size int) *MinInt {
	return &MinInt{0, make([]int, size)}
}

func InitMinInt(init []int) *MinInt {
	res := &MinInt{len(init), init}
	res.heapifyForRandom()
	return res;
}

/* ----- PUBLIC ----- */
/**
 * Push one element to min heap
 */
func (h *MinInt) Push(el int) error {
	// if heap is full, returns error.
	if h.Tail >= len(h.Tree) { return errors.New("heap: full") }

	// add element in tail of Complete Binary Tree.
	h.Tree[h.Tail] = el

	// if two or more element is in CBT, heapify it from bottom to top.
	if h.Tail > 0 { h.heapifyAfterPush(h.Tail) }

	// move tail
	h.Tail++
	return nil
}

/**
 * Pop one element from min heap
 */
func (h *MinInt) Pop() (int, error) {
	// if heap is empty, returns error.
	if h.Tail == 0 { return 0, errors.New("heap: empty") }

	// save head of Complete Binary Tree.
	target := h.Tree[0]

	// allocate last element of CBT to head.
	h.Tree[0] = h.Tree[h.Tail - 1]

	// move tail
	h.Tail--

	// if two or more element is in CBT, heapify it from top to bottom.
	if h.Tail > 1 { h.heapifyTopDown(0) }
	return target, nil
}

/* ----- PRIVATE ----- */
/**
 * Swap value of two given index.
 */
 func (h *MinInt) swap(idx1 int, idx2 int) {
	h.Tree[idx1], h.Tree[idx2] = h.Tree[idx2], h.Tree[idx1]
}

/**
 * Return index that has smallest value.
 */
func (h *MinInt) getMinIdx(idx1, idx2, idx3 int) int {
	if h.Tree[idx1] < h.Tree[idx2] && h.Tree[idx1] < h.Tree[idx3] { return idx1 }
	if h.Tree[idx2] < h.Tree[idx1] && h.Tree[idx2] < h.Tree[idx3] { return idx2 }
	return idx3
}

/**
 * Do heapify after push.
 *     since the sibling of the current node is always bigger than the parent node, we only check and replace between the current node and the parent node.
 */
func (h *MinInt) heapifyAfterPush(cur int) {
	// Notice that cur means index of current node and (cur - 1) / 2 means index of parent node.
	//     if current node is not root and value of parent node is bigger than current node, swap value.
	//     and heapify recursively from parent to top.
	if cur > 0 && h.Tree[cur] < h.Tree[(cur - 1) / 2] {
		h.Tree[cur], h.Tree[(cur - 1) / 2] = h.Tree[(cur - 1) / 2], h.Tree[cur]
		h.heapifyAfterPush((cur - 1) / 2)
	}
}

/*
 * Do heapify for random slice.
 *     since the sibling of the current node is always smaller than the parent node, we only check and replace between the current node and the parent node.
 */
 func (h *MinInt) heapifyForRandom() {
	for i := h.Tail - 1; i > 0; i-- {
		parent := GetParent(i)
		if h.Tree[i] < h.Tree[parent] { h.swap(i, parent) }
	}
}

/**
 * Do heapify from bottom to top.
 */
func (h *MinInt) heapifyBottomUp(cur int) {
	// If current node is root.
	if cur <= 0 { return }

	// Get parent & sibling index
	var parent int = (cur - 1) / 2
	sibling := parent * 2 + 1
	if sibling == cur { sibling++ }

	// Get index that has smallest value.
	minIdx := h.getMinIdx(parent, cur, sibling)

	// If minIdx is not parent node's index
	//     first, swap parent node's value and value of minIdx.
	//     second, rearrange recursively from parent node.
	if minIdx != parent {
		h.swap(minIdx, parent)
		h.heapifyBottomUp(parent)
	}
}

/**
 * Do heapify from top to bottom.
 */
 func (h *MinInt) heapifyTopDown(cur int) {
	// Get children's index.
	leftIdx := cur * 2 + 1
	rightIdx := cur * 2 + 2

	// If current node do not have children.
	if leftIdx >= h.Tail { return }

	// If current node only have left-child
	if rightIdx >= h.Tail && h.Tree[leftIdx] > h.Tree[cur] { h.swap(leftIdx, cur); return }

	// Get index that has biggest value.
	minIdx := h.getMinIdx(cur, leftIdx, rightIdx)

	// If maxIdx is not current node's index
	//     first, swap current node's value and value of maxIdx.
	//     second, heapify recursively from node of maxIdx to bottom.
	if minIdx != cur {
		h.swap(minIdx, cur)
		h.heapifyTopDown(minIdx)
	}
}