package main

import (
    "fmt"
    "os"
)

func solution(n int, times []int) int {
    cache := make([]int, n + 1)

    for i := 2; i <= n; i++ {
        min := 2147483647
        for num, time := range times {
            estTime := 0
            if i - 2 * num - 2 >= 0 {
                estTime = cache[i - num - 1] + time
            }

            if 0 < estTime && estTime < min { min = estTime }
        }
        cache[i] = min
    }

    return cache[n]
}

type Testing struct {
    n, expect   int
    times       []int
}

func main() {
    testCases := []*Testing{
        { n: 4, times: []int{2, 3}, expect: 5 },
        { n: 5, times: []int{2, 4, 5}, expect: 8 },
        { n: 6, times: []int{1, 2, 3}, expect: 5 },
    }

    for _, t := range testCases {
        if outp := solution(t.n, t.times); outp != t.expect {
            fmt.Println("FAIL")
            fmt.Println("Want: ", t.expect)
            fmt.Println("Got: ", outp)
            os.Exit(1)
        }
    }

    fmt.Println("ok")
}
