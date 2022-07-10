// Problem Source: https://leetcode.com/problems/is-subsequence/
package main

import (
    "fmt"
    "os"
)

func isSubsequence(s string, t string) bool {
    sIndex := 0
    for _, rn := range t {
        if sIndex < len(s) && rn == rune(s[sIndex]) {
            sIndex++
        }
    }

    return sIndex == len(s)
}

type Testing struct {
    s       string
    t       string
    outp    bool
}

func main() {
    testCases := []Testing{
        { s: "abc", t: "ahbgdc", outp: true },
        { s: "axc", t: "ahbgdc", outp: false },
    }

    for _, t := range testCases {
        if outp := isSubsequence(t.s, t.t); outp != t.outp {
            fmt.Println("FAIL")
            fmt.Println("Want: ", t.outp)
            fmt.Println("Got: ", outp)
            os.Exit(1)
        }
    }

    fmt.Println("ok")
}
