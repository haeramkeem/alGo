package main

import (
	"fmt"
	"os"
	"reflect"
)

type Node struct {
    Val int
    Children []*Node
}

type Wrapper struct {
    node    *Node
    index   int
}

func levelOrder(root *Node) [][]int {
    // Ignore empty
    if root == nil { return [][]int{} }

    // Add root to the queue
    q := []*Wrapper{
        { node: root, index: 0 },
    }

    ret := make([][]int, 0)
    for i := 0; i < len(q); i++ {
        // Make init level element
        if q[i].index == len(ret) { ret = append(ret, make([]int, 0)) }

        // Add head to the queue
        ret[q[i].index] = append(ret[q[i].index], q[i].node.Val)

        // Add children to the queue
        for _, child := range q[i].node.Children {
            q = append(q, &Wrapper{ node: child, index: q[i].index + 1 })
        }
    }

    return ret
}

func main() {
    testCase := &Node{
        Val: 1,
        Children: []*Node{
            {
                Val: 3,
                Children: []*Node{
                    { Val: 5, Children: nil },
                    { Val: 6, Children: nil },
                },
            },
            { Val: 2, Children: nil },
            { Val: 4, Children: nil },
        },
    }

    expected := [][]int{ {1},{3,2,4},{5,6} }

    if outp := levelOrder(testCase); !reflect.DeepEqual(outp, expected) {
        fmt.Println("FAIL")
        fmt.Println("Want: ", expected)
        fmt.Println("Got: ", outp)
        os.Exit(1)
    }

    fmt.Println("ok")
}
