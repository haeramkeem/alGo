package main

import (
    "fmt"
)

var vipTable = [5][3]bool{
    [3]bool{ false,  true,   true,  },
    [3]bool{ false,  false,  true,  },
    [3]bool{ false,  false,  false, },
    [3]bool{ false,  false,  false, },
    [3]bool{ false,  false,  false, },
}

func isVip(period, yearlyPay int) bool {
    col := 0
    if period >= 24 { col++ } // 1
    if period >= 60 { col++ } // 2

    row := 4
    if yearlyPay >= 360000 { row-- } // 3
    if yearlyPay >= 480000 { row-- } // 2
    if yearlyPay >= 600000 { row-- } // 1
    if yearlyPay >= 900000 { row-- } // 0

    return vipTable[row][col]
}

func solution(periods []int, payments [][]int, estimates []int) []int {
    ans := make([]int, 2)

    for i, period := range periods {

        yearlyPay := 0
        for _, pay := range payments[i] { yearlyPay += pay }

        curr := isVip(period, yearlyPay)
        next := isVip(period + 1, yearlyPay - payments[i][0] + estimates[i])

        if !curr && next { ans[0]++ }
        if curr && !next { ans[1]++ }
    }

    return ans
}

func main() {
    fmt.Println("no test case")
}
