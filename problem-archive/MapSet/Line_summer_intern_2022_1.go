package main

import (
    "fmt"
    "strings"
    "sort"
)

type empty struct{}

func solution(logs []string) []string {
    // Get unique logs
    uniqueLogs := make(map[string]empty)
    for _, log := range logs {
        uniqueLogs[log] = empty{}
    }

    // For all unique logs
    probCnt := make(map[string]int)
    users   := make(map[string]empty)
    for log := range uniqueLogs {
        // Parse
        nameProb := strings.Split(log, " ")

        // Init element
        if _, prs := probCnt[nameProb[1]]; !prs {
            probCnt[nameProb[1]] = 0
        }

        // Increase ProbCnt
        probCnt[nameProb[1]]++

        // Register users
        users[nameProb[0]] = empty{}
    }

    threshold := float32(len(users)) / 2
    ret := make([]string, 0, len(uniqueLogs))
    for prob, cnt := range probCnt {
        if float32(cnt) >= threshold {
            ret = append(ret, prob)
        }
    }

    sort.Strings(ret)
    return ret
}

func main() {
    inp := []string{"morgan sort", "felix sort", "morgan sqrt", "morgan sqrt", "rohan reverse", "rohan reverse"}

    fmt.Println(solution(inp))
}
