package heap

import "errors"

/* ----- PUBLIC ----- */
func NewMinInt(size int) *MinInt {
	return &MinInt{0, make([]int, size)}
}

func (h *MinInt) Push(el int) {
	h.Tree[h.Tail] = el
	h.Tail++
	if h.Tail < 2 {
		h.sortAfterPush(h.Tail)
	}
}

func (h *MinInt) Pop() (int, error) {
	if h.Tail == 0 {
		return 0, errors.New("heap: empty")
	}
	target := h.Tree[0]
	h.Tree[0] = h.Tree[h.Tail - 1]
	h.Tail--
	h.sortAfterPop(1)
	return target, nil
}

/* ----- PRIVATE ----- */
func (h *MinInt) sortAfterPush(cur int) {
	if cur != 1 && h.Tree[cur - 1] < h.Tree[cur / 2 - 1] {
		h.Tree[cur - 1], h.Tree[cur / 2 - 1] = h.Tree[cur / 2 - 1], h.Tree[cur - 1]
		h.sortAfterPush(cur / 2)
	}
}

func (h *MinInt) sortAfterPop(cur int) {
	if cur * 2 - 1 >= h.Tail { return }
	if cur * 2 == h.Tail {
		if h.Tree[cur - 1] > h.Tree[cur * 2 - 1] {
			h.Tree[cur - 1], h.Tree[cur * 2 - 1] = h.Tree[cur * 2 - 1], h.Tree[cur - 1]
		}
		return
	}
	if h.Tree[cur * 2 - 1] < h.Tree[cur - 1] && h.Tree[cur * 2 - 1] < h.Tree[cur * 2] {
		h.Tree[cur * 2 - 1], h.Tree[cur - 1] = h.Tree[cur - 1], h.Tree[cur * 2 - 1]
		h.sortAfterPop(cur * 2)
		return
	} else if h.Tree[cur * 2] < h.Tree[cur - 1] && h.Tree[cur * 2] < h.Tree[cur * 2 - 1] {
		h.Tree[cur * 2], h.Tree[cur - 1] = h.Tree[cur - 1], h.Tree[cur * 2]
		h.sortAfterPop(cur * 2 + 1)
		return
	}
}