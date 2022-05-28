// Problem Source: https://leetcode.com/problems/n-th-tribonacci-number/
package main

import (
    "fmt"
    "os"
)

func tribonacci(n int) int {
    cache := make([]int, 3, n + 3)
    cache[0], cache[1], cache[2] = 0, 1, 1
    for i := 3; i <= n; i++ {
        cache = append(cache, cache[i - 1] + cache[i - 2] + cache[i - 3])
    }
    return cache[n]
}

type Testing struct {
    n, expect   int
}

func main() {
    testCases := []*Testing{
        { n: 4, expect: 4 },
        { n: 25, expect: 1389537 },
    }

    for _, t := range testCases {
        if outp := tribonacci(t.n); outp != t.expect {
            fmt.Println("FAIL")
            fmt.Println("Want: ", t.expect)
            fmt.Println("Got: ", outp)
            os.Exit(1)
        }
    }

    fmt.Println("ok")
}
