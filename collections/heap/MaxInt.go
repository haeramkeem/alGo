package heap

import "errors"

/* ----- PUBLIC ----- */
func NewMaxInt(size int) *MaxInt {
	return &MaxInt{0, make([]int, size)}
}

func (h *MaxInt) Push(el int) error {
	if h.Tail >= len(h.Tree) { return errors.New("heap: full") }
	h.Tree[h.Tail] = el
	if h.Tail > 0 { h.sortAfterPush(h.Tail) }
	h.Tail++
	return nil
}

func (h *MaxInt) Pop() (int, error) {
	if h.Tail == 0 { return 0, errors.New("heap: empty") }
	target := h.Tree[0]
	h.Tree[0] = h.Tree[h.Tail - 1]
	h.Tail--
	h.sortAfterPop(0)
	return target, nil
}

/* ----- PRIVATE ----- */
func (h *MaxInt) sortAfterPush(cur int) {
	if cur > 0 && h.Tree[cur] > h.Tree[(cur - 1) / 2] {
		h.Tree[cur], h.Tree[(cur - 1) / 2] = h.Tree[(cur - 1) / 2], h.Tree[cur]
		h.sortAfterPush((cur - 1) / 2)
	}
}

func (h *MaxInt) sortAfterPop(cur int) {
	if cur * 2 + 1 < h.Tail && h.Tree[cur * 2 + 1] > h.Tree[cur] {
		h.Tree[cur * 2 + 1], h.Tree[cur] = h.Tree[cur], h.Tree[cur * 2 + 1]
		h.sortAfterPop(cur * 2 + 1)
	}
	if cur * 2 + 2 < h.Tail && h.Tree[cur * 2 + 2] > h.Tree[cur] {
		h.Tree[cur * 2 + 2], h.Tree[cur] = h.Tree[cur], h.Tree[cur * 2 + 2]
		h.sortAfterPop(cur * 2 + 2)
	}
}