/**
 * https://www.acmicpc.net/problem/13549
 *
 * BFS + Priority Queue
 */

package main

import (
	"fmt"
)

func main() {
	var n, k uint32
	fmt.Scan(&n, &k)
	mins := make([]uint32, 100001)
	for i := range mins { mins[i]-- }
	deque := []uint32{ n }
	mins[n] = 0
	for len(deque) != 0 {
		cur := deque[0]
		del := true
		if cur <= 50000 && mins[cur * 2] + 1 == 0 {
			deque[0] = cur * 2
			del = false
			mins[cur * 2] = mins[cur]
		}
		if cur < 100000 && mins[cur + 1] + 1 == 0 {
			deque = append(deque, cur + 1)
			mins[cur + 1] = mins[cur] + 1
		}
		if cur > 0 && mins[cur - 1] + 1 == 0 {
			deque = append(deque, cur - 1)
			mins[cur - 1] = mins[cur] + 1
		}
		if del { deque = deque[1:] }
	}
	fmt.Println(mins[k])
}