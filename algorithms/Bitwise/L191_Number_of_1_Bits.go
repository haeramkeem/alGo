// Problem Source: https://leetcode.com/problems/number-of-1-bits/
package main

import (
    "fmt"
    "os"
)

func hammingWeight(num uint32) int {
    cnt := 0
    for i := 0; i < 32; i++ {
        cnt += int((num >> i) & 1)
    }

    return cnt
}

type Testing struct {
    num     uint32
    outp    int
}

func main() {
    testCase := []Testing{
        { num: 11, outp: 3 },
        { num: 128, outp: 1 },
    }

    for _, t := range testCase {
        outp := hammingWeight(t.num)
        if outp != t.outp {
            fmt.Println("FAIL")
            fmt.Printf("Want %d\nGot %d\n", t.outp, outp)
            os.Exit(1)
        }
    }

    fmt.Println("ok")
}
