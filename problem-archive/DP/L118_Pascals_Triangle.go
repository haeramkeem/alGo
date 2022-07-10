// Problem Source: https://leetcode.com/problems/pascals-triangle/
package main

import (
    "fmt"
    "reflect"
    "os"
)

func generate(numRows int) [][]int {
    outp := make([][]int, numRows)
    outp[0] = []int{1}

    for i := 1; i < numRows; i++ {
        level := make([]int, i + 1)
        level[0] = 1
        level[i] = 1

        for j := 1; j < i; j++ {
            level[j] = outp[i - 1][j - 1] + outp[i - 1][j]
        }

        outp[i] = level
    }

    return outp
}

type Testing struct {
    numRows int
    outp    [][]int
}

func main() {
    testCases := []Testing{
        { numRows: 5, outp: [][]int{ []int{1}, []int{1,1}, []int{1,2,1}, []int{1,3,3,1}, []int{1,4,6,4,1} } },
        { numRows: 1, outp: [][]int{ []int{1} } },
    }

    for _, t := range testCases {
        if outp := generate(t.numRows); !reflect.DeepEqual(outp, t.outp) {
            fmt.Println("FAIL")
            fmt.Println("Want: ", t.outp)
            fmt.Println("Got: ", outp)
            os.Exit(1)
        }
    }

    fmt.Println("ok")
}
