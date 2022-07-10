// Problem Source: https://leetcode.com/problems/missing-number/
package main

import (
	"fmt"
	"os"
)

func missingNumber(nums []int) int {
    ret := 0
    for i := 0; i <= len(nums); i++ { ret += i }
    for _, num := range nums { ret -= num }
    return ret
}

type Testing struct {
    nums    []int
    expect  int
}

func main() {
    testCases := []*Testing{
        { nums: []int{3, 0, 1}, expect: 2 },
        { nums: []int{0, 1}, expect: 2 },
        { nums: []int{9, 6, 4, 2, 3, 5, 7, 0, 1}, expect: 8 },
    }

    for _, t := range testCases {
        if outp := missingNumber(t.nums); outp != t.expect {
            fmt.Println("FAIL")
            fmt.Println("Want: ", t.expect)
            fmt.Println("Got:", outp)
            os.Exit(1)
        }
    }

    fmt.Println("ok")
}
