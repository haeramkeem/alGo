/**
 * https://www.acmicpc.net/problem/1806
 *
 * Two Pointer
 */

package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var n, s, l, r, min, acc uint32
	stdin := bufio.NewReader(os.Stdin)
	fmt.Fscan(stdin, &n, &s)
	input, free := make([]uint32, n), false
	for i := range input {
		fmt.Fscan(stdin, &input[i])
		if input[i] >= s { free = true }
	}
	if free { fmt.Println(1); return }
	min--; l, r, acc = 0, 1, input[0]
	for r <= n && l < r  {
		if acc < s {
			if r < n { acc += input[r] }
			r++
		} else {
			if min > r - l - 1 { min = r - l - 1 }
			acc -= input[l]; l++
		}
	}
	fmt.Println(min + 1)
}