/**
 * https://www.acmicpc.net/problem/1700
 *
 * OPT(Memory Replacement Policy of OS)
 */

package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	stdin := bufio.NewReader(os.Stdin)
	var n, k int
	fmt.Fscan(stdin, &n, &k)
	input := make([]int, k)
	for i := range input {
		fmt.Fscan(stdin, &input[i])
	}

	if n >= k { fmt.Println(0); return }

	output := 0
	con := map[int]struct{}{}
	for i := 0; i < k; i++ {
		if _, prs := con[input[i]]; !prs {
			if len(con) < n {
				con[input[i]] = struct{}{}
			} else {
				max := 0
				idx := 0
				for key := range con {
					tempIdx := k
					for j := i + 1; j < k; j++ {
						if key == input[j] {
							tempIdx = j
							break
						}
					}
					if tempIdx > idx {
						idx = tempIdx
						max = key
					}
				}
				delete(con, max)
				con[input[i]] = struct{}{}
				output++
			}
		}
	}
	fmt.Println(output)
}