/**
 * https://www.acmicpc.net/problem/1074
 *
 * Bit Operation
 */

package main

import "fmt"

func main() {
	var n, r, c, racc, cacc uint32
	fmt.Scan(&n, &r, &c)
	for i := uint32(0); r > 0 || c > 0; i++{
		racc += (r % 2) << (2 * i)
		cacc += (c % 2) << (2 * i)
		r >>= 1; c >>= 1
	}

	fmt.Println(2 * racc + cacc)
}