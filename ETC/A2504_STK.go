/**
 * https://www.acmicpc.net/problem/2504
 *
 * Stack
 */

package main

import "fmt"

type Bracket struct {
	btype	int
	index	int
}

func main() {
	var input string
	fmt.Scan(&input)

	bstack := make([]Bracket, 0)
	rstack := make([]int, 1)

	for i, v := range input {
		if v == '(' || v == '[' {
			var btype int
			if v == '(' { btype = 2 }
			if v == '[' { btype = 3 }
			bstack = append(bstack, Bracket{ btype: btype, index: i })
			rstack = append(rstack, 0)
		} else {
			if len(bstack) < 1 { fmt.Println(0); return }
			btop := bstack[len(bstack) - 1]
			if (v == ')' && btop.btype == 3) || (v == ']' && btop.btype == 2) { fmt.Println(0); return }
			bstack = bstack[:len(bstack) - 1]
			rtop := rstack[len(rstack) - 1]
			rstack = rstack[:len(rstack) - 1]
			if rtop == 0 { rtop++ }
			rstack[len(rstack) - 1] += rtop * btop.btype
		}
	}
	fmt.Println(rstack[0])
}