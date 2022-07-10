package heap

func GetParent(childIdx int) int {
	return (childIdx - 1) / 2
}

func GetChildren(parentIdx int) (/* left */int, /* right */int) {
	return parentIdx * 2 + 1, parentIdx * 2 + 2
}

func GetSibling(childIdx int) int {
	left, right := GetChildren(GetParent(childIdx))
	if left != childIdx { return left }
	return right
}