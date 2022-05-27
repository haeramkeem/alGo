// Problem Source: https://leetcode.com/problems/counting-bits/
package main

import (
    "fmt"
    "os"
    "reflect"
)

const MAX_BITS = 17

func countBits(n int) []int {
    outp := make([]int, n + 1)

    for i := 0; i <= n; i++ {
        for j := 0; j < MAX_BITS; j++ {
            outp[i] += int((i >> j) & 1)
        }
    }

    return outp
}

type Testing struct {
    n       int
    outp    []int
}

func main() {
    testCases := []Testing{
        { n: 2, outp: []int{0, 1, 1} },
        { n: 5, outp: []int{0, 1, 1, 2, 1, 2} },
    }

    for _, t := range testCases {
        if outp := countBits(t.n); !reflect.DeepEqual(outp, t.outp) {
            fmt.Println("FAIL")
            fmt.Println("Want: ", t.outp)
            fmt.Println("Got: ", outp)
            os.Exit(1)
        }
    }

    fmt.Println("ok")
}
