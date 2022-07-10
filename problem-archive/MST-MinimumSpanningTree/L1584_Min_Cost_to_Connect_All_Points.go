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

// PriorityQueue Item
type Edge struct {
    beg, end        int // Arbitrary value
    priority, index int // Obey to the container/heap interface
}

func NewEdge(points *[][]int, b, e int) *Edge {
    x := math.Abs(float64((*points)[b][0] - (*points)[e][0]))
    y := math.Abs(float64((*points)[b][1] - (*points)[e][1]))

    return &Edge{
        beg: b,
        end: e,
        priority: int(x + y),
    }
}

// PriorityQueue
// Ref: https://pkg.go.dev/container/heap
// In most cases, the need for modification of the code below is very low
// - You just need to modify Less() and PriorityQueue type to adopt it to other code
// - Push() and Pop() function can be used with no-modifications;
// - cuz container/heap pkg forces you to use 'any' type
type PriorityQueue []*Edge
type any = interface{} // To support older version
func (pq PriorityQueue) Len() int           { return len(pq) }
func (pq PriorityQueue) Empty() bool        { return len(pq) == 0 }
func (pq PriorityQueue) Less(i, j int) bool { return pq[i].priority < pq[j].priority }
func (pq PriorityQueue) Swap(i, j int)      {
    pq[i], pq[j] = pq[j], pq[i]
    pq[i].index = i
    pq[j].index = j
}

func (pq *PriorityQueue) Push(x any) {
	n := len(*pq)
	item := x.(*Edge)
	item.index = n
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() any {
	old := *pq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil  // avoid memory leak
	item.index = -1 // for safety
	*pq = old[0 : n-1]
	return item
}

func minCostConnectPoints(points [][]int) int {
    if len(points) < 2 { return 0 }
    pq := make(PriorityQueue, 0)
    numPoints := len(points)

    visited := make([]bool, numPoints)
    visited[0] = true

    minDistance := 0

    for it := 0; ; {
        visited[it] = true

        for i := 0; i < numPoints; i++ {
            if i == it       { continue }
            if visited[i]    { continue }
            heap.Push(&pq, NewEdge(&points, it, i))
        }

        lowestCostEdge := heap.Pop(&pq).(*Edge)
        for visited[lowestCostEdge.end] && !pq.Empty() {
            lowestCostEdge = heap.Pop(&pq).(*Edge)
        }

        if !visited[lowestCostEdge.end] {
            it = lowestCostEdge.end
            minDistance += lowestCostEdge.priority
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
        {
            points: [][]int{ []int{0, 0} },
            outp: 0,
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


