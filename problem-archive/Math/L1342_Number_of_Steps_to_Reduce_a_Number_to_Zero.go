// Problem Source: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
package main

import (
    "fmt"
    "os"
)

func numberOfSteps(num int) int {
    var cnt int
    for cnt = 0; num != 0; cnt++ {
        if num % 2 == 0 {
            num /= 2
        } else {
            num--
        }
    }
    return cnt
}

type Testing struct {
    num     int
    outp    int
}

func main() {
    testCase := []Testing{
        { num: 14, outp: 6 },
        { num: 8, outp: 4 },
        { num: 123, outp: 12 },
    }

    for _, t := range testCase {
        outp := numberOfSteps(t.num)
        if outp != t.outp {
            fmt.Println("FAIL")
            fmt.Printf("Want %d\nGot %d\n", t.outp, outp)
            os.Exit(1)
        }
    }

    fmt.Println("ok")
}
