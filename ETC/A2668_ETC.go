/**
 * https://www.acmicpc.net/problem/2668
 *
 * ETC(Unknown Algorithm)
 */

package main

import (
	"fmt"
	"sort"
)

func main() {
	var size int
	fmt.Scan(&size)

	input := make(map[int]int)
	output := make([]int, 0)
	var temp int
	for i := 0; i < size; i++ {
		if fmt.Scan(&temp); temp == i + 1 {
			output = append(output, temp)
		} else {
			input[i + 1] = temp
		}
	}

	for start := range input {
		ptr := start
		visited := make(map[int]int)
		for {
			if next, exist := input[ptr]; exist {
				if next == start {
					output = append(output, start)
					delete(input, start)
					for key := range visited {
						output = append(output, key)
						delete(input, key)
					}
					break
				} else if _, exist = visited[next]; exist {
					break
				} else {
					visited[next] = 0
					ptr = next
				}
			} else {
				break
			}
		}
	}

	sort.Ints(output)
	fmt.Println(len(output))
	for _, item := range output {
		fmt.Println(item)
	}
}