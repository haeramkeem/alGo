package main

import (
    "fmt"
)

func solution(p []int) []int {
    
    ans := make([]int, len(p))

    for i := 0; i < len(p); i++ {

        // Find minimum
        j := i
        for it := i; it < len(p); it++ {
            if p[j] > p[it] { j = it }
        }

        if j != i {
            p[i], p[j] = p[j], p[i]
            ans[i]++; ans[j]++
        }
    }
    return ans
}

func main() {
    fmt.Println(solution([]int{2,5,3,1,4}))
}
