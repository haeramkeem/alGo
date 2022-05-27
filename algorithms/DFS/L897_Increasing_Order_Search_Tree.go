package main

import (
	"fmt"
	"os"
)

type TreeNode struct {
     Val int
     Left *TreeNode
     Right *TreeNode
}

func increasingBST(root *TreeNode) *TreeNode {
    // Ignore empty tree
    if root == nil { return nil }

    var newTreeRoot, it *TreeNode

    // Recursion lambda
    var inOrder func(curr *TreeNode)
    inOrder = func(curr *TreeNode) {
        // Left recursion
        if curr.Left != nil { inOrder(curr.Left) }

        // Initial Node
        if it == nil {
            newTreeRoot = &TreeNode{ Val: curr.Val }
            it = newTreeRoot

        // Add Right Node
        } else {
            it.Right = &TreeNode{ Val: curr.Val }
            it = it.Right
        }

        // Right recursion
        if curr.Right != nil { inOrder(curr.Right) }
    }

    inOrder(root)
    return newTreeRoot
}

func main() {
    testCase := &TreeNode{
        Val: 5,
        Left: &TreeNode{
            Val: 1,
            Left: nil,
            Right: nil,
        },
        Right: &TreeNode{
            Val: 7,
            Left: nil,
            Right: nil,
        },
    }

    outp := &TreeNode{
        Val: 1,
        Left: nil,
        Right: &TreeNode{
            Val: 5,
            Left: nil,
            Right: &TreeNode{
                Val: 7,
                Left: nil,
                Right: nil,
            },
        },
    }

    res := increasingBST(testCase)
    if res.Val != outp.Val ||
        res.Right.Val != outp.Right.Val ||
        res.Right.Right.Val != outp.Right.Right.Val {
        fmt.Println("FAIL")
        os.Exit(1)
    }

    fmt.Println("ok")
}
