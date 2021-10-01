package heap

type MinInt struct{
	Tail	int
	Tree	[]int
}

type MaxInt struct{
	Tail	int
	Tree	[]int
}

type Heap interface {
	Push(el int) error
	Pop() (int, error)
	GetTreeSlice() []int
	sortAfterPush(cur int)
	sortAfterPop(cur int)
}