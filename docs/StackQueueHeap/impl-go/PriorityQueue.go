package main

import "fmt"

//////////////////////////////////
// PriorityQueue Implementation //
//////////////////////////////////

type PriorityQueue struct {
    Tree                    []interface{}
    Tail                    int
    IsFirstParamGT func(high, low interface{}) bool
}

func NewPriorityQueue(comp func(high, low interface{}) bool) *PriorityQueue {
     return &PriorityQueue{
         Tree: make([]interface{}, 0),
         Tail: 0,
         IsFirstParamGT: comp,
     }
}

func (this *PriorityQueue) Push(el interface{}) {
    // Push left
    if this.Tail >= len(this.Tree) {
        this.Tree = append(this.Tree, el)
    } else {
        this.Tree[this.Tail] = el
    }
    this.Tail++

    // Heapify by bottom-up recursion
    var heapify func(curr int)
    heapify = func(curr int) {
        parent := (curr - 1) / 2
        if curr > 0 && this.IsFirstParamGT(this.Tree[curr], this.Tree[parent]) {
            // Swap
            this.Tree[curr], this.Tree[parent] = this.Tree[parent], this.Tree[curr]
            heapify(parent)
        }
    }

    // Heapify
    heapify(this.Tail - 1)
}

func (this *PriorityQueue) Pop() interface{} {
    // Get minimum
    popped := this.Tree[0]

    // Heapify by top-down recursion
    var heapify func(curr int)
    heapify = func(curr int) {
        if leftChild := curr * 2 + 1;
        leftChild < this.Tail &&
        this.IsFirstParamGT(this.Tree[leftChild], this.Tree[curr]) {
            // Swap
            this.Tree[curr], this.Tree[leftChild] = this.Tree[leftChild], this.Tree[curr]
            heapify(leftChild)
        }

        if rightChild := curr * 2 + 2;
        rightChild < this.Tail &&
        this.IsFirstParamGT(this.Tree[rightChild], this.Tree[curr]) {
            this.Tree[curr], this.Tree[rightChild] = this.Tree[rightChild], this.Tree[curr]
            heapify(rightChild)
        }
    }

    // Heapify
    this.Tail--
    this.Tree[0] = this.Tree[this.Tail]
    heapify(0)

    return popped
}

func (this *PriorityQueue) Empty() bool {
    return this.Tail == 0
}

/////////////////////
//  Demonstration  //
/////////////////////
func main() {
    fmt.Println("Max heap demo")
    maxHeap := NewPriorityQueue(func(high, low interface{}) bool { return high.(int) > low.(int) })

    maxHeap.Push(5)
    maxHeap.Push(2)
    maxHeap.Push(3)
    maxHeap.Push(1)
    maxHeap.Push(4)

    fmt.Println(maxHeap.Pop())
    fmt.Println(maxHeap.Pop())
    fmt.Println(maxHeap.Pop())
    fmt.Println(maxHeap.Pop())
    fmt.Println(maxHeap.Pop())

    fmt.Println("Min heap demo")
    minHeap := NewPriorityQueue(func(high, low interface{}) bool { return high.(int) < low.(int) })

    minHeap.Push(5)
    minHeap.Push(2)
    minHeap.Push(3)
    minHeap.Push(1)
    minHeap.Push(4)

    fmt.Println(minHeap.Pop())
    fmt.Println(minHeap.Pop())
    fmt.Println(minHeap.Pop())
    fmt.Println(minHeap.Pop())
    fmt.Println(minHeap.Pop())
}
