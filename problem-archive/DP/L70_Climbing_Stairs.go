package main

import (
    "fmt"
    "os"
)

func climbStairs(n int) int {
    cache := make([]int, n + 1)
    cache[0] = 1
    cache[1] = 1
    for i := 2; i <= n; i++ {
        cache[i] = cache[i - 1] + cache[i - 2]
    }
    return cache[n]
}

type Testing struct {
    num     int
    outp    int
}

func main() {
    testCases := []Testing{
        { num: 2, outp: 2 },
        { num: 3, outp: 3 },
    }

    for _, t := range testCases {
        if outp := climbStairs(t.num); outp != t.outp {
            fmt.Println("FAIL")
            fmt.Printf("Want %d\nGot %d\n", t.outp, outp)
            os.Exit(1)
        }
    }

    fmt.Println("ok")
}
