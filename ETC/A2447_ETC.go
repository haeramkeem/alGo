/**
 * https://www.acmicpc.net/problem/2447
 *
 * ETC(Unknown Algorithm)
 */

package main

import (
	"fmt"
)

func triple(sub []string) []string {
	mid := make([]string, 0)
	for l, subLine := range sub {
		for i := 0; i < 2; i++ {
			sub[l] += subLine
		}
		mid = append(mid, subLine)
		for j := 0; j < len(subLine); j++ {
			mid[l] += " "
		}
		mid[l] += subLine
	}

	return append(append(sub, mid...), sub...)
}

func main() {
	var input int
	fmt.Scan(&input)

	result := []string{"***", "* *", "***"}
	for i:= input/3; i >= 3; i = i / 3 {
		result = triple(result)
	}
	for _, line := range result {
		fmt.Println(line)
	}
}