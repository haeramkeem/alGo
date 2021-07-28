/**
 * https://www.acmicpc.net/problem/1062
 *
 * DFS
 */

package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	visited	[26]bool
	input	[]string
	k		int
	n		int
	max		int
)

func visit(node int, length int) {
	if length == k {
		cover := 0
		for _, word := range input {
			match := true
			for _, alpha := range word {
				if !visited[alpha - 'a'] {
					match = false
				}
			}
			if match { cover++ }
		}
		if cover > max { max = cover }
	} else {
		for i := node + 1; i < 26; i++ {
			if !visited[i] {
				visited[i] = true
				visit(i, length + 1)
				visited[i] = false
			}
		}
	}
}

func main() {
	stdin := bufio.NewReader(os.Stdin)
	fmt.Fscan(stdin, &n, &k)
	input = make([]string, n)
	for i := range input {
		var temp string
		fmt.Fscan(stdin, &temp)
		input[i] = temp[4:len(temp) - 4]
	}
	if k < 5 { fmt.Println(0); return }
	if k == 26 { fmt.Println(n); return }

	visited['a' - 'a'] = true
	visited['c' - 'a'] = true
	visited['t' - 'a'] = true
	visited['i' - 'a'] = true
	visited['n' - 'a'] = true

	k -= 5
	visit(-1, 0)
	fmt.Println(max)
}
