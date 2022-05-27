// Problem Source: https://leetcode.com/problems/pascals-triangle-ii/
package main

import (
    "fmt"
    "reflect"
    "os"
)

func getRow(rowIndex int) []int {
    cache := []int{1}

    for i := 1; i <= rowIndex; i++ {
        level := make([]int, i + 1)
        level[0] = 1
        level[i] = 1

        for j := 1; j < i; j++ {
            level[j] = cache[j - 1] + cache[j]
        }

        cache = level
    }

    return cache
}

type Testing struct {
    rowIndex    int
    outp        []int
}

func main() {
    testCases := []Testing{
        { rowIndex: 3, outp: []int{1,3,3,1} },
        { rowIndex: 0, outp: []int{1} },
        { rowIndex: 1, outp: []int{1,1} },
        { rowIndex: 4, outp: []int{1,4,6,4,1} },
    }

    for _, t := range testCases {
        if outp := getRow(t.rowIndex); !reflect.DeepEqual(outp, t.outp) {
            fmt.Println("FAIL")
            fmt.Println("Want: ", t.outp)
            fmt.Println("Got: ", outp)
            os.Exit(1)
        }
    }

    fmt.Println("ok")
}
