// Problem Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
package main

import (
    "fmt"
    "os"
    "math"
)

func maxProfit(prices []int) int {
    min := prices[0]
    profit := 0

    for i := 1; i < len(prices); i++ {
        if min > prices[i] {
            min = prices[i]
        } else {
            profit = int(math.Max(float64(profit), float64(prices[i] - min)))
        }
    }

    return profit
}

type Testing struct {
    prices  []int
    outp    int
}

func main() {
    testCases := []Testing{
        { prices: []int{ 7,1,5,3,6,4 }, outp: 5 },
        { prices: []int{ 7,6,4,3,1 }, outp: 0 },
    }

    for _, t := range testCases {
        if outp := maxProfit(t.prices); outp != t.outp {
            fmt.Println("FAIL")
            fmt.Println("Want: ", t.outp)
            fmt.Println("Got: ", outp)
            os.Exit(1)
        }
    }

    fmt.Println("ok")
}
