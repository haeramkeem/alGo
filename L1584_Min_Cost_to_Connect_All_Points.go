package main

import (
    "fmt"
    "os"
    "math"
    "container/heap"
)

//////////////
// Solution //
//////////////
type Edge struct {
    beg, end, cost  int
}

type EdgeHeap []*Edge

func NewEdge(points *[][]int, b, e int) *Edge {
    x := math.Abs(float64((*points)[b][0] - (*points)[e][0]))
    y := math.Abs(float64((*points)[b][1] - (*points)[e][1]))

    return &Edge{
        beg: b,
        end: e,
        cost: int(x + y),
    }
}

func (h EdgeHeap) Len() int { return len(h) }
func (h EdgeHeap) Less(i, j int) bool { return len(h) }
func edgeCompare(h, l interface{}) bool {
    return h.(*Edge).cost < l.(*Edge).cost
}

func minCostConnectPoints(points [][]int) int {
    pq := NewPriorityQueue(edgeCompare)
    numPoints := len(points)

    visited := make([]bool, numPoints)
    visited[0] = true

    minDistance := 0

    for it := 0; ; {
        visited[it] = true

        for i := 0; i < numPoints; i++ {
           if i == it { continue; }
           pq.Push(NewEdge(&points, it, i))
        }

        lowestCostEdge := pq.Pop().(*Edge)
        for visited[lowestCostEdge.end] && !pq.Empty() {
            lowestCostEdge = pq.Pop().(*Edge)
        }

        if !visited[lowestCostEdge.end] {
            it = lowestCostEdge.end
            minDistance += lowestCostEdge.cost
        }

        if pq.Empty() {
            break
        }
    }

    return minDistance
}

// Testing code
type Testing struct {
    points  [][]int
    outp    int
}

func main() {
    testCases := []Testing{
        {
            points: [][]int{ []int{0, 0}, []int{2, 2}, []int{3, 10}, []int{5, 2}, []int{7, 0} },
            outp: 20,
        },
        {
            points: [][]int{ []int{3, 12}, []int{-2, 5}, []int{-4, 1} },
            outp: 18,
        },
    }

    for _, t := range testCases {
        if outp := minCostConnectPoints(t.points); outp != t.outp {
            fmt.Println("FAIL")
            fmt.Println("Want: ", t.outp)
            fmt.Println("Got: ", outp)
            os.Exit(1)
        }
    }

    fmt.Println("ok")
}


