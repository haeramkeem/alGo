// Problem Source: https://leetcode.com/problems/fibonacci-number/
package main

import (
    "fmt"
    "os"
)

func fib(n int) int {
    if n < 1 { return 0 }
    cache := make([]int, n + 1)
    cache[0], cache[1] = 0, 1
    for i := 2; i <= n; i++ { cache[i] = cache[i - 1] + cache[i - 2] }
    return cache[n]
}

type Testing struct {
    n, expect   int
}

func main() {
    testCases := []*Testing{
        { n: 2, expect: 1 },
        { n: 3, expect: 2 },
        { n: 4, expect: 3 },
    }

    for _, t := range testCases {
        if outp := fib(t.n); outp != t.expect {
            fmt.Println("FAIL")
            fmt.Println("Want: ", t.expect)
            fmt.Println("Got: ", outp)
            os.Exit(1)
        }
    }

    fmt.Println("ok")
}
