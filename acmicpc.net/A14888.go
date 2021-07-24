package main

import (
	"fmt"
)

type Node struct {
	acc		int
	index	int
	remain	[]int
}

func Solve(n int, a []int, ops []int) (int, int) {
	min := 2147483647
	max := -2147483648

	queue := make([]Node, 0)
	queue = append(queue, Node{
		acc: a[0],
		index: 1,
		remain: ops,
	})

	for len(queue) != 0 {
		head := queue[0]
		queue = queue[1:]
		if head.index == n {
			if head.acc > max { max = head.acc }
			if head.acc < min { min = head.acc }
		}
		for idx, val := range head.remain {
			if val > 0 {
				newAcc := head.acc
				switch idx {
					case 0 : newAcc += a[head.index]; break
					case 1 : newAcc -= a[head.index]; break
					case 2 : newAcc *= a[head.index]; break
					case 3 : newAcc /= a[head.index]; break
				}

				newRemain := make([]int, 4)
				copy(newRemain, head.remain)
				newRemain[idx]--

				queue = append(queue, Node{
					index: head.index + 1,
					acc: newAcc,
					remain: newRemain,
				})
			}
		}
	}
	return min, max
}

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}

	op := make([]int, 4)
	for i := range op {
		fmt.Scan(&op[i])
	}

	min, max := Solve(n, a, op)
	fmt.Printf("%d\n%d\n", max, min)
}